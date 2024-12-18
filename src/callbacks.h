#include <gtk/gtk.h>


void
on_buttonAjouterService_clicked        (GtkWidget       *ajout,
                                        gpointer         user_data);




void
on_radiobuttonAgent_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAuto_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonVal_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAgentm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAutom_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonModifierService_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbuttonValm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonSupprimerService_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonChercherService_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
