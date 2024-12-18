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
int modifierService( char * fichier, int id, informationsService nouv )
{
	int tr=0;
	informationsService services;
	FILE * f=fopen(fichier, "r");
	FILE * f2=fopen("nouv.txt", "w");
	if(f!=NULL && f2!=NULL)
	{
        	while (fscanf(f,"%d %s %s %s %d %d %d \n",&services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, &services.spinbuttonPS, &services.radiobuttoncat, &services.checkbuttonVal
			)!=EOF){
				
				if(services.IdService== id)
				{
					
		        		fprintf(f2,"%d %s %s %s %d %d %d \n", services.IdService, nouv.entryNomService, nouv.entryDescriptionService, nouv.comboboxentryemplacementService, nouv.spinbuttonPS, nouv.radiobuttoncat, nouv.checkbuttonVal);
					tr=1;
				}
				else
				{
		        		fprintf(f2,"%d %s %s %s %d %d %d \n", services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, services.spinbuttonPS, services.radiobuttoncat, services.checkbuttonVal);
				}
		}
	}
	if(EOF && services.IdService!= id){
	printf("l'ID est incorrect");	
	}
	else{
	printf("The service succesffuly Modified \n");	
	}
	fclose(f);
	fclose(f2);
	remove(fichier);
	rename("nouv.txt", fichier);
	return tr;
}



int supprimerService(char * fichier, int id)
{
	int rr=0;
	informationsService services;
	FILE * f=fopen(fichier, "r");
	FILE * f2=fopen("nouv.txt", "w");
	if(f!=NULL && f2!=NULL)
	{
		while(fscanf(f,"%d %s %s %s %d %d %d \n",&services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, &services.spinbuttonPS, &services.radiobuttoncat, &services.checkbuttonVal
			)!=EOF)
		{
		if(services.IdService!= id)
                fprintf(f2,"%d %s %s %s %d %d %d \n", services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, services.spinbuttonPS, services.radiobuttoncat, services.checkbuttonVal);
		rr=1;
		}
	}
	if(EOF && services.IdService!= id){
	printf("l'ID est incorrect");	
	}
	else{
	printf("The service succesffuly Deleted \n");	
	}
	
	fclose(f);
	fclose(f2);
	remove(fichier);
	rename("nouv.txt", fichier);
	return rr;
}

informationsService chercherService(char * fichier, int id, informationsService services)
{

	FILE * f=fopen(fichier, "r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d %s %s %s %d %d %d \n",&services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, &services.spinbuttonPS, &services.radiobuttoncat, &services.checkbuttonVal
			)!=EOF)
		{

			if(services.IdService == id){

			fclose(f);
			return services;
			}
		}
	}

	
}


