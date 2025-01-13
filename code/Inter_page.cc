#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"


bool inter1(Page *current){
    return(1);

}

bool inter2(Page *current){
    return(0);
}

bool inter3(Page *current){
    return(0);
}
void inter(Page *current,Page *page1,Page *page2,Page *page3,std::vector<Spirographe*>*spirographes){
    switch(current->get_id()){
        case 0 :
            if(inter1(current)){
                current=page2;
                Spirographe *nvspiro=new Spirographe(5,1,0.5);
                spirographes->push_back(nvspiro);
            }
        
        case 1 :
            if(inter2(current))
                current=page1;
        
        case 2 :
            if(inter3(current))
                current=page1;
        
    }

}