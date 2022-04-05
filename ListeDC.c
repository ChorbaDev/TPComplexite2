#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "ListeDC.h"


typedef struct maillonDC maillonDC;

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

// Affiche la liste
void affiche_listeDCinv(struct listeDC *l) {
    struct maillonDC *aux = l->fin;

    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->precedent;
    }
    printf("\n");
}
// A COMPLETER
// Renvoie le pointeur sur le maillon contenant l'entier info, NULL si info n'est pas present dans la liste
struct maillonDC *recherche_listeDC(struct listeDC *l, int info) {
    struct maillonDC *aux=l->debut;
    while (aux!=NULL){
        if(aux->info==info)
            break;
        aux=aux->suivant;
    }
    return aux;
}

// A COMPLETER
// Ajoute un element a la fin de la liste
void ajout_listeDC(struct listeDC *l, int info) {
    maillonDC *nouveau =(maillonDC *) malloc(sizeof(maillonDC));
    nouveau->info = info;
    nouveau->suivant=NULL;
    nouveau->precedent=NULL;
    if(l->debut==NULL){
        l->debut=nouveau;
        l->fin=nouveau;
    }
    else{
        maillonDC *previous;
        previous=l->fin;
        l->fin->suivant=nouveau;
        l->fin=nouveau;
        l->fin->precedent=previous;
    }
}
int rangDC(struct listeDC *l, int info){
    struct maillonDC *aux=l->debut;
    int i=0;
    while (aux!=NULL){
        if(aux->info==info)
            return i;
        i++;
        aux=aux->suivant;
    }
    return -1;
}
// A COMPLETER
// Recherche l'element info dans la liste et le retire
// Renvoie NULL si info n'est pas dans la liste
// Retourne le pointeur sur le maillon ou se trouve info
// A liberer dans le programme principal
struct maillonDC *suppression_listeDC(struct listeDC *l, int info) {
    int r= rangDC(l,info);
    if(r<0)
        return NULL;
    int i;
    struct maillonDC *precedentFinal=l->debut, *suivantFinal = NULL, *maillonAsupprimer = NULL;
    if(r){
        for(i=0; i<r-1; i++)
        {
            precedentFinal = precedentFinal->suivant;
        }
        maillonAsupprimer = precedentFinal->suivant;
        suivantFinal = maillonAsupprimer->suivant;
        precedentFinal->suivant = suivantFinal;
    }else{
        maillonAsupprimer = precedentFinal;
        l->debut = precedentFinal->suivant;
    }
    return maillonAsupprimer;
}