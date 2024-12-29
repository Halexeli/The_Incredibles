#pragma once
#include "../Figure/Cercle.hh"
#include <SFML/Graphics.hpp>
//INSPIRÉ PAR: https://pgetinker.com/s/OWNuhyU8IgX

class Spirographe {
public:
    //construire un spirographe 
    Spirographe(float R, float r, float l);
    void update(float deltaTime);
    void draw(Screen& window);
    void setR(float r) { m_r = r; }
    float getR() const { return m_r; }
    void reset();

private:
    //ceci pour générer la position du crayon
    //afin de le dessiner sur l'écran en temps réel
    sf::Vector2f genererCrayonPosition(float time) const;

    float m_R;   //cercle fixe
    float m_r;   //cercle roulant
    float m_l;   //distance du crayon par rapport au centre du cercle intérieur
    float m_time; //temps courant

    //données pour le spirographe
    //vertexarray: permet de dessiner des lignes entre les points
    //vector2f: permet de stocker les coordonnées des points
    sf::VertexArray m_SpirographePoints;
    sf::Vector2f m_lastCrayonPosition;

    //cercles
    Cercle m_outerCircle;
    Cercle m_innerCircle;

    //crayon
    sf::CircleShape m_Crayon;
};
