#include "Spirographe.hh"
#include <cmath>

//nb: mtime est le temps écoulé
Spirographe::Spirographe(float R, float r, float l) : Oc(Point(400, 300)),Ic(Point(400 + (R - r), 300)),Cr(Point(0, 0)), m_R(R), m_r(r), m_l(l), m_time(0.0f), m_SpirographePoints(sf::PrimitiveType::LinesStrip), m_outerCircle(&Oc, R), m_innerCircle(&Ic, r), m_Crayon(&Cr, 2),m_color(sf::Color::Green)
{       //last position du crayon initialisée à la position du crayon au temps 0
        m_lastCrayonPosition = genererCrayonPosition(m_time);
        //couleur du crayon
        m_Crayon.setFillColor(sf::Color::Red);
        initCrayon = l;
    }

//equatoins utilisées: 
//x = (R - r) * cos(t) + l * r * cos((R - r) * t / r)
//y = (R - r) * sin(t) - l * r * sin((R - r) * t / r) 

sf::Vector2f const Spirographe::genererCrayonPosition(float time) {
    //ici on génère la position d'un crayon en fct du temps
    float centreX = m_outerCircle.getCentre()->getX();
    float centreY = m_outerCircle.getCentre()->getY();
    float CrayonX = (m_R - m_r) * cos(time) + m_l * m_r * cos((m_R - m_r) * time / m_r);
    float CrayonY = (m_R - m_r) * sin(time) - m_l * m_r * sin((m_R - m_r) * time / m_r);
    return sf::Vector2f(centreX + CrayonX, centreY + CrayonY);
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
        
        m_SpirographePoints.append(sf::Vertex(m_lastCrayonPosition, m_color));
        m_SpirographePoints.append(sf::Vertex(newCrayonPosition, m_color));
    } else { 
        m_SpirographePoints.append(sf::Vertex(newCrayonPosition, m_color));
    }

    m_lastCrayonPosition = newCrayonPosition;
    float centerX = m_outerCircle.getCentre()->getX();
    float centerY = m_outerCircle.getCentre()->getY();
    float innerX = (m_R - m_r) * cos(m_time);
    float innerY = (m_R - m_r) * sin(m_time);
    Ic=Point(centerX + innerX, centerY + innerY);
    m_innerCircle = Cercle(&Ic, m_r);
    

    m_Crayon.setCentre(Point(newCrayonPosition.x, newCrayonPosition.y));
}

void Spirographe::draw(Screen& window) {
    window.draw(m_SpirographePoints);
    m_outerCircle.afficher(window);
    m_innerCircle.afficher(window);
    m_Crayon.afficher(window);
}


void Spirographe::reset() {
    m_time = 0.0f;
    m_SpirographePoints.clear();
    m_lastCrayonPosition = genererCrayonPosition(m_time);
    Ic=Point(m_outerCircle.getCentre()->getX() + m_R - m_r, m_outerCircle.getCentre()->getY());
    m_innerCircle = Cercle(&Ic, m_r);
    m_Crayon.setCentre(Point(m_lastCrayonPosition.x, m_lastCrayonPosition.y));
    m_color = sf::Color::Green;
    m_l = initCrayon;
    
}

void Spirographe::setColor(const sf::Color& color) {
    m_color = color;
    m_Crayon.setFillColor(color);
    for (size_t i = 0; i < m_SpirographePoints.getVertexCount(); ++i) {
        m_SpirographePoints[i].color = color;
    }
}