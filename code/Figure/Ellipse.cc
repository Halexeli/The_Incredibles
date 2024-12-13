#include "Ellipse.hh"

Ellipse_virtuelle::Ellipse_virtuelle():Figure(){
    a=0;
}

Ellipse_virtuelle::Ellipse_virtuelle(const Ellipse_virtuelle &p):Figure(p){
    
    a=p.a;

}

Ellipse_virtuelle::Ellipse_virtuelle(const Point& p, const double _a):Figure(p){
    a=_a;
}


Cercle::Cercle():Ellipse_virtuelle(){
}
Cercle::Cercle(const Cercle& c):Ellipse_virtuelle(c){

}
Cercle::Cercle(const Point& p,const double _a):Ellipse_virtuelle(p,_a){

}


void Cercle::afficher(sf::CircleShape  &shape){
    shape.setRadius(this->a);
    shape.setPosition(10,20);
}
