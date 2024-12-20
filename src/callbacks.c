
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


#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"

int selected = 1;
int available = 0;
agent rowSelected;


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
	
	services=chercherService("srvc.text", idm, services);

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
        if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
        {
        selected = 1;
        }
    }


void
on_radiobuttonFemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
    {
        if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
        {
        selected = 2;
        }
    }


void
on_checkbuttonPreference_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
    {
    available = gtk_toggle_button_get_active(togglebutton) ? 1 : 0;
    }


void
on_buttonSave_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
    {
        agent a;
        GtkWidget *entryNom;
        GtkWidget *entryPrenom;
        GtkWidget *entryCin;
        GtkWidget *entryNum;
        GtkWidget *output;
        GtkWidget *entryJour;
        GtkWidget *entryMois;
        GtkWidget *entryAnnee;
        GtkWidget *comboboxentryNationalite;
        GtkWidget *checkbuttonPreference;

        entryNom = lookup_widget(objet_graphique,"entryNom");
        entryPrenom = lookup_widget(objet_graphique,"entryPrenom");
        entryCin = lookup_widget(objet_graphique,"entryCin");
        entryNum = lookup_widget(objet_graphique,"entryNum");
        output = lookup_widget(objet_graphique,"labelMessage");
        entryJour=lookup_widget(objet_graphique,"spinbuttonJour");
        entryMois=lookup_widget(objet_graphique,"spinbuttonMois");
        entryAnnee=lookup_widget(objet_graphique,"spinbuttonAnnee");
        comboboxentryNationalite =lookup_widget(objet_graphique,"comboboxentryNationalite");
        checkbuttonPreference=lookup_widget(objet_graphique,"checkbuttonPreference");

                
        

        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
        a.cin = atoi(gtk_entry_get_text(GTK_ENTRY(entryCin)));
        a.numeroTelephone =atoi(gtk_entry_get_text(GTK_ENTRY(entryNum)));
        if(selected ==1 )
        {
        strcpy(a.sexe,"H"); 
        }	
        else if(selected ==2){
        strcpy(a.sexe,"F");
            }
            a.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryJour));
            a.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryMois));
            a.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryAnnee));
            a.affecte =0;
            a.id_parking=0;
            a.prefNuit=available;
        
                g_print("%s %s %s %d %d %d %d %d %d %d %s %d\n",a.nom , a.prenom ,a.sexe,a.jour, a.mois , a.annee , a.cin , a.numeroTelephone,a.affecte,a.id_parking,a.nationalite,a.prefNuit);
        strcpy(a.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryNationalite)));

        FILE * f=fopen("agent.txt", "a");
        if(f!=NULL)
        {
            int result = fprintf(f,"%s %s %s %d %d %d %d %d %d %d %s %d\n",a.nom , a.prenom ,a.sexe,a.jour, a.mois , a.annee , a.cin , a.numeroTelephone,a.affecte,a.id_parking,a.nationalite,a.prefNuit);
            if(result < 0) {
                gtk_label_set_text(GTK_LABEL(output),"erreur");
            }
            else {
                gtk_label_set_text(GTK_LABEL(output),"success");
                GtkWidget *treeview2;

        treeview2 = lookup_widget(objet_graphique,"treeview2");
        if (treeview2 != NULL) {
            // Call the function to display the agents in the treeview
            afficher_agent(treeview2);
        } else {
            g_print("treeview2 widget not found!\n");
        }
            }
            fclose(f);
        };
    }



void
on_buttonCancel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
    {
        g_print("Cancel");

    }


