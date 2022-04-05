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
    struct maillonSC *aux=l->debut;
    while (aux!=NULL){
       if(aux->info==info)
           break;
        aux=aux->suivant;
    }
    return aux;
}
int nbElementsLSC(struct listeSC *l) {
    struct maillonSC *aux=l->debut;
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
    maillonSC *nouveau =(maillonSC *) malloc(sizeof(maillonSC));
    nouveau->info = info;
    nouveau->suivant = NULL;
    if(l->debut==NULL){
        l->debut=nouveau;
        l->fin=nouveau;
    }
    else{
        l->fin->suivant=nouveau;
        l->fin=nouveau;
    }
}
/*
 *         printf("2");
        maillonSC *courant = l->debut, *dernier = NULL;
        while(courant != NULL)
        {
            dernier = courant;
            courant = courant->suivant;
        }
        dernier->suivant = nouveau;
 * */
int rangSC(struct listeSC *l, int info){
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

    int r= rangSC(l,info);
    if(r<0)
        return NULL;
    int i;
    struct maillonSC *precedentFinal=l->debut, *suivantFinal = NULL, *maillonAsupprimer = NULL;
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
/*
 *
    maillonSC *pointer=l->debut,*current=pointer,*next=NULL,*previous=NULL;
    while (pointer!=NULL){
        if(pointer->suivant->info==info){
            previous=pointer;
            current=pointer->suivant;
            next=current->suivant;
            break;
        }
        pointer=pointer->suivant;
    }
    previous->suivant=next;
    return current;
 */