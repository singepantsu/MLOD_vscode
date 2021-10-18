#include <stdio.h>

#include "03-matrices.h"

// hypothèses :
// - res est initialisée à 0
// - matrice1 et matrice2 sont des paramètres et res est le résultat
// calcule res = matrice1*matrice2
void mult_matrice( int64_t res[5][5], int64_t matrice1[5][5], int64_t matrice2[5][5]) {
	for (uint8_t i = 0; i < 5; i++) {
		for (uint8_t j = 0; j < 5; j++) {
			for (uint8_t k = 0; k < 5; k++) {
				res[i][j] += matrice1[i][k] * matrice2[k][j];
			}
		}
	}
}

// affiche les coefficients de la matrice carré 5x5 m
void affiche_matrice(int64_t m[5][5]) {
	for (uint8_t i = 0; i < 5; i++) {
		for (uint8_t j = 0; j < 5; j++) {
			printf("%li ",m[i][j]);
		}
		printf("\n");
	}
}
