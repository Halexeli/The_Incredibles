#pragma once
#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

void inter(Page *&current,Page *page1,Page *page2,std::vector<Spirographe*>&spirographes,Screen &screen, float &speed);