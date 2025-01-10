//code modifié qui provient du TP6 de Mme Braunstein

#include "Screen.hh"
#include <cassert>
#include <math.h>

/* Positions origin are upper left corner */


void Screen::render()
{
  _win->display();
  _win->clear();
}

void Screen::rect( float x, float y, float w, float h, uint32_t color)
{
  sf::RectangleShape rectangle(sf::Vector2f(w, h));
  rectangle.setFillColor(sf::Color(color));
  rectangle.setPosition(x, y);
  _win->draw(rectangle);
}


void Screen::disc(float x_center, float y_center, float radius, uint32_t color)
{
  sf::CircleShape shape(radius);
  shape.setFillColor(sf::Color(color));
  shape.setPosition(x_center-radius, y_center-radius);
  _win->draw(shape);
}

void Screen::light(float x, float y, float h, float w, uint32_t color)
{
  sf::ConvexShape convex;
  convex.setPointCount(6);
  convex.setPoint(0, sf::Vector2f(0.f, 0.f));
  convex.setPoint(1, sf::Vector2f((3.f/5.f) * w ,-(4.f/7.f) * h ));
  convex.setPoint(2, sf::Vector2f((3.f/5.f) * w, -(1.f/7.f) * h ));
  convex.setPoint(3, sf::Vector2f( w, -(1.f/7.f) * h ));
  convex.setPoint(4, sf::Vector2f((2.f/5.f) * w, (3.f/7.f) * h ));
  convex.setPoint(5, sf::Vector2f((2.f/5.f) * w ,0.f));
  convex.setFillColor(sf::Color(color));
  convex.setPosition(x, y);
  _win->draw(convex);
}


void Screen::diamond(float x, float y, float h, float w, uint32_t color)
{
   sf::ConvexShape convex;
   convex.setPointCount(4);
   convex.setPoint(0, sf::Vector2f(0.f, 0.f));
   convex.setPoint(1, sf::Vector2f(w/2.f ,-h/2.f));
   convex.setPoint(2, sf::Vector2f(w, 0.f));
   convex.setPoint(3, sf::Vector2f( w/2, h/2 ));
   convex.setFillColor(sf::Color(color));
   convex.setPosition(x, y);
   _win->draw(convex);
}

void Screen::star(float x, float y, float size, uint32_t color)
{
  float h,w;
  h = w = size;
  sf::ConvexShape convex;
  convex.setPointCount(10);
  convex.setPoint(0, sf::Vector2f(0.f, 0.f));
  convex.setPoint(1, sf::Vector2f((3.f/8.f)*w,0.f));
  convex.setPoint(2, sf::Vector2f(w/2.f, -(3.f/8.f)*h));
  convex.setPoint(3, sf::Vector2f((5.f/8.f)*w, 0.f ));
  convex.setPoint(4, sf::Vector2f(w, 0.f ));
  convex.setPoint(5, sf::Vector2f((6.f/8.f)*w, (1.f/4.f)*h ));
  convex.setPoint(6, sf::Vector2f((7.f/8.f)*w, (5.5/8.f)*h ));
  convex.setPoint(7, sf::Vector2f(w/2.f, (1.f/2.f)*h ));
  convex.setPoint(8, sf::Vector2f((1.f/8.f)*w,(5.5/8.f)*h ));
  convex.setPoint(9, sf::Vector2f((1.f/4.f)*w, h/4.f ));
  convex.setFillColor(sf::Color(color));
  convex.setPosition(x, y);
  _win->draw(convex);
}

void Screen::text(float x ,float y,std::string str_txt,int size, uint32_t color, std::string font_file)
{
  sf::Font font;
  if (!font.loadFromFile(font_file))
    {
      std::cerr << "no font found" << std::endl;
    }
  sf::Text text;

  text.setFont(font);
  text.setCharacterSize(size);
  text.setString(str_txt);
  text.setFillColor(sf::Color(color));
  text.setPosition(x,y);
  _win->draw(text);
}

void Screen::Figure_regular(float x, float y,int sommet,float angle, float size, uint32_t color){
  // crée une forme vide
  sf::ConvexShape convex;
  // définit le nombre de points (sommet)
  convex.setPointCount(sommet);
  // définit les points
  for(int i=0; i<sommet;i++)
    convex.setPoint(i, sf::Vector2f(cos(angle+(360*i/sommet))*size, cos(angle+(360*i/sommet))*size));
  convex.setFillColor(sf::Color(color));
  convex.setPosition(x, y);
  _win->draw(convex);
}

void Screen::Figure_irregular(float x, float y,int sommet,std::vector <Point> point, uint32_t color){
  // crée une forme vide
  sf::ConvexShape convex_irr;
  // définit le nombre de points (sommet)
  convex_irr.setPointCount(sommet);
  // définit les points
  int i=0;
  for(auto it:point){
    convex_irr.setPoint(i, sf::Vector2f(it.getX(),it.getY()));
    i++;
  }
  convex_irr.setFillColor(sf::Color(color));
  convex_irr.setPosition(x, y);
  _win->draw(convex_irr);
}

bool Screen::Buttonclicked(float x, float y, float w, float h) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*_win);
    return (mousePos.x >= x && mousePos.x <= x + w && mousePos.y >= y && mousePos.y <= y + h && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

void Screen::Ellipse(float x, float y,float a, float b,float angle,uint32_t color){
    sf::CircleShape ellipse;
    ellipse.setRadius(static_cast<float>(a));  // Définit le rayon
    ellipse.setScale(1.f, static_cast<float>(b / a)); // Applique une échelle pour simuler une ellipse
    ellipse.setFillColor(sf::Color(color)); 
    ellipse.setOutlineThickness(1);
    ellipse.setOutlineColor(sf::Color(255, 255, 255)); // Blanc
    ellipse.setPosition(x, y);
    ellipse.setRotation(static_cast<float>(angle));
    _win->draw(ellipse);
}

void Screen::circle(float x, float y, float radius, uint32_t color){
    sf::CircleShape circle;
    circle.setRadius(radius); // Rayon
    circle.setFillColor(sf::Color(color)); // transparent
    circle.setOutlineThickness(1);
    circle.setOutlineColor(sf::Color(255, 255, 255)); // Blanc
    circle.setPosition(x-radius, y-radius); // Centré
    _win->draw(circle);
}

void Screen::point(Point p,uint32_t color = 0x00000000){
  sf::CircleShape aff_point;
  aff_point.setRadius(0.5); // Rayon
  aff_point.setFillColor(sf::Color(color)); // transparent
  aff_point.setOutlineThickness(1);
  aff_point.setPosition(p.getX()-0.5, p.getY()-0.5); // Centré
  _win->draw(aff_point);
}