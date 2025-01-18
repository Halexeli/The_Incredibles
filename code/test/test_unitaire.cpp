// Let DocTest provide main():
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Spirographe/Spirographe.hh"
#include "../Figure/Ellipse.hh"
#include "../Figure/Figure.hh"
#include "../Figure/Point.hh"
#include "../Figure/Polyedre.hh"
#include "../Affichage/Bouton.hh"
#include "../Affichage/Page.hh"
#include "../Affichage/Screen.hh"

TEST_SUITE("Spirographe") {
  TEST_CASE("1: update() bonne taille"){
    Spirographe s1;
    for(int i=0;i<10000;i++)
    s1.update(i);
    CHECK(s1.get_to_draw().size()<=1000);
  }

  TEST_CASE("2: update() commence au bon endroit"){
    Spirographe s1;
    s1.update(0.1);
    float x_temp,y_temp;
    x_temp,y_temp =s1.get_to_draw()[0];
    CHECK(x_temp==0.f);
    CHECK(y_temp==0.f);
  }
}

TEST_SUITE("Ellipse"){
  TEST_CASE("5: check save and load")
    {
      Point p0(0,0);
      Ellipse e0(p0,10);
      Cercle p1();
      //CHECK();

    }
}

TEST_CASE("3: Grid contents"){

  SUBCASE("All characters are printable character"){

  }
  SUBCASE("Same grids are equals")
    {

    }
  SUBCASE("Two successively generated grid are different")
    {

    }
  SUBCASE("reset make differences")
    {

    }
}
TEST_SUITE("Affichage"){
  TEST_CASE("3: Bouton")
    {

    }

  TEST_CASE("7: Page")
    {

      SUBCASE("Correct size")
        {

        }
      SUBCASE(" starting point whithin bounds")
        {

        }
    }

  TEST_CASE("7: Screen")
    {

      SUBCASE("Correct size")
        {

        }
      SUBCASE(" starting point whithin bounds")
        {

        }
    }
}