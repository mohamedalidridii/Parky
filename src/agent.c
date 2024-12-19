#include "agent.h"

enum {
    NOM,
    PRENOM,
    CIN,
    JOUR,
    MOIS,
    ANNEE,
    AFFECTE,
    ID_PARKING,
    SEXE,
    NATIONALITE,
    NUMEROTELEPHONE,
    PREFNUIT,
    COLUMNS
};
int Menu() {
    int choix;
  
    printf("\n Faite votre choix\n");
    printf("1-Ajouter un agent\n");
    printf("2-modifier un agent\n");
    printf("3-supprimer un agent\n");
    printf("4-chercher et afficher une reservation");
    scanf("%d",&choix);
        return choix;
    }

void saisir(agent *a){
printf("donnez le nom de l'agent \n");
scanf("%s",&(*a).nom);

printf("donnez le prenom de l'agent \n");
scanf("%s",&(*a).prenom);
printf("donnez le sexe de l'agent \n");
scanf("%s",&(*a).sexe);

printf("donnez le jour de naissance de l'agent \n");
scanf("%d",&(*a).jour);
printf("donnez le mois de naissance de l'agent \n");
scanf("%d",&(*a).mois);
printf("donnez l'annee de naissance de l'agent \n");
scanf("%d",&(*a).annee);

printf("donnez le cin de l'agent \n");
scanf("%d",&(*a).cin);

printf("donnez le numero de telephone de l'agent \n");
scanf("%d",&(*a).numeroTelephone);

printf("donnez la nationalite de l'agent \n");
scanf("%s",&(*a).nationalite);
a->affecte=0;
a->id_parking =0;
}
void setup_treeview_columns(GtkWidget *treeview) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;

    // Column for "Nom"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Prenom"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "CIN"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", CIN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Jour"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOUR, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Mois"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOIS, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Annee"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Sexe"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", SEXE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "NumeroTelephone"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Numero Telephone", renderer, "text", NUMEROTELEPHONE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Affecte"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Affecte", renderer, "text", AFFECTE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "ID Parking"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("ID Parking", renderer, "text", ID_PARKING, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "Nationalite"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nationalite", renderer, "text", NATIONALITE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    // Column for "PrefNuit"
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Pref Nuit", renderer, "text", PREFNUIT, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
}

void afficher_agent(GtkWidget *liste) {
    GtkTreeIter iter;
    GtkListStore *store;
    char nom[30], prenom[30], sexe[30], jour[30], mois[30], annee[30], cin[30], numeroTelephone[30], affecte[30], id_parking[30], nationalite[30], prefNuit[30];
    FILE *f;

    // Get the existing model from the TreeView
    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

    // If the store is NULL, create it
    if (store == NULL) {
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);  // Unref store when done
    }

    // Open the file and check how many rows are already present in the model
    f = fopen("agent.txt", "r");
    if (f == NULL) {
        g_print("Error opening file\n");
        return;
    }
    setup_treeview_columns(liste);
    // Count the number of existing rows in the model
    int row_count = gtk_tree_model_iter_n_children(GTK_TREE_MODEL(store), NULL);

    // Skip rows in the file that have already been added to the treeview
    for (int i = 0; i < row_count; i++) {
        // Read and discard data for the existing rows
        fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s", prenom, nom, sexe, jour, mois, annee, cin, numeroTelephone, affecte, id_parking, nationalite, prefNuit);
    }

    // Add new rows from the file
    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s", prenom, nom, sexe, jour, mois, annee, cin, numeroTelephone, affecte, id_parking, nationalite, prefNuit) != EOF) {
        g_print("Read agent data: %s %s %s %s %s %s %s %s %s %s %s %s\n", prenom, nom, sexe, jour, mois, annee, cin, numeroTelephone, affecte, id_parking, nationalite, prefNuit);
        
        // Append new data to the treeview
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
                           PRENOM, prenom, NOM, nom, SEXE, sexe,
                           JOUR, jour, MOIS, mois, ANNEE, annee,
                           CIN, cin, NUMEROTELEPHONE, numeroTelephone,
                           AFFECTE, affecte, ID_PARKING, id_parking,
                           NATIONALITE, nationalite, PREFNUIT, prefNuit, -1);
    }

    fclose(f);  // Close file after reading

    // Queue a redraw of the treeview
    gtk_widget_queue_draw(liste);
}




