
#ifndef TPCOMPLEXITE2_LISTESC_H
#define TPCOMPLEXITE2_LISTESC_H

// Liste simplement chainee
struct maillonSC {
    int info;
    struct maillonSC *suivant;
};

struct listeSC {
    struct maillonSC *debut;
    struct maillonSC *fin;
};
int nbElementsLSC(struct listeSC *l);
// Initialise une list pour qu'elle soit vide
void init_listeSC(struct listeSC *l);
int nbElementsLSC(struct listeSC *l) ;
// Libere la liste chainee
void libere_listeSC(struct listeSC *l);
void insert_listSC(struct listeSC *l, int info, int position);
//
int rangSCinfo(struct listeSC *l, int info);
int elementAtPosSC(struct listeSC *l, int pos);
// Affiche la liste
void affiche_listeSC(struct listeSC *l);
//Ajoute un élément en début de liste
void ajout_entete_listSC(struct listeSC *l, int info);
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



#endif //TPCOMPLEXITE2_LISTESC_H
