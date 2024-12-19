
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

//button modifier

void
on_buttonModifierService_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget* nom, *description, *emplacement, *prix, *togglebutton1, *togglebutton2, *outputcheck, *id;

	informationsService services;
	
	//id
	id=lookup_widget(objet_graphique, "spinbuttonid");
	int idm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));

	//nom
	nom=lookup_widget(objet_graphique, "entryNomServicem");
	strcpy(services.entryNomService, gtk_entry_get_text(GTK_ENTRY(nom)));
	
	//description
	description=lookup_widget(objet_graphique, "entryDescriptionServicem");
	strcpy(services.entryDescriptionService, gtk_entry_get_text(GTK_ENTRY(description)));
	
	//emplacementCombo
	emplacement=lookup_widget(objet_graphique, "comboboxemplacementServicem");
	strcpy(services.comboboxentryemplacementService, gtk_combo_box_get_active_text(GTK_COMBO_BOX(emplacement)));

	//prixSpin
	prix=lookup_widget(objet_graphique, "spinbuttonPrixServicem");
	int price = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prix));
	services.spinbuttonPS = price;

	//radiobutton
	togglebutton1= lookup_widget(objet_graphique, "radiobuttonAgentm");
        togglebutton2= lookup_widget(objet_graphique, "radiobuttonAutom");


	if(radio==1) services.radiobuttoncat=1;
	if(radio==2) services.radiobuttoncat=2;

	//checkbox
	
	if(check==1) services.checkbuttonVal = 1;
	else services.checkbuttonVal = 0;
	modifierService( "srvc.txt", idm , services);
}

void
on_radiobuttonAgentm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) radio=1;
}


void
on_radiobuttonAutom_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) radio=1;
}

void
on_checkbuttonValm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)) check=1;
	else check=0;
}

//Supprimer

void
on_buttonSupprimerService_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	//id
	GtkWidget* id;
	id=lookup_widget(objet_graphique, "spinbuttonid");
	int idm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));

	supprimerService("srvc.text", idm);
}


void
on_buttonChercherService_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	char idstr[20];
	char spinbuttonstr[20];
	char catstr[20];
	int  idm;
	GtkWidget*idService, * nom, *description, *emplacement, *prix, *cat, * id;

	informationsService services;


	//id a chercher

	id=lookup_widget(objet_graphique, "spinbuttonid");

	idm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));
	
	services=chercherService("srvc.text", idm);

	idService=lookup_widget(objet_graphique, "labelIdService");
	sprintf(idstr, "%d", services.IdService);
	gtk_label_set_text(GTK_LABEL(idService), idstr);

	nom=lookup_widget(objet_graphique, "labelNomService");

	gtk_label_set_text(GTK_LABEL(nom), services.entryNomService);

	description=lookup_widget(objet_graphique, "labelDescriptionService");
	gtk_label_set_text(GTK_LABEL(description), services.entryDescriptionService);

	emplacement=lookup_widget(objet_graphique, "labelEmplacementService");
	gtk_label_set_text(GTK_LABEL(emplacement), services.comboboxentryemplacementService);

	prix=lookup_widget(objet_graphique, "labelPrixService");
	snprintf(spinbuttonstr, sizeof(spinbuttonstr), "%d", services.spinbuttonPS);
	gtk_label_set_text(GTK_LABEL(prix), spinbuttonstr);

	cat=lookup_widget(objet_graphique, "labelCategorieService");
	snprintf(catstr, sizeof(catstr), "%d", services.radiobuttoncat);
	gtk_label_set_text(GTK_LABEL(cat), catstr);

}


void
on_radiobuttonHomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonFemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbuttonPreference_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonSave_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonCancel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}

