#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "ListeSC.h"


typedef struct maillonSC maillonSC;

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
    maillonSC *aux=l->debut;
    while (aux!=NULL){
       if(aux->info==info)
           break;
        aux=aux->suivant;
    }
    return aux;
}
int nbElementsLSC(struct listeSC *l) {
    maillonSC *aux=l->debut;
    int i=0;
    while (aux!=NULL){
        i++;
        aux=aux->suivant;
    }
    return i;
}

// A COMPLETER
// Ajoute un element a la fin de la liste
void ajout_listeSC(struct listeSC *l, int info) {
    maillonSC *new =(maillonSC *) malloc(sizeof(maillonSC));
    new->info = info;
    new->suivant = NULL;
    if(l->debut==NULL){
        l->debut=new;
        l->fin=new;
    }
    else{
        l->fin->suivant=new;
        l->fin=new;
    }
}

int rangSCinfo(struct listeSC *l, int info){
    struct maillonSC *aux=l->debut;
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

struct maillonSC *suppression_listeSC(struct listeSC *l, int info) {
    int r = rangSCinfo(l, info);
    if (r < 0)
        return NULL;
    maillonSC *precedentFinal = l->debut, *suivantFinal = NULL, *maillonAsupprimer = NULL;
    if (r) {
        for (int i = 0; i < r - 1; i++) {
            precedentFinal = precedentFinal->suivant;
        }
        maillonAsupprimer = precedentFinal->suivant;
        suivantFinal = maillonAsupprimer->suivant;
        precedentFinal->suivant = suivantFinal;
    } else {
        maillonAsupprimer = precedentFinal;
        l->debut = precedentFinal->suivant;
    }
    return maillonAsupprimer;
}

int elementAtPosSC(struct listeSC *l, int pos) {
    struct maillonSC *aux = l->debut;
    for (int i = 0; i < pos; ++i) {
        aux = aux->suivant;
    }
    return aux->info;
}

//Ajoute un ??l??ment en d??but de liste
void ajout_entete_listSC(struct listeSC *l, int info) {
    maillonSC *new = (maillonSC *) malloc(sizeof(maillonSC));
    new->info = info;
    new->suivant = NULL;
    if (l->debut == NULL) {
        l->debut = new;
        l->fin = new;
    }  else {
        new->suivant = l->debut;
        l->debut = new;
    }
}

void insert_listSC(struct listeSC *l, int info, int position) {
    if (l->debut==NULL || position<=0){
        ajout_entete_listSC(l,info);
    }else if(position>nbElementsLSC(l)){
        ajout_listeSC(l,info);
    }else{
        maillonSC *current= l->debut,*new= (maillonSC *) malloc(sizeof(maillonSC));
        new->info=info;
        new->suivant=NULL;
        for (int i = 1; i <position ; ++i) {
            current=current->suivant;
        }
        new->suivant=current->suivant;
        current->suivant=new;
    }
}