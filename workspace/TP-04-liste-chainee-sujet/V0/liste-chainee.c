#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = (Liste) malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste n = creer(v);
	n->suiv = l;
	return n;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste l_copy = l;
	while (!estVide(l_copy)){
		afficheElement(l_copy->val);
		l_copy=l_copy->suiv;
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if (l != NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e);

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	while (!estVide(l)){
		detruireElement(l->val); //noyau central de la fonction
		Cellule* next=l->suiv;
		free(l);
		l=next;
	}
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l)){
		detruireElement(l->val);
		detruire_r(l->suiv);
	}
	free(l);
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste l_copy;
	Liste cell_fin = creer(v);
	l_copy = l->suiv;
	while (!estVide(l_copy)){
		l_copy=l_copy->suiv;
	}
	*l_copy = cell_fin;
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (estVide(l)){
		return creer(v);
	}
	else{
		Cellule* cell =(Cellule*) malloc(sizeof(Cellule));
		cell->val = l->val;
		cell->suiv = ajoutFin_r(v, l->suiv);
		return cell;
	}
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste l_copy;
	l_copy = l;
	while (equalsElement(l_copy->val, v)  && !estVide(l_copy)){
		l_copy = l_copy->suiv;
	}
	return l_copy;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (equalsElement(l->val,v) || estVide(l)){
		return l;
	}
	return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste l_copy = cherche_i(v,l);
	return TODO;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (l->val )
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



