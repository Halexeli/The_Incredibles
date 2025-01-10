#include "Cercle.hh"
#include <cmath>

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

bool const Cercle::contientPoint(const Point& p) {
    double dx = p.getX() - centre.getX();
    double dy = p.getY() - centre.getY();
    return (dx * dx + dy * dy) <= (a * a); // Distance au centre <= rayon²
}

// --- Méthode d'affichage ---

void Cercle::afficher(Screen& window) {
    window.circle(centre.getX(), centre.getY(), a); 
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
