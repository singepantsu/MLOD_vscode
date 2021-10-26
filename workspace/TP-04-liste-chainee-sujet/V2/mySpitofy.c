//cd workspace/TP-04-liste-chainee-sujet/V2/
//gcc -W -Wall LinkedList.c mySpitofy.c linkedListOfMusic.c -o mySpitofy -g
// ./mySpitofy < music.csv > out.csv
// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy <music.csv> out.csv

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = (char*) calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}
	return line;
}

int main(void){

    char *first_line=scanLine();
    Liste l = creer(readMusicLine());
    for (long int i=0;i<2700;i++){
        l=ajoutFin_i(readMusicLine(),l);
    }
    printf("%s\n",first_line);
    afficheListe_i(l);
    detruire_i(l);
    free(first_line);
    return 0;
}