#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define TAILLEAJOUT 50


int initTab(int* tab, int size) {
	int i = 0;
	if ((tab == NULL) || (size < 0)) {
		return -1;
	}
	else {
		for (i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (size < nbElts)) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", tab[i]);
		}
	}
	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	/*if (tab == NULL) {
		return -1;
	}
	if(nbElts<size){
		tab[*nbElts] = element;
		nbElts++;
	}
	else {
		tab = (int*)realloc(tab, (*size + 1) * sizeof(int));
	}
	return 0;*/
	if (tab == NULL || size < 0 || nbElts < 0) return NULL; //Valeurs entrées non valides
	if (nbElts + 1 >  size) { //Test si dépassement de capacité
		int* tmp = tab; //Sauvegarde de l'ancien pointeur si
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  //Allocation de la mémoire
		if (tab == NULL) { //Vérification que la mémoire a bien été allouée
			tab = tmp;
			return NULL;
		}
		*size += TAILLEAJOUT;
	}
	*(tab+*nbElts) = element;
	nbElts += 1;
	return 0;
}