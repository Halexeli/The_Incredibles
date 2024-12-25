#include "Ellipse.hh"
#include <cmath>
#include "SFML/Graphics.hpp"

Ellipse::Ellipse() : Ellipse_virtuelle(), b(0), angle(0) {}

Ellipse::Ellipse(const Ellipse& p) : Ellipse_virtuelle(p), b(p.b), angle(p.angle) {}

Ellipse::Ellipse(const Point& p, const double a, const double b, const double angle)
    : Ellipse_virtuelle(p, a), b(b), angle(angle) {}


// getters et setters
double Ellipse::getB() const {
    return b;}

void Ellipse::setB(double _b) {
    b = _b;}

double Ellipse::getAngle() const {
    return angle;}

void Ellipse::setAngle(double _angle) {
    angle = _angle;} 

// Méthodes :
double Ellipse::aire() const {
    return M_PI * a * b;
}

double Ellipse::perimetre() const {
    double h = pow((a - b), 2) / pow((a + b), 2);
    return M_PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}
// Redimensionne l'ellipse selon les facteurs a et b
void Ellipse::redimensionner(double facteurA, double facteurB) {
    a *= facteurA;
    b *= facteurB;
}
// Fait pivoter l'ellipse de l'angle angleSupplementaire
void Ellipse::pivoter(double angleSupplementaire) {
    angle += angleSupplementaire;
    while (angle >= 360) angle -= 360;
}
// Affiche l'ellipse dans la fenêtre window
void Ellipse::afficher(sf::RenderWindow& window) {
    sf::CircleShape ellipse;
    ellipse.setRadius(static_cast<float>(a));  // Définit le rayon
    ellipse.setScale(1.f, static_cast<float>(b / a)); // Applique une échelle pour simuler une ellipse
    ellipse.setFillColor(sf::Color(0, 0, 255)); // Bleu
    ellipse.setOutlineThickness(1);
    ellipse.setOutlineColor(sf::Color(255, 255, 255)); // Blanc
    ellipse.setPosition(static_cast<float>(getCentre().getX()), static_cast<float>(getCentre().getY()));
    ellipse.setRotation(static_cast<float>(angle));
    window.draw(ellipse);
}
// Affichage des informations de l'ellipse
void Ellipse::afficherInfos() const {
    std::cout << "Ellipse : " << std::endl;
    std::cout << "Centre : (" << getCentre().getX() << ", " << getCentre().getY() << ")" << std::endl;
    std::cout << "Demi-grand axe (a) : " << a << std::endl;
    std::cout << "Demi-petit axe (b) : " << b << std::endl;
    std::cout << "Angle de rotation : " << angle << " degrés" << std::endl;
    std::cout << "Aire : " << aire() << std::endl;
    std::cout << "Périmètre (approximation) : " << perimetre() << std::endl;
}



