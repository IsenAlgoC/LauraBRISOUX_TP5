#include "tab.h"		//fichier d'en-tête personnel




int initTab(int* tab, int size) {				// fonction qui remplit un tableau d’entiers de taille size avec des zéros
	int i = 0;
	if ((tab == NULL) || (size < 0)) {			//erreur si tab est un pointeur NULL ou size < 0
		return -1;
	}
	else {
		for (i = 0; i < size; i++) {			
			*(tab + i) = 0;						//chaque valeur est mise à zéro tour à tour
		}
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts) {			// fonction qui affiche les nbElts premièrs éléments du tableau tab
	if ((tab == NULL) || (size < 0) || (size < nbElts)) {	//erreur si tab est un pointeur NULL ou size <0 ou size < nbElts
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {					//affiche tour à tour les éléments du tableau
			printf("%d ", tab[i]);
		}
	}
	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	/*ajoute un nombre entier à la suite des valeurs déjà entrées et met à jour le nombre
		d'éléments stockés ainsi que la capacité réelle du tableau. */

	if (tab == NULL || *size < 0 || *nbElts < 0) {
		return NULL;
	}//Valeurs entrées non valides
	if (*nbElts + 1 >  *size) { //Test si dépassement de capacité
		int* tmp = tab; //Sauvegarde de l'ancien pointeur si
		*tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  //Allocation de la mémoire
		if (tab == NULL) { //Vérification que la mémoire a bien été allouée
			*tab = tmp;
			return NULL;
		}
		*size += TAILLEAJOUT;		//Si le tableau est trop petit, il doit être agrandi de TAILLEAJOUT éléments.
	}
	*(tab+*nbElts) = element;
	*nbElts += 1;
	return *nbElts;
}