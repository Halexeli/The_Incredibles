// Let DocTest provide main():
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//using namespace doctest; // Utilisation du namespace doctest

#include "doctest.h"
#include "../Spirographe/Spirographe.hh"
#include "../Figure/Ellipse.hh"
#include "../Figure/Figure.hh"
#include "../Figure/Point.hh"
#include "../Figure/Polyedre.hh"
#include "../Affichage/Bouton.hh"
#include "../Affichage/Page.hh"
#include "../Affichage/Screen.hh"
#include "../Figure/Cercle.hh"

TEST_SUITE("Spirographe") {
  TEST_CASE("1: la contrainte est correcte"){
    Spirographe s1(100,20,0.1);
    CHECK(s1.get_sommet()==5);
  }

  TEST_CASE("2: le changement global fonctionnement bien"){
    Spirographe s1;
    s1.aug_taille(100);
    CHECK(s1.get_R()==200);
    CHECK(s1.getR()==40);
  }
  TEST_CASE("Changement de couleur (setColor)") {
        Spirographe spiro(100.0f, 50.0f, 0.5f);
        sf::Color newColor = sf::Color::Red;
        spiro.setColor(newColor);
        // Vérifie que la couleur du spirographe et du crayon a été changée
        CHECK(spiro.getColor() == newColor);
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
        CHECK(e1.get_a() == doctest::Approx(10.0)); // 5 * 2
        CHECK(e1.getB() == doctest::Approx(9.0));  // 3 * 3
    }

    TEST_CASE("Redimensionner avec un facteur unique") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        e1.redimensionner(2.0);
        CHECK(e1.get_a() == doctest::Approx(10.0)); // 5 * 2
        CHECK(e1.getB() == doctest::Approx(6.0));  // 3 * 2
    }

    TEST_CASE("Pivoter") {
        Point centre(0.0, 0.0);
        Ellipse e1(&centre, 5.0, 3.0, 0.0);
        e1.pivoter(45.0);
        CHECK(e1.getAngle() == doctest::Approx(45.0));
        e1.pivoter(360.0);
        CHECK(e1.getAngle() == doctest::Approx(45.0)); // Retourne à l'angle initial
        e1.pivoter(400.0);
        CHECK(e1.getAngle() == doctest::Approx(85.0)); // 45 + 400 - 360 = 85
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
        Polyedre_regulier p1(&centre, 4, 5.0, 0.0); // Carré de côté 5

        Point inside(2.0, 2.0);  // À l'intérieur
        Point outside(6.0, 6.0); // À l'extérieur

        CHECK(p1.contientPoint(inside) == true);
        CHECK(p1.contientPoint(outside) == false);
    }

    TEST_CASE("Méthode contientPoint - Polyedre irrégulier") {
        Point centre(0.0, 0.0);
        Point P1(0.0,0.0),P2(4.0,0.0),P3(4.0,4.0),P4(0.0,4.0);
        std::vector<Point*> sommets;
        sommets.push_back(&P1);
        sommets.push_back(&P2);
        sommets.push_back(&P3);
        sommets.push_back(&P4);


        Polyedre_irregulier p2(&centre, 4, sommets);

        Point inside(2.0, 2.0);  // À l'intérieur
        Point outside(5.0, 5.0); // À l'extérieur

        CHECK(p2.contientPoint(inside) == true);
        CHECK(p2.contientPoint(outside) == false);
    }

    
}
