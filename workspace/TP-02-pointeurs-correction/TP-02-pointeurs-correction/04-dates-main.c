#include "04-dates.h"

// ========
// = Main =
// ========

int main(void){

	Date d;

	printf("version 1 : intialisation d'une date allouée statiquement\n");
	initialiseDate(&d);
	afficheDate(&d);

	printf("\nversion 2 : recopie d'une date allouée statiquement\n");
	d = creerDateParCopie();
	afficheDate(&d);

	printf("\nversion 3 : allocation dynamique de date\n");
	Date *pDate;
	pDate = newDate();
	afficheDate(pDate);
	free(pDate);


	printf("\nversion 3.1 : allocation dynamique d'un tableau de date\nCette derniere version sera celle à privilégier notament dans les prochains TD sur les matrices ou les listes\n");
	int nbDates;
	printf("Entrer le nombre de dates à saisir : ");
	scanf("%i",&nbDates);
	Date *tabDate[nbDates]; // C99 only, automatic allocation on the stack
	int i;
	for(i=0; i<nbDates ; i++)
		tabDate[i] = newDate();

	for(i=0; i<nbDates ; i++)
		afficheDate(tabDate[i]);

	for(i=0; i<nbDates ; i++)
		free(tabDate[i]);	// toute adresse obtenue via malloc ou calloc doit être libérée avec free

	return EXIT_SUCCESS;
}