#include "Point.hh"

void Point::afficher() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::operator=(const Point& p) { //dans le cas où le point est le mm on fait rien
    if (this != &p) {
        x = p.x;
        y = p.y;
    }
}

bool Point::operator==(const Point& p) {
    return x == p.x && y == p.y;
}