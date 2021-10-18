#include "02-convexe.h"
#include <stdio.h>

bool est_convexe(bool tab[],int length)  {
	int nbChangement = 0,i=1;

	for(i=1; nbChangement<=2 && i<length ; i++)
		if( tab[i-1] != tab[i] )
			nbChangement++;

	return nbChangement<=2;
}


int suiv(int i, int length) {
	return (i+1)%length;
}

bool est_convexe2(bool tab[],int length)  {

	int i=0;
	int indicePremierTrue;

	// on elimine les true au debut
	while(i<length && tab[i])
		i++;

	// on elimine les false
	while(i<length && !tab[i])
		i++;

	// si fin du tableau c'est convexe
	if(i==length)
		return true;

	// on a trouvé le premier true
	indicePremierTrue = i;
	i=suiv(i,length);

	// on elimine les true
	while(i!=indicePremierTrue && tab[i])
		i=suiv(i,length);

	// on elimine les false
	while(i!=indicePremierTrue && !tab[i])
		i=suiv(i,length);

	// printf("\t i=%i\n",i);

	// si on est revenu sur l'indice du 1er true on a bien eu une succession de true puis de false
	return i == indicePremierTrue;
}
