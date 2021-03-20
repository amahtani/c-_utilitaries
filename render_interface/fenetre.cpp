#include "fenetre.hpp"

using namespace std;

Fenetre::Fenetre() : bouton("Hello World!") {
    set_title("Hello World!");
    set_border_width(10);
    
    add(bouton);
    bouton.show();
    bouton.set_can_focus(false);
    
    bouton.signal_clicked().connect(sigc::bind<string>(sigc::mem_fun(*this, &Fenetre::set_title), "Bonjour le monde !")); //Lorsque l'utilisateur clique sur le bouton, modifier le titre et...
    bouton.signal_clicked().connect(sigc::bind<string>(sigc::mem_fun(bouton, &Gtk::Button::set_label), "Bonjour le monde !")); //... le texte sur le bouton.
}
