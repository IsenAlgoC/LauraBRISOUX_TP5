#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define TAILLEINITIALE 100





/* Cr�ation du type TABLEAU */
typedef struct Tableau
{
    int* elt;// le tableau d�entiers
    int size;// la taille de ce tableau d�entiers
    int eltsCount;// le nombre d��l�ments dans le tableau
}TABLEAU;
TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
int displayElements(TABLEAU* tab, int startPos, int endPos);
int deleteElements(TABLEAU* tab, int startPos, int endPos);





/* Fonction de cr�ation de tableau */
TABLEAU newArray() {
    TABLEAU tableau;
    tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
    tableau.size = TAILLEINITIALE;
    tableau.eltsCount;            //le nombre d'�l�ments dans le tableau
    return tableau;
}



/* Fonction qui augmente la taille d'un tableau */
int incrementArraySize(TABLEAU* tab, int incrementValue) {
    int* tab2 = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));  // on r�alloue de la m�moire � hauteur de l'ancienne place + la place qu'on veut rajouter
    if (tab2 == NULL) { return(-1); }                                                  // si cela �choue on renvoie 0
    tab->elt = tab2;                                                                       // sinon on affecte le nouvel emplacement m�moire
    tab->size += incrementValue;                                                      //on met � jour la nouvelle taille du tableau
    return (tab->size);
}



/* Fonction qui ins�re un �l�ment a une position donn�e */
int setElement(TABLEAU* tab, int pos, int element) {
    if (pos < tab->eltsCount) {                             // si la position est d�j� dans le tableau on remplace juste l'ancien contenu par �l�ment
        *(tab->elt + pos-1) = element;
        return pos;
    }
    int* tab2 = (int*)realloc(tab->elt, (pos + 1) * sizeof(int));     // sinon on r�alloue de la m�moire pour le placer
    if (tab2 == NULL) { return(0); }
    tab->elt = tab2;
    for (int i = tab->eltsCount; i <= pos - 1; i++) {                     // on remplace tous les emplacements entre l'ancienne fin du tableau et la position par 0
        *(tab->elt + i) = 0;
    }
    *(tab->elt + pos) = element;                                    // on met �l�ment � pos
    tab->size = pos + 1;                                              // on met � jour la taille et le nombre d'�l�ments du tableau
    tab->eltsCount = pos + 1;
    return pos;
}



/* Fonction qui affiche une partie du tableau en fonction d'un indice de d�but et d'un indice de fin */
int displayElements(TABLEAU* tab, int startPos, int endPos) {
    if ((startPos >= 0) && (endPos < tab->size) && (endPos >= startPos)) {   // on v�rifie la validit� des param�tres en entr�e
        for (int i = startPos; i <= endPos; i++) {                           // on affiche les �l�ments du tableau entre startPos et endPos
            printf("%d ", *(tab->elt + i));
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}



/* Fonction qui supprime un �l�ment et met a jour la taille du tableau */
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
    int j = 0; // initialisation de l'indice de la liste raccourcie
    int* tab2 = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int));    // on r�alloue la m�moire n�cessaire au traitement
    if (tab2 == NULL) { return(-1); }
    for (int i = 0; i <= tab->size - 1; i++) {
        if ((i < startPos-1) || (i > endPos-1)) {
            *(tab2 + j) = *(tab->elt + i);                                         //on copie chaque �l�ment du tableau dans la copie lorsque son indice correspond aux param�tres d'entr�e
            j++;     //quand on rajoute un �l�ment on incr�mente l'indice de la copie pour la remplir au fur et � mesure
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
    setElement(&tableau, 112, 9999);                     // on teste l'insertion d'�l�ments dans la liste puis en dehors
    displayElements(&tableau, 0, tableau.size - 1);      // ils sont bien remplac�s et l'ajout en dehors fonctionne avec les "0" de comblage
    deleteElements(&tableau, 9, 16);
    deleteElements(&tableau, 50 - (16 - 9 + 1), 63 - (16 - 9 + 1));                  //on supprime les segments entre 10 et 25 puis 57 et 69 (inclus)
    displayElements(&tableau, 0, tableau.size - 1);    // les segments ont bien disparu
    printf("La taille avant realloc est %d\n", tableau.size);                      // taille avant r�alloc
    int a = incrementArraySize(&tableau, 10);
    printf("La taille apres realloc correcte est %d\n", a);                                 // taille apr�s r�alloc correcte
    system("pause");
    free(tableau.elt);
}