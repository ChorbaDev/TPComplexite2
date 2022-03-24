#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "ListeDC.h"


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
