#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/table.h>
#include <gtkmm/window.h>

int main(int argc, char* argv[]) {
    
    Gtk::Main app(argc, argv);
    
    Gtk::Window fenetre;
    
    Gtk::Table tableau(5, 5); //Création d'un tableau de 3 case par 3 cases, dont les cases ne sont pas nécessairement de même grandeur.
    
    fenetre.add(tableau);
    
    Gtk::Button bouton1("Bouton 1");
    Gtk::Button bouton2("Bouton 2");
    Gtk::Button bouton3("Bouton 3");
    Gtk::Button bouton4("Bouton 4");
    Gtk::Button bouton5("Bouton 5");
    Gtk::Button bouton6("Bouton 6");
    Gtk::Button bouton7("Bouton 7");
    Gtk::Button bouton8("Bouton 8");
    Gtk::Button bouton9("Bouton 9");
    bouton1.set_can_focus(false);
    bouton2.set_can_focus(false);
    bouton3.set_can_focus(false);
    bouton4.set_can_focus(false);
    bouton5.set_can_focus(false);
    bouton6.set_can_focus(false);
    bouton7.set_can_focus(false);
    bouton8.set_can_focus(false);
    bouton9.set_can_focus(false);
    
    tableau.attach(bouton1, 0, 1, 1, 1, Gtk::FILL, Gtk::FILL, 5, 1); //Ajout d'un widget dans le tableau : ce widget sera de (0, 0) à (1, 1). Le widget prend le moins d'espace possible.
    tableau.attach(bouton2, 1, 0, 2, 1, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton3, 2, 0, 3, 1, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton4, 0, 1, 1, 2, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton5, 1, 1, 2, 2, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton6, 2, 1, 3, 2, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton7, 0, 2, 1, 3, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton8, 1, 2, 2, 3, Gtk::FILL, Gtk::FILL, 5, 1);
    tableau.attach(bouton9, 2, 2, 3, 3, Gtk::FILL, Gtk::FILL, 5, 1);
    
    fenetre.show_all(); //L'habituel show_all() pour afficher tous les widgets.
    
    Gtk::Main::run(fenetre);
    
    return 0;
}