void affecterParking(char * filename, int id_parking,int id) {

    agent nouveauA;
  
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "a");
    if(f!=NULL && f2!=NULL)
    {
       while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %s \n",&nouveauA.nom , &nouveauA.prenom ,&nouveauA.sexe,&nouveauA.jour, &nouveauA.mois , &nouveauA.annee , &nouveauA.cin , &nouveauA.numeroTelephone,&nouveauA.affecte,&nouveauA.id_parking ,&nouveauA.nationalite)!=EOF)
        {
            if(nouveauA.cin== id)
            {
		nouveauA.affecte = 1;
		nouveauA.id_parking = id_parking;
                fprintf(f2,"%s %s %s %d %d %d %d %d %d %s \n",nouveauA.nom ,nouveauA.prenom ,nouveauA.sexe, nouveauA.jour, nouveauA.mois , nouveauA.annee , nouveauA.cin , nouveauA.numeroTelephone,nouveauA.affecte,nouveauA.id_parking,nouveauA.nationalite);
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %d %d %d %s \n",nouveauA.nom , nouveauA.prenom ,nouveauA.sexe, nouveauA.jour, nouveauA.mois , nouveauA.annee , nouveauA.cin , nouveauA.numeroTelephone,nouveauA.affecte,nouveauA.id_parking,nouveauA.nationalite);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
}

void AjouterAgent(char * filename, agent a )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %d %d %d %d %s \n",a.nom , a.prenom ,a.sexe,a.jour, a.mois , a.annee , a.cin , a.numeroTelephone,a.affecte,a.id_parking,a.nationalite);
        fclose(f);

    }

}

void supprimer(char *filename, int numeroAcomparer ){

    agent nouveauA;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "a");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s \n",&nouveauA.nom , &nouveauA.prenom, &nouveauA.sexe , &nouveauA.jour, &nouveauA.mois , &nouveauA.annee , &nouveauA.cin , &nouveauA.numeroTelephone,&nouveauA.affecte,&nouveauA.id_parking,&nouveauA.nationalite)!=EOF)
        {
            if(nouveauA.cin!= numeroAcomparer)
               fprintf(f2,"%s %s %s %d %d %d %d %d %d %s \n",nouveauA.nom , nouveauA.prenom,nouveauA.sexe , nouveauA.jour, nouveauA.mois , nouveauA.annee , nouveauA.cin , nouveauA.numeroTelephone,nouveauA.affecte,nouveauA.id_parking,nouveauA.nationalite);
                
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);

}
agent chercher(char * filename, int numeroAcomparer)
{
    agent nouveauA;
    int tr=0;
    FILE * f=fopen(filename, "r");

    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %d %d %d %d %d %d %d %s \n",&nouveauA.nom , &nouveauA.prenom,&nouveauA.sexe , &nouveauA.jour, &nouveauA.mois , &nouveauA.annee , &nouveauA.cin , &nouveauA.numeroTelephone,&nouveauA.affecte,&nouveauA.id_parking, &nouveauA.nationalite)!=EOF)
        {
            if(nouveauA.cin == numeroAcomparer ) {
    		fclose(f);
                return nouveauA;
        }
	else {
	     nouveauA.cin=0;
    return nouveauA;		
	}
    }


}
}

int modifier( char * filename, int id )
{
    int modificationFaite=0;
    agent nouveauA,b;
  
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "a");
    if(f!=NULL && f2!=NULL)
    {
       while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s \n",&nouveauA.nom , &nouveauA.prenom ,&nouveauA.sexe, &nouveauA.jour, &nouveauA.mois , &nouveauA.annee , &nouveauA.cin , &nouveauA.numeroTelephone,&nouveauA.affecte,&nouveauA.nationalite)!=EOF)
        {
            if(nouveauA.cin== id)
            {
		saisir(&b);
                fprintf(f2,"%s %s %s %d %d %d %d %d %d %s \n",b.nom , b.prenom ,b.sexe, b.jour, b.mois , b.annee , nouveauA.cin , b.numeroTelephone,b.affecte,b.nationalite);
                modificationFaite=1;
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %d %d %s \n",nouveauA.nom , nouveauA.prenom, nouveauA.sexe , nouveauA.jour, nouveauA.mois , nouveauA.annee , nouveauA.cin , nouveauA.numeroTelephone,nouveauA.affecte,nouveauA.nationalite);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return modificationFaite;

}


