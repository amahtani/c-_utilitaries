#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <string>

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Fenetre : public Gtk::Window {
    public :
        Fenetre();
    
    private :
        Gtk::Button bouton;
};

#endif
