#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlistOfMusic.h"
/*
char* scanElement()
{
	int maxLineSize = 255;
	char c, *line = (char*) calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

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
    printf("%s,%s,%s,%s,%s,%d,%d\n",
        m->name, m->artist, m->album, m->genre, m->disk_num, m->track_num, m->year);
}

void detruireElement(Element e){
    Music *m = (Music *)e;
    free(m->name);
    free(m->artist);
    free(m->album);
    free(m->genre);
    free(m->disk_num);
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
		test = (strcmp(m1->disk_num,m2->disk_num)==0);
	if(test)
		test = (m1->track_num==m2->track_num);
	if(test)
		test = (m1->year==m2->year);
	return test;
}

Music* readMusicLine(){
    Music* m = (Music*) malloc(sizeof(Music));
    m->name     = (char*) calloc(sizeof(char),250);
    m->artist   = (char*) calloc(sizeof(char),250);
    m->genre    = (char*) calloc(sizeof(char),250);
    m->album    = (char*) calloc(sizeof(char),250);
	m->disk_num = (char*) calloc(sizeof(char),250);
    scanf("%250[^,\n],", m->name);
    scanf("%250[^,\n],", m->artist);
    scanf("%250[^,\n],", m->album);
    scanf("%250[^,\n],", m->genre);
    scanf("%250[^,\n]", m->disk_num);
    scanf(",%i,", &(m->track_num));
    scanf("%i\n",&(m->year));
    return m;
}

Liste trierLaListeParAnnee(Liste l){
	Liste l_new = creer(l->val);
	l=l->suiv;
	if(estVide(l) || estVide(l->suiv))
        return l;

	while (l!=NULL){
		l_new = ajoutTete(l->val, l_new);
		Liste l_newCopy = l_new;
		Liste l_newSuiv = l_new->suiv;
		Music *temp = (Music*)l_new->val;
		Music *tempSuiv = (Music*)l_newSuiv->val;
		while ((l_newCopy!=NULL) || (temp->year)>(tempSuiv->year)){
			Music *perm = temp;
			l_newCopy->val = perm;
			l_newSuiv->val = temp;
			l_newCopy = l_newCopy->suiv;
			l_newSuiv = l_newCopy->suiv;
			temp = (Music*)l_newCopy->val;
			tempSuiv = (Music*)l_newSuiv->val;
		}
		l = l->suiv;
	}
	return l_new;
}