void on_buttonModifier_clicked(GtkWidget *objet_graphique, gpointer user_data) {
    // Déclaration des widgets
    GtkWidget *entryNom, *entryPrenom, *entryCin, *entryNum;
    GtkWidget *entryJour, *entryMois, *entryAnnee, *comboboxentryNationalite, *checkbuttonPreference;

    // Initialisation des widgets
    entryNom = lookup_widget(objet_graphique, "entryNom");
    if (!entryNom) {
        g_print("Error: Widget entryNom not found\n");
        return;
    }

    entryPrenom = lookup_widget(objet_graphique, "entryPrenom");
    if (!entryPrenom) {
        g_print("Error: Widget entryPrenom not found\n");
        return;
    }

    entryCin = lookup_widget(objet_graphique, "entryCin");
    if (!entryCin) {
        g_print("Error: Widget entryCin not found\n");
        return;
    }

    entryNum = lookup_widget(objet_graphique, "entryNum");
    if (!entryNum) {
        g_print("Error: Widget entryNum not found\n");
        return;
    }

    entryJour = lookup_widget(objet_graphique, "spinbuttonJour");
    if (!entryJour) {
        g_print("Error: Widget spinbuttonJour not found\n");
        return;
    }

    entryMois = lookup_widget(objet_graphique, "spinbuttonMois");
    if (!entryMois) {
        g_print("Error: Widget spinbuttonMois not found\n");
        return;
    }

    entryAnnee = lookup_widget(objet_graphique, "spinbuttonAnnee");
    if (!entryAnnee) {
        g_print("Error: Widget spinbuttonAnnee not found\n");
        return;
    }

    comboboxentryNationalite = lookup_widget(objet_graphique, "comboboxentryNationalite");
    if (!comboboxentryNationalite) {
        g_print("Error: Widget comboboxentryNationalite not found\n");
        return;
    }

    checkbuttonPreference = lookup_widget(objet_graphique, "checkbuttonPreference");
    if (!checkbuttonPreference) {
        g_print("Error: Widget checkbuttonPreference not found\n");
        return;
    }

    // Vérifiez que rowSelected est correctement initialisé
    if (rowSelected.nom[0] == '\0') {  // Vérification d'une valeur par défaut
        g_print("Error: rowSelected is not initialized correctly. 'nom' is empty.\n");
        return;
    }
	GtkWidget *radiobuttonHomme;
	GtkWidget *radiobuttonFemme;

	radiobuttonHomme= lookup_widget(objet_graphique,"radiobuttonHomme");
	radiobuttonFemme= lookup_widget(objet_graphique,"radiobuttonFemme");

    // Débogage : Afficher les valeurs de rowSelected avant de les affecter
    g_print("rowSelected.nom: %s\n", rowSelected.nom);
	gtk_entry_set_text(GTK_ENTRY(entryNom), rowSelected.nom);
    g_print("rowSelected.prenom: %s\n", rowSelected.prenom);
	gtk_entry_set_text(GTK_ENTRY(entryPrenom), rowSelected.prenom);
    g_print("rowSelected.cin: %d \n", rowSelected.cin);
    gtk_entry_set_text(GTK_ENTRY(entryCin), g_strdup_printf("%d", rowSelected.cin));
    g_print("rowSelected.numeroTelephone: %d\n", rowSelected.numeroTelephone);
    g_print("rowSelected.jour: %d, rowSelected.mois: %d, rowSelected.annee: %d\n",rowSelected.jour, rowSelected.mois, rowSelected.annee);
    g_print("rowSelected.prefNuit: %d\n", rowSelected.prefNuit);
    g_print("rowSelected.prefNuit: %s \n", rowSelected.nationalite);
    // Mise à jour des widgets avec les valeurs de rowSelected
    gtk_entry_set_text(GTK_ENTRY(entryNum), g_strdup_printf("%d", rowSelected.numeroTelephone));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryJour), (double)rowSelected.jour);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryMois), (double)rowSelected.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryAnnee), (double)rowSelected.annee);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbuttonPreference), rowSelected.prefNuit);
    available = rowSelected.prefNuit;
   // gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentryNationalite), rowSelected.nationalite);
	int index = 0;
	if(strcmp(rowSelected.nationalite,"Tunisien")== 0) {
		index = 0;
	}
	if(strcmp(rowSelected.nationalite,"Algérien") == 0) {
		index = 1;
	}
	if(strcmp(rowSelected.nationalite,"Français") == 0) {
		index = 2;
	}
	gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentryNationalite), index);
	if (strcmp(rowSelected.sexe, "H") == 0) {
        selected = 1;
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobuttonHomme), TRUE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobuttonFemme), FALSE);
    } else if (strcmp(rowSelected.sexe, "F") == 0) {
        selected =2;
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobuttonHomme), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobuttonFemme), TRUE);
    }
    }



void
on_buttonSupprimer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
    {
	supprimer("agent.txt",rowSelected.cin);
    GtkWidget *treeview2;

	treeview2 = lookup_widget(objet_graphique,"treeview2");
	 if (treeview2 != NULL) {
        // Call the function to display the agents in the treeview
		g_print("l9itha");
        afficher_agent(treeview2);
    } else {
        g_print("treeview2 widget not found!\n");
    }
    }


