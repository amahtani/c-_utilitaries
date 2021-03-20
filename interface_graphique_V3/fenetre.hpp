#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <string>

#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/label.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/stock.h>
#include <gtkmm/window.h>

class Fenetre : public Gtk::Window {
    public :
        Fenetre();
        
        typedef sigc::signal<void> type_signal_pourcentage_moitie; //Création d'un typedef pour le type du signal.
        type_signal_pourcentage_moitie signal_pourcentage_moitie(); //Création de la méthode qui retourne le signal.
        
        typedef sigc::signal<void, std::string> type_signal_pourcentage_max;
        type_signal_pourcentage_max signal_pourcentage_max();
        
        void ajouterPourcentage(); //Création d'une fonction de rappel.
        
    protected :
        type_signal_pourcentage_moitie signalPourcentageMoitie; //Création du signal.
        type_signal_pourcentage_max signalPourcentageMax;
        
    private :
        Gtk::ProgressBar barreProgression; //Création d'une barre de progression.
        Gtk::VButtonBox boiteV;
        Gtk::Button bouton;
        Gtk::Label etiquette;
};

#endif
