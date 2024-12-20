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

void
on_radiobuttonHomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonPreference_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonSave_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonCancel_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAfficherAgent_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_UpdateButton_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
