#include <gtkmm/main.h>

#include "fenetre.hpp"

int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Fenetre fenetre;
    Gtk::Main::run(fenetre);
    return 0;
}
