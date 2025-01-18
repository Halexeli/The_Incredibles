#include "Point.hh"

void Point::afficher() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

bool Point::operator==(const Point& p) {
    return x == p.x && y == p.y;
}