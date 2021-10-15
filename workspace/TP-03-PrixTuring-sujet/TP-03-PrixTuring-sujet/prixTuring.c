/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

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

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}
struct winTuring{
	int year;
	char *name;
	char* why;

};
typedef struct winTuring WinTuring;

// MON TRUC FOIREUX:
void readWinners(WinTuring **win, int n_ligne)
{
	*win = calloc(n_ligne,fmax(sizeof(char),sizeof(int)));
	for (int i=0;i<n_ligne;i++){
	(*win)[i].year=scanLineAsInt();
	(*win)[i].name=scanLine();
	(*win)[i].why=scanLine();
	}
	//if (scanLineAsInt() != 0)
	//{
	//	win->i=scanLineAsInt();
	//}
}

void printWinners(WinTuring **win ,int nb){
	for (int i=0;i<nb;i++){
		printf("%i \n %s \n %s \n",(*win)[i].year,(*win)[i].name,(*win)[i].why);
	}
}

int main(void)
{
	WinTuring *Win;
	int n_l = scanLineAsInt();
	readWinners(&Win, n_l);
	printWinners(&Win, n_l);

/*  Pour l'exp.:
	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);

	int winnerYear = scanLineAsInt();
	printf("winnerYear = %i\n",winnerYear);

	char *winnerName = scanLine();
	printf("WinnerName = %s\n",winnerName);

	return EXIT_SUCCESS;*/
}
