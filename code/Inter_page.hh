#pragma once
#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

void inter(Page *current,Page *page1,Page *page2,Page *page3,std::vector<Spirographe*>&spirographes,Screen &screen);
bool inter1(Page *current,Screen &screen);
int inter2(Page *current,Screen &screen);
int inter3(Page *current,Screen &screen);