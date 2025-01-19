#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

bool inter_in(Page *current,Spirographe *spirographes,Screen &screen){
    if(current->get_Bouton(10)->Ispressed(screen))
    return(1);
    const Point test=spirographes->get_centre();
    sf::Vector2u size=screen.getSize();
    const float R=spirographes->get_R();
    //x +
    if(current->get_Bouton(2)->Ispressed(screen) && size.x>(test.getX()+R)){
        spirographes->deplacerx(2);
        spirographes->clear_crayon();
        current->get_String(2)->add(2);
    }
    //y -
    else if(current->get_Bouton(4)->Ispressed(screen) && (test.getY()-R)>0){
        spirographes->deplacery(-2);
        spirographes->clear_crayon();
        current->get_String(3)->add(-2);
    }
    //x -
    else if(current->get_Bouton(3)->Ispressed(screen) && (test.getX()-R)>0){
        spirographes->deplacerx(-2);
        spirographes->clear_crayon();
        current->get_String(2)->add(-2);
    }
    //y +
    else if(current->get_Bouton(5)->Ispressed(screen) && (test.getY()+R)<size.y){
        spirographes->deplacery(2);
        spirographes->clear_crayon();
        current->get_String(3)->add(2);
    }
    //sommet +1
    else if(current->get_Bouton(0)->Ispressed(screen) && spirographes->get_sommet()>0){
        spirographes->aug_sommet(-1);
        spirographes->clear_crayon();
        current->get_String(0)->add(-1);
    }
    //sommet -1
    else if(current->get_Bouton(1)->Ispressed(screen)){
        spirographes->aug_sommet(1);
        spirographes->clear_crayon();
        current->get_String(0)->add(1);
    }
    //rayon globale +1
    else if(current->get_Bouton(6)->Ispressed(screen)){
        spirographes->aug_taille(2);
        spirographes->clear_crayon();
        current->get_String(4)->add(2);
    }
    //rayon globale -1
    else if(current->get_Bouton(7)->Ispressed(screen)){
        spirographes->aug_taille(-2);
        spirographes->clear_crayon();
        current->get_String(4)->add(-2);
    }
    //taille du crayon + 0.1
    else if(current->get_Bouton(8)->Ispressed(screen)){
        spirographes->aug_crayon(0.1);
        spirographes->clear_crayon();
        current->get_String(6)->add(0.1);
    }
    //taille du crayon - 0.1
    else if(current->get_Bouton(9)->Ispressed(screen) && spirographes->getCrayonSize()-0.02>=0){
            spirographes->aug_crayon(-0.1);
            spirographes->clear_crayon();
            current->get_String(6)->add(-0.1);
    }
    else if(current->get_Bouton(11)->Ispressed(screen)){
        //rose
        spirographes->setColor(sf::Color(0xFF33D4FF));
    }
    else if(current->get_Bouton(12)->Ispressed(screen)){
        //violet
        spirographes->setColor(sf::Color(0xA41BFDFF));
    }
    else if(current->get_Bouton(13)->Ispressed(screen)){
        //bleu
        spirographes->setColor(sf::Color(0x0785FCFF));
    }
    else if(current->get_Bouton(14)->Ispressed(screen)){
        //vert
        spirographes->setColor(sf::Color(0x00FF00FF));
    }
    else if(current->get_Bouton(15)->Ispressed(screen)){
        //jaune
        spirographes->setColor(sf::Color(0xFEFC1DFF));
    }
    else if(current->get_Bouton(16)->Ispressed(screen)){
        //orange
        spirographes->setColor(sf::Color(0xF76C1AFF));
    }
    else if(current->get_Bouton(17)->Ispressed(screen)){
        //Rouge
        spirographes->setColor(sf::Color(0xF90B08FF));
    }

    return(0);
}

void inter(Page *&current,Page *page1,Page *page2,std::vector<Spirographe*>&spirographes,Screen &screen){
    if(current->get_id()==0)
    {
        if(page1->get_Bouton(0)->Ispressed(screen)){
            //on ajoute un un spirographe
            current=page2;
            spirographes.push_back(new Spirographe(100.f, 20.f, 0.3f));
        }
        else if(page1->get_Bouton(1)->Ispressed(screen)){
            //on les enleve tous
            spirographes.clear();
        }
    }
    else if(current->get_id()==1)
    {
        if(inter_in(current,spirographes.back(),screen)){
            //si on change de page on "rafraichit" les valeurs de base
            current=page1;
            page2->get_String(0)->set("5");
            page2->get_String(2)->set("400");
            page2->get_String(3)->set("300");
            page2->get_String(4)->set("100");
            page2->get_String(6)->set("0.3");
        }

    }
}