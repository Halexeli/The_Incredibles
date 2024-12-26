#include "Cercle.hh"
#include <cmath>
#include <SFML/Graphics.hpp>

// --- Constructeurs ---

Cercle::Cercle() : Ellipse_virtuelle() {}

Cercle::Cercle(const Cercle& c) : Ellipse_virtuelle(c) {}

Cercle::Cercle(const Point& centre, const double rayon) : Ellipse_virtuelle(centre, rayon) {}

// --- Destructeur ---
Cercle::~Cercle() {}

// --- Méthodes spécifiques au cercle ---

double Cercle::diametre() const {
    return 2 * a; // Diamètre = 2 * rayon
}

double Cercle::circonference() const {
    return 2 * M_PI * a; // Circonférence = 2πr
}

bool Cercle::contientPoint(const Point& p) const {
    double dx = p.getX() - centre.getX();
    double dy = p.getY() - centre.getY();
    return (dx * dx + dy * dy) <= (a * a); // Distance au centre <= rayon²
}

// --- Méthode d'affichage ---

void Cercle::afficher(sf::RenderWindow& window) {
    sf::CircleShape circle;
    circle.setRadius(static_cast<float>(a)); // Rayon
    circle.setFillColor(sf::Color(255, 0, 0)); // Rouge
    circle.setOutlineThickness(1);
    circle.setOutlineColor(sf::Color(255, 255, 255)); // Blanc
    circle.setPosition(static_cast<float>(centre.getX() - a), static_cast<float>(centre.getY() - a)); // Centré
    window.draw(circle);
}

// --- Méthode de redimensionnement ---

void Cercle::redimensionner(double facteur) {
    a *= facteur; // Multiplie le rayon par un facteur
}

// --- Méthode d'informations ---

void Cercle::afficherInfos() const {
    std::cout << "Cercle : " << std::endl;
    std::cout << "Centre : (" << centre.getX() << ", " << centre.getY() << ")" << std::endl;
    std::cout << "Rayon : " << a << std::endl;
    std::cout << "Diamètre : " << diametre() << std::endl;
    std::cout << "Circonférence : " << circonference() << std::endl;
}
