#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#include<stdio.h>
#include <gtk/gtk.h>
typedef struct {
    char nom[10];
    char prenom[10];
    char sexe[10];
    int jour,mois,annee;
    int cin;
    int numeroTelephone;
    int affecte;
    int id_parking;
    char nationalite[20];
    int prefNuit;
}agent;
void saisir (agent *a);
void AjouterAgent (char *fichier, agent a);
int modifier( char *fichier, int id,agent b);
void supprimer(char *fichier, int id );
agent chercher(char *fichier, int id);
void afficher_agent(GtkWidget *liste);
int menu();

#endif // AGENT_H_INCLUDED

