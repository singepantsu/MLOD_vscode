#include <stdlib.h>

#include "03-matrices.h"

int main(void) {
	//matrices en ligne * colonne
   	int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
   	int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
   	int64_t matriceResultat[5][5] = {{0}};

	mult_matrice(matriceResultat,matrice1,matrice2);
	affiche_matrice(matriceResultat);

	return EXIT_SUCCESS;
}