void
on_buttonAfficherAgent_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
    {
	GtkWidget *treeview2;

	treeview2 = lookup_widget(objet_graphique,"treeview2");
	 if (treeview2 != NULL) {
        // Call the function to display the agents in the treeview
		g_print("l9itha");
        afficher_agent(treeview2);
    } else {
        g_print("treeview2 widget not found!\n");
    }
    }

void on_treeview2_row_activated(GtkTreeView *treeview,
                                 GtkTreePath *path,
                                 GtkTreeViewColumn *column,
                                 gpointer user_data) {
    // Get the row index from the TreePath
    gint row_index = gtk_tree_path_get_indices(path)[0];

    // Print the selected row index for debugging
    g_print("Selected row index: %d\n", row_index);

    // Define an agent structure to store the selected row data

    // Open the file
    FILE *file = fopen("agent.txt", "r");
    if (!file) {
        g_print("Failed to open the file\n");
        return;
    }

    // Read lines from the file until the selected row index
    char line[256];  // Buffer to hold a line from the file
    int current_line = 0;

    // Loop through the file
    while (fgets(line, sizeof(line), file)) {
        if (current_line == row_index) {
            g_print("Line %d: %s", current_line + 1, line);  // Debug: print the line content

            // Parse the line and store it in the rowSelected structure
            int items_parsed = sscanf(line, "%s %s %s %d %d %d %d %d %d %d %s %d",
                                      rowSelected.nom, rowSelected.prenom, rowSelected.sexe,
                                      &rowSelected.jour, &rowSelected.mois, &rowSelected.annee,
                                      &rowSelected.cin, &rowSelected.numeroTelephone,
                                      &rowSelected.affecte, &rowSelected.id_parking,
                                      rowSelected.nationalite, &rowSelected.prefNuit);

            // Check if sscanf was successful
            if (items_parsed != 12) {
                g_print("Error: Failed to parse the line correctly.\n");
                fclose(file);
                return;
            }

            break;  // Stop after finding the selected row
        }
        current_line++;
    }

    // Close the file
    fclose(file);
    }







void
on_UpdateButton_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    GtkWidget *entryNom;
        GtkWidget *entryPrenom;
        GtkWidget *entryNum;
        GtkWidget *output;
        GtkWidget *entryJour;
        GtkWidget *entryMois;
        GtkWidget *entryAnnee;
        GtkWidget *comboboxentryNationalite;
        GtkWidget *checkbuttonPreference;

        entryNom = lookup_widget(objet_graphique,"entryNom");
        entryPrenom = lookup_widget(objet_graphique,"entryPrenom");
        entryNum = lookup_widget(objet_graphique,"entryNum");
        output = lookup_widget(objet_graphique,"labelMessage");
        entryJour=lookup_widget(objet_graphique,"spinbuttonJour");
        entryMois=lookup_widget(objet_graphique,"spinbuttonMois");
        entryAnnee=lookup_widget(objet_graphique,"spinbuttonAnnee");
        comboboxentryNationalite =lookup_widget(objet_graphique,"comboboxentryNationalite");
        checkbuttonPreference=lookup_widget(objet_graphique,"checkbuttonPreference");
        strcpy(rowSelected.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
        strcpy(rowSelected.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
        rowSelected.numeroTelephone= atoi(gtk_entry_get_text(GTK_ENTRY(entryNum)));
        if(selected ==1 )
        {
        strcpy(rowSelected.sexe,"H"); 
        }	
        else if(selected ==2){
        strcpy(rowSelected.sexe,"F");
        }
        rowSelected.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryJour));
            rowSelected.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryMois));
            rowSelected.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryAnnee));
            rowSelected.affecte =0;
            rowSelected.id_parking=0;
            rowSelected.prefNuit=available;
        strcpy(rowSelected.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryNationalite)));
        int updated = 0 ;
        updated = modifier("agent.txt",rowSelected.cin, rowSelected);
        if(updated != 0) {
            GtkWidget *treeview2;

        treeview2 = lookup_widget(objet_graphique,"treeview2");
        if (treeview2 != NULL) {
            // Call the function to display the agents in the treeview
            afficher_agent(treeview2);
        } else {
            g_print("treeview2 widget not found!\n");
        }
        }
}

