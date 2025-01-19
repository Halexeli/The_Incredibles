#pragma once
#include "../Figure/Cercle.hh"
#include <SFML/Graphics.hpp>
//INSPIRÉ PAR: https://pgetinker.com/s/OWNuhyU8IgX

class Spirographe {
public:
    //construire un spirographe 
    Spirographe();
    Spirographe(float R, float r, float l);
    Spirographe(Spirographe &p);
    ~Spirographe(){};
    //permet d'update le tracé du spirographe a une certaine position
    void update(float deltaTime);
    //dessine sur un ecran SFML
    void draw(Screen& window);
    //change le petit rayon
    void setR(float r) { m_r = r; }
    //donne le petit rayon
    float getR() const { return m_r; }
    //recommence le tracé depuis le début
    void reset();
    //supprime le vertexArray m_SpirographePoints pour le tracé
    void clear_crayon(){m_SpirographePoints.clear();};
    //change la couleur du tracé
    void setColor(const sf::Color& color);
    const sf::Color getColor(){return(m_color);}
    //change la taille du crayon
    void setCrayonSize(float size) { m_l = size; }
    //donne la taille du crayon
    float getCrayonSize() const { return m_l; }
    //deplace la figure en fonction de l'axe x
    void deplacerx(float x);
    //deplace la figure en fonction de l'axe y
    void deplacery(float y);
    //augmente la taille globale
    void aug_taille(float r);
    //augmente le rapport entre le crayon et le rayon du cercle interieur
    void aug_crayon(float r){if(m_l+r>=0){m_l+=r;m_Crayon+=r;}};
    //retourne le centre
    const Point &get_centre(){return(Oc);};
    //donne le grand rayon
    const float get_R(){return(m_R);};
    //augmente le nombre de sommets (contraintes)
    void aug_sommet(int nb);
    //retourne le nombre de sommets
    const int get_sommet(){return(sommet);}; 

private:
    //ceci pour générer la position du crayon
    //afin de le dessiner sur l'écran en temps réel
    sf::Vector2f const genererCrayonPosition(float time);
    float initCrayon;
    float m_R;   //cercle fixe
    float m_r;   //cercle roulant
    float m_l;   //distance du crayon par rapport au centre du cercle intérieur
    float m_time; //temps courant
    int sommet;  //contraintes

    //données pour le spirographe
    //vertexarray: permet de dessiner des lignes entre les points
    //vector2f: permet de stocker les coordonnées des points
    sf::VertexArray m_SpirographePoints;
    sf::Vector2f m_lastCrayonPosition;

    //cercles
    Cercle m_outerCircle;
    Cercle m_innerCircle;

    //crayon
    Cercle m_Crayon;

    //Point necessaire
    Point Oc;
    Point Ic;
    Point Cr;

    //colors:
    sf::Color m_color;
};
