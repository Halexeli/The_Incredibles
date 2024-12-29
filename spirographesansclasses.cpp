#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
//inspiré par: https://pgetinker.com/s/OWNuhyU8IgX

sf::Vector2f generatePenPosition(float R, float r, float l, float time) {
    float penX = (R - r) * cos(time) + l * r * cos((R - r) * time / r);
    float penY = (R - r) * sin(time) - l * r * sin((R - r) * time / r);
    return sf::Vector2f(400.f + penX, 300.f + penY); 
}

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Spirograph");

    float R = 200.f;  
    float r = 57.f;   
    float l = 0.9f;   //distance du stylo par rapport au centre du cercle intérieur
    float rotations = 10.0f;  //nbr de rotations à faire
    size_t numPoints = 1000;  //points à génerer


    sf::VertexArray spirographPoints(sf::PrimitiveType::LinesStrip);

    sf::Clock clock;
    float time = 0.0f;
    sf::Vector2f lastPenPosition = generatePenPosition(R, r, l, time);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        time += clock.restart().asSeconds() * 2; 

        sf::Vector2f newPenPosition = generatePenPosition(R, r, l, time);

        if (spirographPoints.getVertexCount() > 0) {
            spirographPoints.append(sf::Vertex(lastPenPosition, sf::Color::Green));
            spirographPoints.append(sf::Vertex(newPenPosition, sf::Color::Green));
        } else {
            spirographPoints.append(sf::Vertex(newPenPosition, sf::Color::Green));
        }

        lastPenPosition = newPenPosition;

        window.clear();

        window.draw(spirographPoints);

        sf::CircleShape outerCircle(R);
        outerCircle.setFillColor(sf::Color::Transparent);
        outerCircle.setOutlineColor(sf::Color::White);
        outerCircle.setOutlineThickness(1);
        outerCircle.setOrigin(R, R);
        outerCircle.setPosition(400.f, 300.f);
        window.draw(outerCircle);

        float innerX = (R - r) * cos(time);
        float innerY = (R - r) * sin(time);
        sf::CircleShape innerCircle(r);
        innerCircle.setFillColor(sf::Color::Transparent);
        innerCircle.setOutlineColor(sf::Color::White);
        innerCircle.setOutlineThickness(1);
        innerCircle.setOrigin(r, r);
        innerCircle.setPosition(400.f + innerX, 300.f + innerY);
        window.draw(innerCircle);

        float penX = (R - r) * cos(time) + l * r * cos((R - r) * time / r);
        float penY = (R - r) * sin(time) - l * r * sin((R - r) * time / r);
        sf::CircleShape pen(2);
        pen.setFillColor(sf::Color::Red);
        pen.setOrigin(2, 2);
        pen.setPosition(400.f + penX, 300.f + penY);
        window.draw(pen);

        window.display();
    }

    return 0;
}
