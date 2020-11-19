#include "tab.h"		//fichier d'en-t�te personnel




int initTab(int* tab, int size) {				// fonction qui remplit un tableau d�entiers de taille size avec des z�ros
	int i = 0;
	if ((tab == NULL) || (size < 0)) {			//erreur si tab est un pointeur NULL ou size < 0
		return -1;
	}
	else {
		for (i = 0; i < size; i++) {			
			*(tab + i) = 0;						//chaque valeur est mise � z�ro tour � tour
		}
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts) {			// fonction qui affiche les nbElts premi�rs �l�ments du tableau tab
	if ((tab == NULL) || (size < 0) || (size < nbElts)) {	//erreur si tab est un pointeur NULL ou size <0 ou size < nbElts
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {					//affiche tour � tour les �l�ments du tableau
			printf("%d ", tab[i]);
		}
	}
	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	/*ajoute un nombre entier � la suite des valeurs d�j� entr�es et met � jour le nombre
		d'�l�ments stock�s ainsi que la capacit� r�elle du tableau. */

	if (tab == NULL || *size < 0 || *nbElts < 0) {
		return NULL;
	}//Valeurs entr�es non valides
	if (*nbElts + 1 >  *size) { //Test si d�passement de capacit�
		int* tmp = tab; //Sauvegarde de l'ancien pointeur si
		*tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  //Allocation de la m�moire
		if (tab == NULL) { //V�rification que la m�moire a bien �t� allou�e
			*tab = tmp;
			return NULL;
		}
		*size += TAILLEAJOUT;		//Si le tableau est trop petit, il doit �tre agrandi de TAILLEAJOUT �l�ments.
	}
	*(tab+*nbElts) = element;
	*nbElts += 1;
	return *nbElts;
}