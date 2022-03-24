#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "test_algo_structure.h"

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
