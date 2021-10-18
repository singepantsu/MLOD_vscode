#pragma once
#include <stdint.h>

// hypothèses :
// - res est initialisée à 0
// - matrice1 et matrice2 sont des paramètres et res est le résultat
// calcule res = matrice1*matrice2
void mult_matrice( int64_t res[5][5], int64_t matrice1[5][5], int64_t matrice2[5][5]);

// affiche les coefficients de la matrice carré 5x5 m
void affiche_matrice(int64_t m[5][5]);

