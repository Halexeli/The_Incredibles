#include "Spirographe.hh"
#include <cmath>

//nb: mtime est le temps écoulé
Spirographe::Spirographe(float R, float r, float l) : m_R(R), m_r(r), m_l(l), m_time(0.0f), m_SpirographePoints(sf::PrimitiveType::LinesStrip), m_outerCircle(Point(400, 300), R), m_innerCircle(Point(400 + (R - r), 300), r), m_Crayon(2) 
{       //last position du crayon initialisée à la position du crayon au temps 0
        m_lastCrayonPosition = genererCrayonPosition(m_time);
        //couleur du crayon
        m_Crayon.setFillColor(sf::Color::Red);
        m_Crayon.setOrigin(2, 2);
    }

//equatoins utilisées: 
//x = (R - r) * cos(t) + l * r * cos((R - r) * t / r)
//y = (R - r) * sin(t) - l * r * sin((R - r) * t / r) 

sf::Vector2f Spirographe::genererCrayonPosition(float time) const {
    //ici on génère la position d'un crayon en fct du temps
    
    float CrayonX = (m_R - m_r) * cos(time) + m_l * m_r * cos((m_R - m_r) * time / m_r);
    float CrayonY = (m_R - m_r) * sin(time) - m_l * m_r * sin((m_R - m_r) * time / m_r);
    return sf::Vector2f(400.f + CrayonX, 300.f + CrayonY); 
}

//le update sert à mettre à jour la position du crayon en fonction du deltatime
/*
principe: 
    - on incrémente le temps écoulé
    -si le spirographe a déjà des points, on ajoute le dernier point i.e ancienne position du crayon et le nouveau point
    -sinon on ajoute juste le nouveau point
    -ensuite on calcule la nvle position du cercle mobile (interne )
    -ceci sert à animer le spirographe

*/
void Spirographe::update(float deltaTime) {
    m_time += deltaTime; 
    sf::Vector2f newCrayonPosition = genererCrayonPosition(m_time); //on génère la nouvelle position du crayon


    
    if (m_SpirographePoints.getVertexCount() > 0) { 
        //
        m_SpirographePoints.append(sf::Vertex(m_lastCrayonPosition, sf::Color::Green));
        m_SpirographePoints.append(sf::Vertex(newCrayonPosition, sf::Color::Green));
    } else { 
        m_SpirographePoints.append(sf::Vertex(newCrayonPosition, sf::Color::Green));
    }

    m_lastCrayonPosition = newCrayonPosition;

    float innerX = (m_R - m_r) * cos(m_time);
    float innerY = (m_R - m_r) * sin(m_time);
    m_innerCircle = Cercle(Point(400.f + innerX, 300.f + innerY), m_r);


    m_Crayon.setPosition(newCrayonPosition);
}

void Spirographe::draw(sf::RenderWindow& window) {
    window.draw(m_SpirographePoints);
    m_outerCircle.afficher(window);
    m_innerCircle.afficher(window);
    window.draw(m_Crayon);
}
