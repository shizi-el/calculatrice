#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm/applicationWindow.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/table.h>
#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>


// Ceci est la class fentre
class Fenetre: public Gtk::ApplicationWindow
{
public:
    // La methode de la class
    Fenetre();
    ~Fenetre();
protected:
    Glib::RefPtr<Gtk::Builder> ui;

private:
    // Conteneur vertical comme widget enfant
    Gtk::Box* container;



};
#endif // DEF_FENETRE
