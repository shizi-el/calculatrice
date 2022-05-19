#include <iostream>
#include <math.h>
#include <string>
#include <gtkmm/builder.h>
#include "Fenetre.hpp"

#include <sstream>

using namespace std;

// Declaration des widget
Gtk::EntryBuffer* buffer;
Gtk::Entry* ecran;
// Declaration des variables
gint number, expression1, expression2, result;
char OP;
double value_enter = 0;

// Recupere la valeur saisie et retourn un string
string getValue(int g){
    value_enter = value_enter * 10 + g;

    stringstream content;
    content << value_enter;

    return content.str();
}

// La methode fenetre de la class fenetre
Fenetre::Fenetre(): container(nullptr)
{
    // On initialise l'interface utilisateur
    ui = Gtk::Builder::create_from_file("calculator.glade");
    // On connecte les signaux du UI
    gtk_builder_connect_signals(ui->gobj(),NULL);

    // On recupere le widget container de notre UI
    ui->get_widget("container",container);
    // On l'ajoute dans le widget fenetre
    add(*container);

    ui->get_widget("ecran",ecran);
    Glib::RefPtr<Gtk::EntryBuffer> buffer = ecran->get_buffer();
    // On affiche tout
    show_all();
}

extern "C" G_MODULE_EXPORT void on_btn0_clicked(Gtk::Button *btn0)
{
    // Modifie la valeur de l'ecran
    ecran->set_text(getValue(0).c_str());
}


extern "C" G_MODULE_EXPORT void on_btn1_clicked(Gtk::Button *btn1){

    ecran->set_text(getValue(1).c_str());

}

extern "C" G_MODULE_EXPORT void on_btn2_clicked(Gtk::Button *btn2){

        ecran->set_text(getValue(2).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn3_clicked(Gtk::Button *btn3){

        ecran->set_text(getValue(3).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn4_clicked(Gtk::Button *btn4){

    ecran->set_text(getValue(4).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn5_clicked(Gtk::Button *btn5){

        ecran->set_text(getValue(5).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn6_clicked(Gtk::Button *btn6){

    ecran->set_text(getValue(6).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn7_clicked(Gtk::Button *btn7){

    ecran->set_text(getValue(7).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn8_clicked(Gtk::Button *btn8){

    ecran->set_text(getValue(8).c_str());

}
extern "C" G_MODULE_EXPORT void on_btn9_clicked(Gtk::Button *btn9){

    ecran->set_text(getValue(9).c_str());

}

/* Fonction des operations */

// Addition
extern "C" G_MODULE_EXPORT void on_btnPlus_clicked(Gtk::Button *btnPlus){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    OP = '+';
    ecran->set_text("0");
    value_enter = 0;

}
// Soustraction
extern "C" G_MODULE_EXPORT void on_btnMinus_clicked(Gtk::Button *btnMinus){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    OP = '-';
    ecran->set_text("0");
    value_enter = 0;

}
// Division
extern "C" G_MODULE_EXPORT void on_btnDiv_clicked(Gtk::Button *btnDiv){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    OP = '/';
    ecran->set_text("0");
    value_enter = 0;
}
// Multiplication
extern "C" G_MODULE_EXPORT void on_btnMul_clicked(Gtk::Button *btnMul){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    OP = 'X';
    ecran->set_text("0");
    value_enter = 0;
}
// Cosinus d'un angle
extern "C" G_MODULE_EXPORT void on_btnCosx_clicked(Gtk::Button *btnCosx){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    OP = 'COSX';
    value_enter = 0;
}
// Sinus d'un angle
extern "C" G_MODULE_EXPORT void on_btnSinx_clicked(Gtk::Button *btnCosx){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    result = sin(expression1);
    string tmp = to_string(result);
    char const *result_string = tmp.c_str();
    ecran->set_text(result_string);
    value_enter = 0;
}
// Tangente d'un angle
extern "C" G_MODULE_EXPORT void on_btnTanx_clicked(Gtk::Button *btnCosx){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    result = tan(expression1);
    string tmp = to_string(result);
    char const *result_string = tmp.c_str();
    ecran->set_text(result_string);
    value_enter = 0;
}
// Ajout d'un point
extern "C" G_MODULE_EXPORT void on_btnPoint_clicked(Gtk::Button *btnCosx){

    const gchar *num = ecran->get_text().c_str();
    expression1 = atoi(num);
    value_enter = 0;

}
// Resultat
extern "C" G_MODULE_EXPORT void on_btnEqual_clicked(Gtk::Button *btnEqual)
{

    const gchar *num = ecran->get_text().c_str();
    expression2 = atoi(num);
    value_enter = 0;
    switch (OP)
    {
        case '+':
            result = expression1 + expression2;
        break;
        case '-':
            result = expression1 - expression2;
        break;
        case '/':
            result = expression1 / expression2;
        break;
        case 'X':
            result = expression1 * expression2;
        break;
        case 'COSX':
            result = cos(expression1);
        break;
    }
    string tmp = to_string(result);
    char const *result_string = tmp.c_str();
    ecran->set_text(result_string);
}
// Effacer le resultat
extern "C" G_MODULE_EXPORT void on_btnClear_clicked(Gtk::Button *btnClear)
{
    value_enter = 0;
    ecran->set_text(getValue(0).c_str());

}
// Supprime le pointer container.
Fenetre::~Fenetre()
{
    delete container;
}
