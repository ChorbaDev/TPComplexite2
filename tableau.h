#ifndef TPCOMPLEXITE2_TABLEAU_H
#define TPCOMPLEXITE2_TABLEAU_H

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


#endif //TPCOMPLEXITE2_TABLEAU_H
