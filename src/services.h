#ifndef FONCTION_ADD_H
#define FONCTION_ADD_H

typedef struct{
	int  IdService;
	char entryNomService[100];
	char entryDescriptionService[100];
	char comboboxentryemplacementService[100];
	int  spinbuttonPS;
	int  radiobuttoncat;
	int  checkbuttonVal;
	}informationsService;


	void AjouterService(char * fichier, informationsService services);
	int modifierService( char* fichier, int id, informationsService nouv );
	int supprimerService(char* fichier, int id);
	int chercherService(char * fichier, int id);
	int AfficherService(char * fichier);
	int affecterServiceCitoyen (char *fichierCitoyen, char *fichierServices, char *fichierAffectations,  int idServiceA, int idCitoyenA);
	
	int affecterServiceReservation(char* fichierReservation, char* fichierService, char* fichierAffectationsReservation);
	//int compterService(char * Affectations);
#endif

