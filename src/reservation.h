#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include <stdio.h>

typedef struct {
    int idReservation;           // ID de la réservation
    int id_citoyen;             // ID du citoyen
    int id_parking;             // ID du parking
    int places_reservees;       // Nombre de places réservées
    int jour, mois, annee;      // Date de la réservation
    char matricule_v[50];       // Matricule du véhicule
    char service_complementaire[100]; // Service complémentaire demandé
} reservation;

// Prototypes des fonctions
int ajouter_reservation(char *filename, reservation r);
int modifier_reservation(char *filename, int id, reservation r);
int supprimer_reservation(char *filename, int id);
reservation chercher_reservation(char *filename, int id);
void afficher_toutes_reservations(char *filename);

#endif // RESERVATION_H_INCLUDED

