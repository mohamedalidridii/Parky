
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "services.h"
#include <stdio.h>
#include <stdlib.h>



int radio=1;
int check=0;

void
on_buttonAjouterService_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget* nom, *description, *emplacement, *prix, *togglebutton1, *togglebutton2, *outputcheck;

	informationsService services;

	
	//nom
	nom=lookup_widget(objet_graphique, "entryNomService");
	strcpy(services.entryNomService, gtk_entry_get_text(GTK_ENTRY(nom)));
	
	//description
	description=lookup_widget(objet_graphique, "entryDescriptionService");
	strcpy(services.entryDescriptionService, gtk_entry_get_text(GTK_ENTRY(description)));
	
	//emplacementCombo
	emplacement=lookup_widget(objet_graphique, "comboboxemplacementService");
	strcpy(services.comboboxentryemplacementService, gtk_combo_box_get_active_text(GTK_COMBO_BOX(emplacement)));

	//prixSpin
	prix=lookup_widget(objet_graphique, "spinbuttonPrixService");
	int price = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prix));
	services.spinbuttonPS = price;

	//radiobutton
	togglebutton1= lookup_widget(objet_graphique, "radiobuttonAgent");
        togglebutton2= lookup_widget(objet_graphique, "radiobuttonAuto");


	if(radio==1) services.radiobuttoncat=1;
	if(radio==2) services.radiobuttoncat=2;

	//checkbox
	
	if(check==1) services.checkbuttonVal = 1;
	else services.checkbuttonVal = 0;
	AjouterService("srvc.txt", services);


}

void
on_radiobuttonAgent_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) radio=1;
}
void
on_radiobuttonAuto_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) radio=2;
}
void
on_checkbuttonVal_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) check=1;
	else check=0;
}
