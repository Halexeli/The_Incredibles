#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Spirographe/Spirographe.hh"
#include "../Figure/Cercle.hh"
#include "../Figure/Ellipse.hh"
#include "../Figure/Polyedre.hh"
#include "../Affichage/Screen.hh"
#include "../Affichage/Page.hh"
#include "../Affichage/Bouton.hh"

TEST_CASE("Testing Spirographe") {
    Spirographe spiro(100.0f, 50.0f, 0.5f);

    SUBCASE("Etat initial") {
        sf::Vector2f pos = spiro.genererCrayonPosition(0.0f);
        CHECK(pos.x >= 0.0f);
        CHECK(pos.y >= 0.0f);
    }

    SUBCASE("Update") {
        spiro.update(0.1f);
        sf::Vector2f pos = spiro.genererCrayonPosition(0.1f);
        CHECK(pos.x >= 0.0f);
        CHECK(pos.y >= 0.0f);
    }

    SUBCASE("Reset") {
        spiro.update(0.1f);
        spiro.reset();
        sf::Vector2f pos = spiro.genererCrayonPosition(0.0f);
        CHECK(pos.x >= 0.0f);
        CHECK(pos.y >= 0.0f);
    } 
}

TEST_SUITE("Cercle") {
    TEST_CASE("Constructeur avec paramètres") {
        Point centre(5.0, 5.0);
        Cercle c2(&centre, 10.0);
        CHECK(c2.diametre() == doctest::Approx(20.0)); // Diamètre = 2 * rayon
        CHECK(c2.circonference() == doctest::Approx(2 * M_PI * 10.0)); // Circonférence = 2πr
    }

    TEST_CASE("Constructeur de copie") {
        Point centre(3.0, 4.0);
        Cercle c1(&centre, 8.0);
        Cercle c2(c1);
        CHECK(c2.diametre() == c1.diametre());
        CHECK(c2.circonference() == c1.circonference());
    }

    TEST_CASE("Méthode contientPoint() - Point à l'intérieur") {
        Point centre(0.0, 0.0);
        Cercle c1(&centre, 5.0);
        Point p1(3.0, 4.0); // Distance = 5 (à l'intérieur)
        CHECK(c1.contientPoint(p1) == true);
    }

    TEST_CASE("Redimensionner") {
        Point centre(2.0, 2.0);
        Cercle c1(&centre, 4.0);
        c1.redimensionner(2.0); // Agrandit le rayon
        CHECK(c1.diametre() == doctest::Approx(16.0)); // 2 * 4 * 2
        CHECK(c1.circonference() == doctest::Approx(2 * M_PI * 8.0)); // 2π * 8
    }
}

TEST_SUITE("Ellipse") {
    TEST_CASE("Constructeur avec paramètres") {
        Point centre(2.0, 3.0);
        Ellipse e2(&centre, 5.0, 3.0, 45.0);
        CHECK(e2.get_a() == doctest::Approx(5.0));
        CHECK(e2.getB() == doctest::Approx(3.0));
        CHECK(e2.getAngle() == doctest::Approx(45.0));
        CHECK(e2.aire() == doctest::Approx(M_PI * 5.0 * 3.0)); // Aire = πab
    }

    TEST_CASE("Méthode contientPoint() - Point à l'intérieur") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0); // Pas de rotation
        Point p1(3.0, 0.0); // À l'intérieur
        CHECK(e1.contientPoint(p1) == true);
    }

    TEST_CASE("Méthode contientPoint() - Point à l'extérieur") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        Point p2(6.0, 0.0); // À l'extérieur
        CHECK(e1.contientPoint(p2) == false);
    }

    TEST_CASE("Redimensionner avec deux facteurs") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        e1.redimensionner(2.0, 3.0);
        CHECK(e1.get_a() == doctest::Approx(10.0)); 
        CHECK(e1.getB() == doctest::Approx(9.0));  
    }

    TEST_CASE("Redimensionner avec un facteur unique") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        e1.redimensionner(2.0);
        CHECK(e1.get_a() == doctest::Approx(10.0));
        CHECK(e1.getB() == doctest::Approx(6.0));  
    }

    TEST_CASE("Pivoter") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        e1.pivoter(45.0);
        CHECK(e1.getAngle() == doctest::Approx(45.0));
        e1.pivoter(360.0);
        CHECK(e1.getAngle() == doctest::Approx(45.0)); 
        e1.pivoter(400.0);
        CHECK(e1.getAngle() == doctest::Approx(85.0)); 
    }

    TEST_CASE("Calcul de l'aire") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        CHECK(e1.aire() == doctest::Approx(M_PI * 5.0 * 3.0));
    }
}

TEST_SUITE("Polyedre") {
    TEST_CASE("Méthode contientPoint - Polyedre régulier") {
        Point centre(0.0, 0.0);
        Polyedre_regulier p1(&centre, 4, 5.0, 0.0);

        Point inside(2.0, 2.0);
        Point outside(6.0, 6.0);

        CHECK(p1.contientPoint(inside) == true);
        CHECK(p1.contientPoint(outside) == false);
    }

    TEST_CASE("Méthode contientPoint - Polyedre irrégulier") {
        Point centre(0.0, 0.0);
        std::vector<Point *> sommets = {new Point(0.0, 0.0), new Point(4.0, 0.0), new Point(4.0, 4.0), new Point(0.0, 4.0)}; // Rectangle
        Polyedre_irregulier p2(&centre, 4, sommets);

        Point inside(2.0, 2.0);
        Point outside(5.0, 5.0);

        CHECK(p2.contientPoint(inside) == true);
        CHECK(p2.contientPoint(outside) == false);
    }
}

TEST_CASE("Testing Screen") {
    Screen screen(500, 500);

    SUBCASE("fonctions draw") {
        CHECK_NOTHROW(screen.circle(250, 250, 100));
        CHECK_NOTHROW(screen.Figure_regular(250, 250, 5, 0, 50));
        CHECK_NOTHROW(screen.Figure_irregular(250, 250, 5, {new Point(0, 0), new Point(50, 0), new Point(50, 50), new Point(0, 50)}));
        CHECK_NOTHROW(screen.Ellipse(250, 250, 100, 50, 0));
        CHECK_NOTHROW(screen.text(250, 250, "Hello, World!", 24));
        CHECK_NOTHROW(screen.point(Point(250, 250)));
    }
}

TEST_CASE("Testing Page") {
    Page page;
    Screen screen(500, 500);

    SUBCASE("Draw Page") {
        CHECK_NOTHROW(page.draw(screen));
    }
}

TEST_CASE("Testing Bouton") {
    Screen screen(500, 500);
    Bouton bouton(100, 100, 50, 50, "Clicker");

    SUBCASE("Button Pressed") {
        CHECK(bouton.Ispressed(screen) == false);
    }

    SUBCASE("Draw Button") {
        CHECK_NOTHROW(bouton.draw(screen));
    }
}

TEST_CASE("Testing Texte") {
    Screen screen(500, 500);
    Texte texte(100, 100, 12, 0xFFFFFFFF, "Hello", "../Assets/Times_New_Roman/times_new_roman.ttf");

    SUBCASE("Draw Text") {
        CHECK_NOTHROW(texte.draw(screen));
    }

    SUBCASE("Add to Text") {
        texte.setText("10");
        texte.add(5);
        CHECK(texte.getText() == "15.000000");
    }

    SUBCASE("Set Text") {
        texte.setText("New Text");
        CHECK(texte.getText() == "New Text");
    }
}