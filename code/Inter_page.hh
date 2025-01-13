#pragma once
#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

void inter(Page *current,Page *page1,Page *page2,Page *page3,std::vector<Spirographe*>*spirographes);
bool inter1(Page *current);
bool inter2(Page *current);
bool inter3(Page *current);