#include "Point.hh"

Point::Point(){
    x=new float(0);
    y=new float(0);
}
Point::Point(float _x, float _y){
    x=new float(_x);
    y=new float(_y);
}
Point::Point(const Point& p){
    x=new float(p.getY());
    y=new float(p.getY());
}
Point::~Point(){
    delete x;
    delete y;
}

void Point::afficher() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
float Point::getX() const {
    return *x;
}

float Point::getY() const {
    return *y;
}

void Point::setX(float _x) {
    *x = _x;
}

void Point::setY(float _y) {
    *y = _y;
}

void Point::operator=(const Point& p) { //dans le cas où le point est le mm on fait rien
    if (this != &p) {
        *x = *p.x;
        *y = *p.y;
    }
}

bool Point::operator==(const Point& p) {
    return *x == *p.x && *y == *p.y;
}