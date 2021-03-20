#include "fenetre.hpp"

Fenetre::Fenetre() : boiteV(Gtk::BUTTONBOX_SPREAD), bouton(Gtk::Stock::ADD) {
    add(boiteV);
    
    boiteV.pack_start(bouton);
    bouton.set_can_focus(false);
    boiteV.pack_start(barreProgression);
    boiteV.pack_start(etiquette);
    
    //Connexion du signal clicked() à une fonction de rappel.
    bouton.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::ajouterPourcentage));
    //Connexion du signal pourcentage_moitie() à une fonction de rappel en ajoutant un paramètre.
    signal_pourcentage_moitie().connect(sigc::bind<std::string>(sigc::mem_fun(etiquette, &Gtk::Label::set_text), "Le pourcentage est 50%."));
    //Cette fois, pas besoin d'ajouter un paramètre, car le signal le transmet automatiquement.
    signal_pourcentage_max().connect(sigc::mem_fun(etiquette, &Gtk::Label::set_text));
    
    //Affichage des widgets.
    show_all();
}

void Fenetre::ajouterPourcentage() {
    double nouveauPourcentage(barreProgression.get_fraction() + 0.1);
    
    if(std::abs(nouveauPourcentage - 0.5) < 0.00001) {
        signal_pourcentage_moitie().emit(); //Émettre notre signal perso.
    }
    else if(std::abs(nouveauPourcentage - 1) < 0.00001) {
        signal_pourcentage_max().emit("Le pourcentage est 100%."); //Émettre notre signal perso avec un paramètre.
    }
    
    if(nouveauPourcentage <= 1.00001) {
        barreProgression.set_fraction(nouveauPourcentage);
    }
    else {
        barreProgression.set_fraction(0);
    }
}

Fenetre::type_signal_pourcentage_moitie Fenetre::signal_pourcentage_moitie() { //Cette méthode retourne le signal.
    return signalPourcentageMoitie;
}

Fenetre::type_signal_pourcentage_max Fenetre::signal_pourcentage_max() {
    return signalPourcentageMax;
}
