#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlistOfMusic.h"
/*
char* scanElement()
{
	int maxLineSize = 255;
	char c, *line = (char*) calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^,]", line);

	if ( (c = getchar()) != ',') {
		//we did not get all the line 
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != ',') && c != EOF) ;
	}

	return line;
}
*/
void afficheElement(Element e){
    Music *m = (Music *)e;
    printf("%s,%s,%s,%s,%d,%d,%d\n",
        m->name, m->artist, m->album, m->genre, m->disk_num, m->track_num, m->year);
}

void detruireElement(Element e){
    Music *m = (Music *)e;
    free(m);
}

bool equalsElement(Element e1, Element e2){
	Music *m1 = (Music*) e1;
    Music *m2 = (Music*) e2;
	bool test = (strcmp(m1->name,m2->name)==0);
	if(test)
		test = (strcmp(m1->artist,m2->artist)==0);
	if(test)
		test = (strcmp(m1->album,m2->album)==0);
	if(test)
		test = (strcmp(m1->genre,m2->genre)==0);
	if(test)
		test = (m1->disk_num==m2->disk_num);
	if(test)
		test = (m1->track_num==m2->track_num);
	if(test)
		test = (m1->year==m2->year);
	return test;
}

Music* readMusicLine(){
    Music* m =(Music*) malloc(sizeof(Music));
    /*Prototype en projet:
    int buf;
    char *str = (char*) calloc(1,sizeof(char)); 
    m->name = scanf("%20s,", &str);
    m->artist = scanf("%20s,", &str);
    m->album = scanf("%20s,", &str);
    m->genre = scanf("%20s,", &str);
	m->disk_num = scanf("%i,", &buf);
    m->track_num = scanf("%i,", &buf);
    m->year = scanf("%i\n",&buf);
    free(str);
    */
   scanf("%40s,", m->name);
   scanf("%40s,", m->artist);
   scanf("%40s,", m->album);
   scanf("%40s,", m->genre);
   scanf("%i,", &(m->disk_num));
   scanf("%i,", &(m->track_num));
   scanf("%i\n",&(m->year));
    return m;
}