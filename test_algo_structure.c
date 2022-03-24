#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>

#define N 10
#define AFFICHETABLEAU

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
// Liste simplement chainee
struct maillonSC {
    int info;
    struct maillonSC *suivant;
};

struct listeSC {
    struct maillonSC *debut;
    struct maillonSC *fin;
};

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

//==================================================================
// Liste doublement chainee
struct maillonDC {
    int info;
    struct maillonDC *suivant;
    struct maillonDC *precedent;
};

struct listeDC {
    struct maillonDC *debut;
    struct maillonDC *fin;
};

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

// =================================================================
int main(int argc, char *argv[]) {
    printf("Début du programme\n");

    int i;
    float temps;
    clock_t t1, t2;

    int *tableau = malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        tableau[i] = rand() % (N * N);
    }

    int nb_elements_de_base = N / 2 + rand() % (N / 3);

    //--------
    //version Tableau
    //--------
    int nbel = 0;
    int *t = (int *) malloc(nb_elements_de_base * sizeof(int));

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        nbel = ajout_tableau(t, nbel, tableau[rand() % N]);
    }

    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de l'ajout pour le tableau : %f\n", temps);

#ifdef AFFICHETABLEAU
    //affiche_tableau(t, nbel);
#endif

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        recherche_tableau(t, nbel, tableau[rand() % N]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la recherche d'un element pour le tableau : %f\n", temps);

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        nbel = suppression_tableau(t, nbel, tableau[rand() % N]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la suppression pour le tableau : %f\n", temps);

    free(t);

    //--------
    //version Liste Simplement Chaînée
    //--------
    struct listeSC lsc;
    init_listeSC(&lsc);
    struct maillonSC *auxsc;

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        ajout_listeSC(&lsc, tableau[rand() % N]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de l'ajout pour la liste : %f\n", temps);

#ifdef AFFICHETABLEAU
    //   affiche_structure(...);
#endif

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        recherche_listeSC(&lsc, tableau[rand() % N]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la recherche pour le liste : %f\n", temps);


    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        auxsc = suppression_listeSC(&lsc, tableau[rand() % N]);
        if (auxsc != NULL) free(auxsc);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la suppression pour le liste : %f\n", temps);

    libere_listeSC(&lsc);

    //--------
    //version Liste Doublement Chaînée
    //--------
    struct listeDC ldc;
    init_listeDC(&ldc);
    struct maillonDC *auxdc;

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        ajout_listeDC(&ldc, tableau[rand() % N]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de l'ajout pour la liste : %f\n", temps);

#ifdef AFFICHETABLEAU
//   affiche_structure(...);
#endif

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        recherche_listeDC(&ldc, tableau[rand() % N]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la recherche pour le liste : %f\n", temps);


    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        auxdc = suppression_listeDC(&ldc, tableau[rand() % N]);
        if (auxdc != NULL) free(auxdc);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la suppression pour le liste : %f\n", temps);

    libere_listeDC(&ldc);

    free(tableau);
}

