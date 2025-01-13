//Code modifié qui provient du TP6 de Mme Braunstein
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Figure/Point.hh"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

 /**
     Constructor of Screen  open a SFML window
     @param w width of the window (e.g. 500)
     @param h height of the window (e.g. 500)
 **/

class Screen: public sf::RenderWindow {
 public:
  Screen(uint16_t h, uint16_t w) : sf::RenderWindow(sf::VideoMode(h, w), "Incredible Spirographe"), _win(this){};
  ~Screen(){/*delete _win;*/};
  bool isOpen(){return _win->isOpen();}
  void close(){_win->close();}
  bool pollEvent(sf::Event& event){return _win->pollEvent(event);}
  void render();
  void rect(float x, float y, float w, float h, uint32_t color = 0xFF0000FF);
  /** draw a filled rectangle
      @param x x-coordinate of the center (in pixels)
      @param y y-coordinate of the center (in pixels)
      @param w width of the rectangle (in pixels)
      @param h height of the rectangle (in pixels)
      @param color 0xRRGGBBAA (default: blue)
  */
  void line(int x0, int y0, int x1, int y1, uint32_t color = 0xFF0000FF);
  /** draw a line
      @param x0 starting x-coordinate (in pixels)
      @param y0 starting y-coordinate (in pixels)
      @param x1 ending x-coordinate (in pixels)
      @param y1 ending y-coordinate (in pixels)
      @param color 0xRRGGBBAA (default: red)
  */
  void disc(float x, float y, float radius, uint32_t color = 0xFF0000FF);
   /** draw a disc
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param radius (in pixels)
    @param color 0xRRGGBBAA (default: red)
  */

   void circle(float x, float y, float radius, uint32_t color = 0x00000000 );
   /** draw a disc
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param radius (in pixels)
    @param color   default transparent color = 0x00000000
  */

  void light(float x, float y, float height, float width, uint32_t color = 0xFFFF00FF);
   /** draw a lightning
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param height(in pixels)
    @param width(in pixels)
    @param color 0xRRGGBBAA (default: yellow
  */
  void diamond(float x, float y, float height, float width, uint32_t color = 0xAEFBFFFF);
   /** draw a diamond
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param height(in pixels)
    @param width(in pixels)
    @param color 0xRRGGBBAA (default: light blue
  */
  void star(float x, float y, float size, uint32_t color = 0xFFCD00FF);
   /**   draw a star
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param size  (in pixels)
    @param color 0xRRGGBBAA (default: orange)
  */
  void Figure_regular(float x, float y,int sommet,float angle, float size, uint32_t color= 0xAEFBFFFF);
   /**   draw a regular figure convex
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param sommet nombre de sommets
    @param angle l'angle que la figure fait avec l'axe x (et le premier segment qui va du centre de la figure au premier point)
    @param size taille des segments du centre de la figure 
    @param color 0xRRGGBBAA (default: light blue)
  */
  void Figure_irregular(float x, float y,int sommet, std::vector <Point *> point,uint32_t color= 0xAEFBFFFF);
   /**   draw a irregular figure convex
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param sommet nombre de sommets
    @param point vecteur des coordonnées des points autour de la figure si (x,y)=(0,0)
    @param color 0xRRGGBBAA (default: light blue)
  */
   void Ellipse(float x, float y,float a, float b,float angle,uint32_t color= 0x00000000);
   /**   draw a irregular figure convex
    @param x x-coordinate of the center (in pixels)
    @param y y-coordinate of the center (in pixels)
    @param a rayon
    @param b echelle pour simuler une ellipse
    @param angle angle avec le x-axis
    @param sommet nombre de sommets
    @param point vecteur des coordonnées des points autour de la figure si (x,y)=(0,0)
    @param color default : blue
  */
  void text(float x ,float y,std::string text,int size,uint32_t color = 0x35EEEEFF,std::string font_file = "../../Assets/Times_New_Roman/times_new_roman.ttf");
  //Permet d'afficher un texte

  void point(Point p,uint32_t color = 0x00000000);
  //affiche un point

  uint16_t w() const {return _w;}
  uint16_t h() const {return _h;}
  bool Buttonclicked(float x, float y, float w, float h);
  //permet de voir si un bouton est cliqué
 protected:


 private:
  sf::RenderWindow *  _win;
  uint16_t _w, _h;

  
  
};