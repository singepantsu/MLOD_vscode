#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Exercice utilisant des dates et illustrants différents modes d'allocation mémoire : statique et dynamique
 * gcc -Wall -W --std=c99 -o testDates testDates.c dates.c
 * ./dates < dates.txt
*/

// =============
// = Constantes =
// =============


// =========
// = Types =
// =========
typedef enum { janvier=1,fevrier,mars,avril,mai,juin,juillet,aout,septembre,octobre,novembre,decembre } Mois;

typedef struct {
	unsigned short jour;
	Mois mois;
	unsigned short annee;
} Date;

// =============
// = Fonctions =
// =============

bool estBissextile(short annee);

bool estDateValide(Date* d);
short nombreDejoursDansleMois(Date *d);
bool isDateValide(Date *d);
char* libelleMois(Mois m);

void afficheDate(Date *d);
void initialiseDate(Date *d);
Date creerDateParCopie();
Date* newDate();

