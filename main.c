#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
#include "tableau.h"
#include "ListeDC.h"
#include "ListeSC.h"
#define N 50
void test(int nb){
    printf("Début du programme\n");

    int i;
    float temps;
    clock_t t1, t2;

    int *tableau = malloc(nb * sizeof(int));
    for (i = 0; i < nb; i++) {
        tableau[i] = rand() % (nb * nb);
    }
    int nb_elements_de_base = nb / 2 + rand() % (nb / 3);
    printf("\nTableau:\n");

    //--------
    //version Tableau
    //--------
    int nbel = 0;
    int *t = (int *) malloc(nb_elements_de_base * sizeof(int));
    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        ajout_entete_tableau(t, i, tableau[rand() % nb]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de l'ajout pour le tableau : %f\n", temps);

#ifdef AFFICHETABLEAU
    //affiche_tableau(t, nbel);
#endif

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        recherche_tableau(t, nbel, tableau[rand() % nb]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la recherche d'un element pour le tableau : %f\n", temps);
    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        int r=tableau[rand() % nb];
        nbel = suppression_tableau(t, nbel, r);
    }
    affiche_tableau(t,nbel);
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la suppression pour le tableau : %f\n", temps);
    free(t);
    printf("\nSimplement Chaînée:\n");
    //--------
    //version Liste Simplement Chaînée
    //--------

    struct listeSC lsc;
    init_listeSC(&lsc);
    struct maillonSC *auxsc;

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        ajout_listeSC(&lsc, tableau[rand() % nb]);
    }
    t2 = clock();


    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de l'ajout pour la liste : %f\n", temps);

#ifdef AFFICHETABLEAU
    /*printf("%d\n",nbElementsLSC(&lsc));
    affiche_listeSC(&lsc);*/
#endif

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        recherche_listeSC(&lsc, tableau[rand() % nb]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la recherche pour le liste : %f\n", temps);

    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        int a = tableau[rand() % nb];
        auxsc = suppression_listeSC(&lsc, a);
        if (auxsc != NULL) free(auxsc);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la suppression pour le liste : %f\n", temps);
    libere_listeSC(&lsc);
    printf("\nDoublement Chaînée:\n");
    //--------
    //version Liste Doublement Chaînée
    //--------
    struct listeDC ldc;
    init_listeDC(&ldc);
    struct maillonDC *auxdc;
    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        ajout_listeDC(&ldc, tableau[rand() % nb]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de l'ajout pour la liste : %f\n", temps);

#ifdef AFFICHETABLEAU
    //   affiche_structure(...);
#endif
    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        recherche_listeDC(&ldc, tableau[rand() % nb]);
    }
    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la recherche pour le liste : %f\n", temps);
    t1 = clock();
    for (i = 0; i < nb_elements_de_base; i++) {
        auxdc = suppression_listeDC(&ldc, tableau[rand() % nb]);

        if (auxdc != NULL) free(auxdc);
    }

    t2 = clock();
    temps = (float) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps de la suppression pour le liste : %f\n", temps);

    libere_listeDC(&ldc);

    free(tableau);
}

int main(int argc, char *argv[]) {
    for(int i = 10; i<N;i++){
        printf("iteration %d\n",i);
        test(i);
    }
}

