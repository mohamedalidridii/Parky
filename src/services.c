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
			if(services.IdService!= id){
                	fprintf(f2,"%d %s %s %s %d %d %d \n", services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, services.spinbuttonPS, services.radiobuttoncat, services.checkbuttonVal);
			rr=1;
			}
			else{
			 rr=0;
			}
		}
	}
	fclose(f);
	fclose(f2);
	remove(fichier);
	rename("nouv.txt", fichier);
	return rr;
}

informationsService chercherService(char * fichier, int id)
{

informationsService services;

	FILE * f=fopen(fichier, "r");

	if(f!=NULL)
	{
		while(fscanf(f,"%d %s %s %s %d %d %d \n",&services.IdService, services.entryNomService, services.entryDescriptionService, services.comboboxentryemplacementService, &services.spinbuttonPS, &services.radiobuttoncat, &services.checkbuttonVal
			)!=EOF)
		{

			if(services.IdService == id){

			return services;
			}
		}
	fclose(f);
	}

	return services;
}

int affecter_service( char * fichier, char * fichier1,  int id_res, int id_sc)
{
    int trs = 0;
    int trp = 0;

    reservation p; 
    informationsService s;

    FILE * f=fopen(fichier, "r");
    FILE * f2=fopen(fichier1, "r");
    FILE * f3=fopen("nouv.txt", "a");
	printf("begging\n");
    if(f!=NULL && f2!=NULL && f3!=NULL)
    {
	printf("after null\n");
	while(fscanf(f,"%d %s %s %s %d %d %d\n",&s.IdService, s.entryNomService, s.entryDescriptionService, s.comboboxentryemplacementService, &s.spinbuttonPS, 			&s.radiobuttoncat, &s.checkbuttonVal)!=EOF)
        {	printf("after while\n");
		if(s.IdService == id_sc){
			while(fscanf(f2,"%d %d %d %d %d %d %d %s %d \n ",&p.idReservation, &p.id_citoyen, &p.id_parking, &p.places_reservees, &p.jour, &p.mois, &p.annee, p.matricule_v, 			&p.service_complementaire)!=EOF){
				printf("after while f\n");
         			if(p.idReservation != id_res){
					fprintf(f3,"%d %d %d %d %d %d %d %s %d\n",p.idReservation, p.id_citoyen, p.id_parking, p.places_reservees, p.jour, p.mois, p.annee, 						p.matricule_v, 	p.service_complementaire);
					
				}	
				else{
					printf("p.idReservation == id_res && s.IdService = id_sc is OK\n");

					fprintf(f3,"%d %d %d %d %d %d %d %s %d\n",p.idReservation, p.id_citoyen, p.id_parking, p.places_reservees, p.jour, p.mois, p.annee, 							p.matricule_v, 	id_sc);	
					
				}
	
			}
		}
	}
	fclose(f);
    	fclose(f2); 
	fclose(f3); 
	remove(fichier1);
	rename("nouv.txt", fichier1);
    }
	return 0;
}

