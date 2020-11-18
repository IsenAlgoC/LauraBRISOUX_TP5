#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100





/* Creation du type tableau */
typedef struct Tableau
{
    int* elt;// le tableau d’entiers
    int size;// la taille de ce tableau d’entiers
    int eltsCount;// le nombre d’éléments dans le tableau
}TABLEAU;
TABLEAU NewArray();
int IncrementArraySize(TABLEAU* tab, int IncrementValue);
int SetElement(TABLEAU* tab, int pos, int Element);
int DisplayElements(TABLEAU* tab, int StartPos, int EndPos);
int DeleteElements(TABLEAU* tab, int StartPos, int EndPos);





/* Fonction de creation de tableau */
TABLEAU NewArray() {
    TABLEAU tableau;
    tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
    tableau.size = TAILLEINITIALE;
    tableau.eltsCount = 0;
    return tableau;
}



/* Fonction qui augmente la taille d'un tableau */
int IncrementArraySize(TABLEAU* tab, int IncrementValue) {
    int* tab2 = (int*)realloc(tab->elt, (tab->size + IncrementValue) * sizeof(int));  // on réalloue de la mémoire à hauteur de l'ancienne place + la place qu'on veut rajouter
    if (tab2 == NULL) { return(-1); }                                                  // si cela echoue on renvoit 0
    tab->elt = tab2;                                                                       // sinon on affecte le nouveal emplacement mémoire
    tab->size += IncrementValue;                                                      //on met à jour la nouvelle taille du tableau
    return (tab->size);
}



/* Fonction qui insere un element a une position donnee */
int SetElement(TABLEAU* tab, int pos, int Element) {
    if (pos < tab->eltsCount) {                             // si la position est déjà dans le tableau on remplace juste l'ancien contenu par element
        *(tab->elt + pos) = Element;
        return pos;
    }
    int* tab2 = (int*)realloc(tab->elt, (pos + 1) * sizeof(int));     // sinon on réalloue de la mémoire pour le placer
    if (tab2 == NULL) { return(0); }
    tab->elt = tab2;
    for (int i = tab->eltsCount; i <= pos - 1; i++) {                     // on remplace tous les emplacement entre l'ancienne fin du tableau et la position par 0
        *(tab->elt + i) = 0;
    }
    *(tab->elt + pos) = Element;                                    // on met element à pos
    tab->size = pos + 1;                                              // on met à jour la taille et le nombre d'elements du tableau
    tab->eltsCount = pos + 1;
    return pos;
}



/* Fonction qui affiche une partie du tableau en fonction d'un indice de debut et d'un indice de fin */
int DisplayElements(TABLEAU* tab, int StartPos, int EndPos) {
    if ((StartPos >= 0) && (EndPos < tab->size) && (EndPos >= StartPos)) {   // on vérifie la validité des paramètres en entrée
        for (int i = StartPos; i <= EndPos; i++) {                           // on affiche les elements du tableau entre StartPos et EndPos
            printf("%d ", *(tab->elt + i));
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}



/* Fonction qui supprime un element et met a jour la taille du tableau */
int DeleteElements(TABLEAU* tab, int StartPos, int EndPos) {
    int j = 0; // initialisation de l'indice de la liste raccourcie
    int* tab2 = (int*)malloc((tab->size - (EndPos - StartPos) - 1) * sizeof(int));    // on réalloue la memoire necessaire au traitement
    if (tab2 == NULL) { return(-1); }
    for (int i = 0; i <= tab->size - 1; i++) {
        if ((i < StartPos) || (i > EndPos)) {
            *(tab2 + j) = *(tab->elt + i);                                         //on copie chaque element du tableau dans la copie lorsque son indice correspond aux paramètres d'entrée
            j++;     //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et à mesure
        }
    }
}