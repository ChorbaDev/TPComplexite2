#ifndef TPCOMPLEXITE2_TEST_ALGO_STRUCTURE_H
#define TPCOMPLEXITE2_TEST_ALGO_STRUCTURE_H

#define N 10
#define AFFICHETABLEAU


//====================================================================
// Tableau
// Affiche le tableau
// nbel = nombre d'element dans le tableau
void affiche_tableau(int *t, int nbel);

// A COMPLETER
// recherche un element dans un tableau
// renvoie l'indice où se trouve l'element, -1 sinon
int recherche_tableau(int *t, int nbel, int info);

// A COMPLETER
// Ajoute un element a la fin du tableau
// Retourne le nouveau nombre d'element
int ajout_tableau(int *t, int nbel, int info);

// A COMPLETER
// Recherche l'element info dans le tableau et le retire
// Ne fait rien si info n'est pas dans le tableau
// Retourne le nouveau nombre d'elements dans le tableau
int suppression_tableau(int *t, int nbel, int info);


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
void init_listeSC(struct listeSC *l);

// Libere la liste chainee
void libere_listeSC(struct listeSC *l);

// Affiche la liste
void affiche_listeSC(struct listeSC *l);

// A COMPLETER
// Renvoie le pointeur sur le maillon contenant l'entier info, NULL si info n'est pas present dans la liste
struct maillonSC *recherche_listeSC(struct listeSC *l, int info);

// A COMPLETER
// Ajoute un element a la fin de la liste
void ajout_listeSC(struct listeSC *l, int info);

// A COMPLETER
// Recherche l'element info dans la liste et le retire
// Renvoie NULL si info n'est pas dans la liste
// Retourne le pointeur sur le maillon ou se trouve info
// A liberer dans le programme principal
struct maillonSC *suppression_listeSC(struct listeSC *l, int info);

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
void init_listeDC(struct listeDC *l);

// Libere la liste chainee
void libere_listeDC(struct listeDC *l);

// Affiche la liste
void affiche_listeDC(struct listeDC *l);

// A COMPLETER
// Renvoie le pointeur sur le maillon contenant l'entier info, NULL si info n'est pas present dans la liste
struct maillonDC *recherche_listeDC(struct listeDC *l, int info);

// A COMPLETER
// Ajoute un element a la fin de la liste
void ajout_listeDC(struct listeDC *l, int info);

// A COMPLETER
// Recherche l'element info dans la liste et le retire
// Renvoie NULL si info n'est pas dans la liste
// Retourne le pointeur sur le maillon ou se trouve info
// A liberer dans le programme principal
struct maillonDC *suppression_listeDC(struct listeDC *l, int info);


#endif //TPCOMPLEXITE2_TEST_ALGO_STRUCTURE_H
