#include "Polyedre.hh"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <numeric> //ceci est pour gcd
//gcd calcule le pgcd
//je l'utilise pour calculer le nombre de tours que je dois faire pour que le cercle roulant fasse un tour complet

//virtuel
Polyedre_virtuel::Polyedre_virtuel() : Figure(), sommets(0) {}
Polyedre_virtuel::Polyedre_virtuel(const Polyedre_virtuel& p) : Figure(p), sommets(p.sommets) {}
Polyedre_virtuel::Polyedre_virtuel(const Point& p, int sommets) : Figure(p), sommets(sommets) {}
Polyedre_virtuel::~Polyedre_virtuel() {}

//regulier
Polyedre_regulier::Polyedre_regulier() : Polyedre_virtuel(), cote(0.0), angle(0.0) {}
Polyedre_regulier::Polyedre_regulier(const Polyedre_regulier& p) : Polyedre_virtuel(p), cote(p.cote), angle(p.angle) {}
Polyedre_regulier::Polyedre_regulier(const Point& p, int sommets, double cote, double angle) : Polyedre_virtuel(p, sommets), cote(cote), angle(angle) {}
Polyedre_regulier::~Polyedre_regulier() {}
//affiche un polygone régulier
void Polyedre_regulier::afficher(Screen& window) {
    sf::ConvexShape polygon;
    polygon.setPointCount(sommets);
    //angle step= angle entre chaque sommet
    double angleStep = 2 * M_PI / sommets;
    for (int i = 0; i < sommets; ++i) {
        double x = getCentre().getX() + cote * cos(i * angleStep + angle);
        double y = getCentre().getY() + cote * sin(i * angleStep + angle);
        //setPoint(i,point) permet de définir le sommet i du polygone
        polygon.setPoint(i, sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
    }
    
    polygon.setFillColor(sf::Color::Transparent);
    polygon.setOutlineColor(sf::Color::White);
    polygon.setOutlineThickness(1);
    window.draw(polygon);
}
//algorithme raycasting 
//src: https://rosettacode.org/wiki/Ray-casting_algorithm
//explication: 
/*
    1. On trace une ligne horizontale vers la droite de chaque point du polygone
    2. On compte le nombre de fois que la ligne traverse les côtés du polygone
    3. Si le nombre de fois est impair, le point est à l'intérieur du polygone
logique: 
    - Si le point est à l'intérieur du polygone, il doit traverser un nombre impair de côtés
    - sinon, il doit traverser un nombre pair de côtés s'il est à l'extérieur
vu que c'est un polygone régulier ici, c'est plus simple de générer les coordonnées des sommets
on peut utiliser alors une boucle simple
*/

bool Polyedre_regulier::contientPoint(const Point& point) const {
    //
    int count = 0;
    double angleStep = 2 * M_PI / sommets; 
    for (int i = 0; i < sommets; ++i) {
        //calcul des coordonnées des sommets du polygone
        double x1 = getCentre().getX() + cote * cos(i * angleStep + angle);
        double y1 = getCentre().getY() + cote * sin(i * angleStep + angle);
        double x2 = getCentre().getX() + cote * cos((i + 1) * angleStep + angle);
        double y2 = getCentre().getY() + cote * sin((i + 1) * angleStep + angle);
        //si la ligne horizontale vers la droite du point traverse le côté du polygone
        //on incrémente le compteur
        //si le point est à l'intérieur du polygone, le compteur sera impair
        if (((y1 > point.getY()) != (y2 > point.getY())) &&
            (point.getX() < (x2 - x1) * (point.getY() - y1) / (y2 - y1) + x1)) {
            count++;
        }
    }
    return count % 2 == 1; //si le nombre de fois est impair, le point est à l'intérieur du polygone
}

//irregulier 
Polyedre_irregulier::Polyedre_irregulier() : Polyedre_virtuel() {}
Polyedre_irregulier::Polyedre_irregulier(const Polyedre_irregulier& p) : Polyedre_virtuel(p), list_sommets(p.list_sommets) {}
Polyedre_irregulier::Polyedre_irregulier(const Point& p, int sommets, std::stack<std::vector<std::pair<double, double> > > list_sommets) : Polyedre_virtuel(p, sommets), list_sommets(list_sommets) {}
Polyedre_irregulier::~Polyedre_irregulier() {}


void Polyedre_irregulier::afficher(Screen& window) {
    if (list_sommets.empty()) return;
    //LineStrip: permet de dessiner des lignes entre les sommets
    sf::VertexArray lines(sf::LineStrip);
    //on parcourt la pile
    std::vector<std::pair<double, double> > temp_stack = list_sommets;
    while (!temp_stack.empty()) {
        std::pair<double, double>  vec = temp_stack.top(); //on récupère le sommet
        temp_stack.pop(); //on le retire de la pile
        for (const auto& pair : vec) {
            //on dessine les lignes entre les sommets
            lines.append(sf::Vertex(sf::Vector2f(static_cast<float>(pair.first), static_cast<float>(pair.second)), sf::Color::White));
        }
    }

    window.draw(lines);
}
//particularité des polygones irrégulier:  ils peuvent être concaves i.e les angles peuvent être > 180°
//du coup les sommets sont pas espacés de manière régulière
//donc on stocke les sommets dans une structure de données un peu plus générale (pile)
bool Polyedre_irregulier::contientPoint(const Point& point) const {
    
    int count = 0;
    std::stack<std::vector<std::pair<double, double> > > temp_stack = list_sommets; //copie de la pile i.E liste des sommets
    std::vector<std::pair<double, double> > vertices; //liste sommets

    while (!temp_stack.empty()) { //tant que la pile n'est pas vide
        std::vector<std::pair<double, double> > vec = temp_stack.top(); //on récupère le sommet
        temp_stack.pop();//on le retire de la pile
        vertices.insert(vertices.end(), vec.begin(), vec.end());//on ajoute le sommet à la liste des sommets
    }
    //on applique l'algorithme raycasting
    for (size_t i = 0; i < vertices.size(); ++i) {
        double x1 = vertices[i].first; //coordonnées du sommet i
        double y1 = vertices[i].second;
        double x2 = vertices[(i + 1) % vertices.size()].first;//coordonnées du sommet suivant
        double y2 = vertices[(i + 1) % vertices.size()].second;

        if (((y1 > point.getY()) != (y2 > point.getY())) &&
            (point.getX() < (x2 - x1) * (point.getY() - y1) / (y2 - y1) + x1)) {
            count++;
        }
    }
    return count % 2 == 1;
}