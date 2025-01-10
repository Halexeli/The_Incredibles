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
        double x = getCentre()->getX() + cote * cos(i * angleStep + angle);
        double y = getCentre()->getY() + cote * sin(i * angleStep + angle);
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

bool const Polyedre_regulier::contientPoint(const Point& point) {
    //
    int count = 0;
    double angleStep = 2 * M_PI / sommets; 
    for (int i = 0; i < sommets; ++i) {
        //calcul des coordonnées des sommets du polygone
        const Point * centre=getCentre();
        double x1 = centre->getX() + cote * cos(i * angleStep + angle);
        double y1 = centre->getY() + cote * sin(i * angleStep + angle);
        double x2 = centre->getX() + cote * cos((i + 1) * angleStep + angle);
        double y2 = centre->getY() + cote * sin((i + 1) * angleStep + angle);
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
Polyedre_irregulier::Polyedre_irregulier(const Point& p, int sommets, std::vector<Point> list_sommets) : Polyedre_virtuel(p, sommets), list_sommets(list_sommets) {}
Polyedre_irregulier::~Polyedre_irregulier() {}


void Polyedre_irregulier::afficher(Screen& window) {
    const Point * centre=getCentre();
    window.Figure_irregular(centre->getX(),centre->getY(),list_sommets.size(),list_sommets);
}
//particularité des polygones irrégulier:  ils peuvent être concaves i.e les angles peuvent être > 180°
//du coup les sommets sont pas espacés de manière régulière
//donc on stocke les sommets dans une structure de données un peu plus générale (pile)
bool const Polyedre_irregulier::contientPoint(const Point& point) {
    
    int count = 0;
    //on applique l'algorithme raycasting
    std::vector<Point>::iterator temp,it;
    for (it=list_sommets.begin();it!=list_sommets.end();it++) {
        if(it!=list_sommets.begin()){
            float x1=temp->getX();
            float y1=temp->getY();
            float x2=it->getX();
            float y2=it->getY();
            if (((y1 > point.getY()) != (y2 > point.getY())) &&
                (point.getX() < (x2 - x1) * (point.getY() - y1) / (y2 - y1) + x1)) {
                count++;
            }
        }
        temp=it;
    }
    float x1=list_sommets.begin()->getX();
    float y1=list_sommets.begin()->getY();
    float x2=temp->getX();
    float y2=temp->getY();
    if (((y1 > point.getY()) != (y2 > point.getY())) &&
        (point.getX() < (x2 - x1) * (point.getY() - y1) / (y2 - y1) + x1)) {
        count++;
        }
    return count % 2 == 1;
}