#include "Figure/Ellipse.hh"

int main(){
    Cercle c(Point(100,100),50);
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
    sf::CircleShape shape;
    sf::Cursor cursor;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }    

        if (cursor.loadFromSystem(sf::Cursor::Hand))
            window.setMouseCursor(cursor);

        c.afficher(shape);
        window.clear();
        window.draw(shape);
        window.display();
    }


    return 0;
}
