#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "test_algo_structure.h"


//====================================================================
// Tableau
// Affiche le tableau
// nbel = nombre d'element dans le tableau
void affiche_tableau(int *t, int nbel) {
    int i;

    for (i = 0; i < nbel; ++i)
        printf("%d ", t[i]);
    printf("\n");
}

// A COMPLETER
// recherche un element dans un tableau
// renvoie l'indice où se trouve l'element, -1 sinon
int recherche_tableau(int *t, int nbel, int info) {
    return -1;
}

// A COMPLETER
// Ajoute un element a la fin du tableau
// Retourne le nouveau nombre d'element
int ajout_tableau(int *t, int nbel, int info) {
    return 0;
}

// A COMPLETER
// Recherche l'element info dans le tableau et le retire
// Ne fait rien si info n'est pas dans le tableau
// Retourne le nouveau nombre d'elements dans le tableau
int suppression_tableau(int *t, int nbel, int info) {
    return 0;
}

//==================================================================


// Initialise une list pour qu'elle soit vide
void init_listeSC(struct listeSC *l) {
    l->debut = NULL;
    l->fin = NULL;
}

// Libere la liste chainee
void libere_listeSC(struct listeSC *l) {
    struct maillonSC *aux = l->debut, *suivant;

    while (aux != NULL) {
        suivant = aux->suivant;
        free(aux);
        aux = suivant;
    }
}

// Affiche la liste
void affiche_listeSC(struct listeSC *l) {
    struct maillonSC *aux = l->debut;

    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->suivant;
    }
    printf("\n");
}

// A COMPLETER
// Renvoie le pointeur sur le maillon contenant l'entier info, NULL si info n'est pas present dans la liste
struct maillonSC *recherche_listeSC(struct listeSC *l, int info) {
    return NULL;
}

// A COMPLETER
// Ajoute un element a la fin de la liste
void ajout_listeSC(struct listeSC *l, int info) {
    return;
}

// A COMPLETER
// Recherche l'element info dans la liste et le retire
// Renvoie NULL si info n'est pas dans la liste
// Retourne le pointeur sur le maillon ou se trouve info
// A liberer dans le programme principal
struct maillonSC *suppression_listeSC(struct listeSC *l, int info) {
    return NULL;
}


// Initialise une list pour qu'elle soit vide
void init_listeDC(struct listeDC *l) {
    l->debut = NULL;
    l->fin = NULL;
}

// Libere la liste chainee
void libere_listeDC(struct listeDC *l) {
    struct maillonDC *aux = l->debut, *suivant;

    while (aux != NULL) {
        suivant = aux->suivant;
        free(aux);
        aux = suivant;
    }
}

// Affiche la liste
void affiche_listeDC(struct listeDC *l) {
    struct maillonDC *aux = l->debut;

    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->suivant;
    }
    printf("\n");
}

// A COMPLETER
// Renvoie le pointeur sur le maillon contenant l'entier info, NULL si info n'est pas present dans la liste
struct maillonDC *recherche_listeDC(struct listeDC *l, int info) {
    return NULL;
}

// A COMPLETER
// Ajoute un element a la fin de la liste
void ajout_listeDC(struct listeDC *l, int info) {
    return;
}

// A COMPLETER
// Recherche l'element info dans la liste et le retire
// Renvoie NULL si info n'est pas dans la liste
// Retourne le pointeur sur le maillon ou se trouve info
// A liberer dans le programme principal
struct maillonDC *suppression_listeDC(struct listeDC *l, int info) {
    return NULL;
}


