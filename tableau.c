#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "tableau.h"

//====================================================================
// Tableau
// Affiche le tableau
// nbel = nombre d'element dans le tableau
void affiche_tableau(int *t, int nbel) {
    for (int i = 0; i < nbel; ++i)
        printf("%d ", t[i]);
    printf("\n");
}

// A COMPLETER
// recherche un element dans un tableau
// renvoie l'indice où se trouve l'element, -1 sinon
int recherche_tableau(int *t, int nbel, int info) {
    for (int i = 0; i < nbel; ++i) {
        if( *(t+i)==info)
            return i;
    }
    return -1;
}

// A COMPLETER
// Ajoute un element a la fin du tableau
// Retourne le nouveau nombre d'element
int ajout_tableau(int *t, int nbel, int info) {
    *(t+nbel)=info;
    return nbel+1;
}
void ajout_entete_tableau(int *t,int nbel, int info){
    insert_tableau(t,nbel,info,1);
}
void insert_tableau(int *t,int nbel, int info, int position){
    for(int i=nbel-1;i>=position-1;i--){
        t[i+1]=t[i];
    }
    t[position-1]= info;
}
// A COMPLETER
// Recherche l'element info dans le tableau et le retire
// Ne fait rien si info n'est pas dans le tableau
// Retourne le nouveau nombre d'elements dans le tableau
int suppression_tableau(int *t, int nbel, int info) {
    int position= recherche_tableau(t,nbel,info);
    if (position==-1)
        return nbel;
    for (int i = position - 1; i < nbel - 1; i++)
        t[i] = t[i+1];
    return nbel-1;
}

