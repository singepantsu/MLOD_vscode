#include "04-dates.h"

// =============
// = Fonctions =
// =============

bool estBissextile(short annee) {		
	return (annee%400==0) || ((annee%4==0) && (annee%100!=0));
}

short nombreDejoursDansleMois(Date *d) {
	const unsigned short nombreDeJoursParMois [] = {  31, 28, 31,
									 		 		30, 31, 30,
													31, 31, 30,
							 	 			   		31, 30, 31};
    if(estBissextile(d->annee) && (d->mois==fevrier))
		return 29;
	 
	return nombreDeJoursParMois[d->mois-1];	
}

bool estDateValide(Date *d) {	
	return (d!=NULL) &&
			(d->mois>=1) && 
			(d->mois<=12) &&
			d->jour>0 &&
			d->jour<=nombreDejoursDansleMois(d); 
}

// retourne la chaine de caractère représentant m
char* libelleMois(Mois m) {
	char* nomsDesMois [] = { "Janvier",
					 		 "Fevrier",
							 "Mars",
			 	 			 "Avril",
                      "Mai",
							 "Juin",
					       "Juillet",
					       "Août",
					       "Septembre",
					       "Octobre",
					       "Novembre",
					       "Décembre" };
    return nomsDesMois[m-1];
}

void afficheDate(Date* d) {
	printf("%i %s %i\n", d->jour,libelleMois(d->mois),d->annee);
}

// initialise la date d dont l'adresse est passée en paramtère
// Attention : d doit être alllouée préalablement
void initialiseDate(Date * d) {
	bool dValide = false;

	do {
		printf("jour : ");
		scanf("%hu",&(d->jour));
		printf("mois : ");
		scanf("%d",(int *)&d->mois);
		printf("annee : ");
		scanf("%hu",&d->annee);

		if(!(dValide=estDateValide(d))) {
			printf("\t date invalide!");
			afficheDate(d);
		}

	} while( !dValide );
}

// retourne une date initialisée par copie
Date creerDateParCopie() {
	Date d;
	initialiseDate(&d);
	return d;
}

// Alloue dynamiquement une date, l'initialise et retourne son adresse
Date* newDate() {
	Date* d = (Date*)malloc(sizeof(Date));	
	initialiseDate(d);
	return d;
}
