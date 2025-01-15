#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"


bool inter1(Page *current,Screen &screen){
    if(current->get_Bouton(0)->Ispressed(screen)){
        return(1);
    }
    else{
        return(0);
    }
}

int inter2(Page *current,Spirographe *spirographe,Screen &screen){
    return(0);
}

int inter3(Page *current,Spirographe *spirographe,Screen &screen){
    return(0);
}
void inter(Page *current,Page *page1,Page *page2,Page *page3,std::vector<Spirographe*>&spirographes,Screen &screen){
    switch(current->get_id()){
        case 0 :
            if(inter1(current,screen)){
                //Spirographe *newspiro=new Spirographe(100.f, 20.f, 0.3f);
                //spirographes.push_back(newspiro);
            }
        
        case 1 :
            if(inter2(current,spirographes.back(),screen));
        
        case 2 :
            if(inter3(current,spirographes.back(),screen));

    }

}