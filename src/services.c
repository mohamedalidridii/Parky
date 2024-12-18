#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "services.h"
#include "reservation.h"

int ObtenirDernierID(char *fichier) {
	informationsService services;
    	FILE *f = fopen(fichier, "r");
    	int dernierID = 0, tempID;

    	if (f != NULL) {
        	// Lire chaque ligne et extraire uniquement l'ID
        	while (fscanf(f,"%d %s %s %s %d %d %d \n",&services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, &services.spinbuttonPS, &services.radiobuttoncat, &services.checkbuttonVal
			)!=EOF) {
            	dernierID = services.IdService;
        }
        fclose(f);
    }
    return dernierID;
}

void AjouterService(char* fichier,  informationsService services)
	{
	FILE * f=fopen(fichier, "a");
    	if(f!=NULL)
    	{

		//Id Generation
		int dernierID = ObtenirDernierID(fichier);
        	services.IdService = dernierID + 1;
        	fprintf(f,"%d %s %s %s %d %d %d \n", services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, services.spinbuttonPS, services.radiobuttoncat, services.checkbuttonVal);
        	fclose(f);

    	}


}





