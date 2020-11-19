#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define TAILLEINITIALE 100





/* Création du type TABLEAU */
typedef struct Tableau
{
    int* elt;// le tableau d’entiers
    int size;// la taille de ce tableau d’entiers
    int eltsCount;// le nombre d’éléments dans le tableau
}TABLEAU;
TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
int displayElements(TABLEAU* tab, int startPos, int endPos);
int deleteElements(TABLEAU* tab, int startPos, int endPos);





/* Fonction de création de tableau */
TABLEAU newArray() {
    TABLEAU tableau;
    tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
    tableau.size = TAILLEINITIALE;
    tableau.eltsCount;            //le nombre d'éléments dans le tableau
    return tableau;
}



/* Fonction qui augmente la taille d'un tableau */
int incrementArraySize(TABLEAU* tab, int incrementValue) {
    int* tab2 = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));  // on réalloue de la mémoire à hauteur de l'ancienne place + la place qu'on veut rajouter
    if (tab2 == NULL) { return(-1); }                                                  // si cela échoue on renvoie 0
    tab->elt = tab2;                                                                       // sinon on affecte le nouvel emplacement mémoire
    tab->size += incrementValue;                                                      //on met à jour la nouvelle taille du tableau
    return (tab->size);
}



/* Fonction qui insère un élément a une position donnée */
int setElement(TABLEAU* tab, int pos, int element) {
    if (pos < tab->eltsCount) {                             // si la position est déjà dans le tableau on remplace juste l'ancien contenu par élément
        *(tab->elt + pos-1) = element;
        return pos;
    }
    int* tab2 = (int*)realloc(tab->elt, (pos + 1) * sizeof(int));     // sinon on réalloue de la mémoire pour le placer
    if (tab2 == NULL) { return(0); }
    tab->elt = tab2;
    for (int i = tab->eltsCount; i <= pos - 1; i++) {                     // on remplace tous les emplacements entre l'ancienne fin du tableau et la position par 0
        *(tab->elt + i) = 0;
    }
    *(tab->elt + pos) = element;                                    // on met élément à pos
    tab->size = pos + 1;                                              // on met à jour la taille et le nombre d'éléments du tableau
    tab->eltsCount = pos + 1;
    return pos;
}



/* Fonction qui affiche une partie du tableau en fonction d'un indice de début et d'un indice de fin */
int displayElements(TABLEAU* tab, int startPos, int endPos) {
    if ((startPos >= 0) && (endPos < tab->size) && (endPos >= startPos)) {   // on vérifie la validité des paramètres en entrée
        for (int i = startPos; i <= endPos; i++) {                           // on affiche les éléments du tableau entre startPos et endPos
            printf("%d ", *(tab->elt + i));
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}



/* Fonction qui supprime un élément et met a jour la taille du tableau */
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
    int j = 0; // initialisation de l'indice de la liste raccourcie
    int* tab2 = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int));    // on réalloue la mémoire nécessaire au traitement
    if (tab2 == NULL) { return(-1); }
    for (int i = 0; i <= tab->size - 1; i++) {
        if ((i < startPos-1) || (i > endPos-1)) {
            *(tab2 + j) = *(tab->elt + i);                                         //on copie chaque élément du tableau dans la copie lorsque son indice correspond aux paramètres d'entrée
            j++;     //quand on rajoute un élément on incrémente l'indice de la copie pour la remplir au fur et à mesure
        }
    }
    tab->size -= (endPos - startPos) + 1;
    tab->eltsCount -= (endPos - startPos) + 1;
    tab->elt = tab2;
    return(tab->size);
}



int main() {
    TABLEAU tableau = newArray();
    for (int i = 0; i <= tableau.size -1; i++) {     //initialisation du tableau avec pour valeur l'indice (afin de bien voir les modifications)
        *(tableau.elt + i) = i+1;
    }
    tableau.eltsCount = 100;
    setElement(&tableau, 2, 9999);
    setElement(&tableau, 112, 9999);                     // on teste l'insertion d'éléments dans la liste puis en dehors
    displayElements(&tableau, 0, tableau.size - 1);      // ils sont bien remplacés et l'ajout en dehors fonctionne avec les "0" de comblage
    deleteElements(&tableau, 9, 16);
    deleteElements(&tableau, 50 - (16 - 9 + 1), 63 - (16 - 9 + 1));                  //on supprime les segments entre 10 et 25 puis 57 et 69 (inclus)
    displayElements(&tableau, 0, tableau.size - 1);    // les segments ont bien disparu
    printf("La taille avant realloc est %d\n", tableau.size);                      // taille avant réalloc
    int a = incrementArraySize(&tableau, 10);
    printf("La taille apres realloc correcte est %d\n", a);                                 // taille après réalloc correcte
    system("pause");
    free(tableau.elt);
}