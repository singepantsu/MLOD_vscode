#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return (a == NULL);
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire depart = (Noeud*) malloc(sizeof(Noeud));
	depart->val=e;
	initialiser(&depart->filsDroit);
	initialiser(&depart->filsGauche);
	return depart;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
if (estVide(a))
	return creer(e);
ArbreBinaire copie_a = a;
	while (copie_a != NULL){
		if (copie_a->val == e)
			return a;
		if (copie_a->val>e){
			if (estVide(copie_a->filsGauche)){
				copie_a->filsGauche = creer(e);
				return a;
			}
			copie_a = copie_a->filsGauche;
		}
		if (copie_a->val<e){
			if (estVide(copie_a->filsDroit)){
				copie_a->filsDroit = creer(e);
				return a;
			}
			copie_a = copie_a->filsDroit;
		}
	}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if (estVide(a))
		return creer(e);
	if (e < a->val)
		a->filsGauche = insere_r(a->filsGauche,e);
	if (e > a->val)
		a->filsDroit = insere_r(a->filsDroit,e);
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
if (estVide(a))
	return 0;
return (1 + nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche));
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
int prof = 0;
ArbreBinaire copie_a = a;
	while (!estVide(copie_a)){
		if (copie_a->val == e)
			return prof;
		if (e<copie_a->val)
			copie_a = copie_a->filsGauche;
		if (e>copie_a->val)
			copie_a = copie_a->filsDroit;
		prof++;
	}
	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (estVide(a))
		return 0;
	if (estVide(a->filsGauche) && estVide(a->filsDroit))
		return 1;
	if (hauteur(a->filsGauche)>hauteur(a->filsDroit))
		return (1 + hauteur(a->filsGauche));
	return (1 + hauteur(a->filsDroit));
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	if (estVide(a) || a->val == elem)
		return NULL;
	ArbreBinaire fg = a->filsGauche;
	ArbreBinaire fd = a->filsDroit;
	bool test = false;
	if (!estVide(fg))
		test = (fg->val == elem);
	if (!estVide(fd))
		test = (test || (fd->val == elem));
	if (test)
		return a;
	if (elem < a->val)
		return pere(fg, elem);
	return pere(fd, elem);
}


void afficheRGD_r(ArbreBinaire a){
	if (!estVide(a)){
		printf("%i ", a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if (!estVide(a)){
		afficheGRD_r(a->filsGauche);
		printf("%i ", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if (!estVide(a)){
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%i ", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if (estVide(a))
		return NULL;
	if (estVide(a->filsGauche))
		return a;
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if (estVide(a))
		return NULL;
	if (estVide(a->filsDroit))
		return a;
	return max(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if (estVide(a))
		return NULL;
	if (a->val == elem)
		return a;
	if (elem < a->val)
		return recherche_r(a->filsGauche,elem);
	return recherche_r(a->filsDroit, elem);
}


// supprime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x){
	if (estVide(a))
		return NULL;
	if (a->val == x){
		if (estVide(a->filsDroit) && estVide(a->filsGauche))
			return NULL;
		if (estVide(a->filsDroit))
			return a->filsGauche;
		if (estVide(a->filsGauche))
			return a->filsDroit;
		Element fg_max= max(a->filsGauche)->val;
		a->val = fg_max;
		a->filsGauche = supprimer_r(a->filsGauche,fg_max);
		return a;
	}
	if(x < a->val)
		a->filsGauche = supprimer_r(a->filsGauche,x);
	if(x > a->val)
		a->filsDroit = supprimer_r(a->filsDroit,x);
	return a;
}

void detruire_r(ArbreBinaire a){
	if (!estVide(a)){
	detruire_r(a->filsGauche);
	detruire_r(a->filsDroit);
	free(a);
	}
}

