#ifndef TPCOMPLEXITE2_LISTEDC_H
#define TPCOMPLEXITE2_LISTEDC_H

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
int rangDC(struct listeDC *pDc, int info);
int rangDC2(struct listeDC *l, int pos);
int nbElementsLDC(struct listeDC *l);
// Initialise une list pour qu'elle soit vide
void init_listeDC(struct listeDC *l);

// Libere la liste chainee
void libere_listeDC(struct listeDC *l);

// Affiche la liste
void affiche_listeDC(struct listeDC *l);
void affiche_listeDCinv(struct listeDC *l);
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

#endif //TPCOMPLEXITE2_LISTEDC_H
