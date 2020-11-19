#include "tab.h"		//fichiier d'en-t�te personnel



int main() {
	int myTab1[10];
	initTab(myTab1, 10);				//les valeurs sont initialis�es � 0
	afficheTab(myTab1, 10, 10);			//on affiche un tableau de 10 valeurs
	printf("\n");

	int* myTab2 = NULL;					//tableau dynamique
	int tabSize = TAB2SIZE;
	int nbElts = 20;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));			//allocation de la m�moire
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("m�moire insuffisante"); return(-1); }

	for (int i = 0; i < nbElts; i++) {			//Remplir les 20 premi�res valeurs du tableau avec les nombres de 1 � 20
		myTab2[i] = i + 1;
	}
	afficheTab(myTab2, TAB2SIZE, nbElts);
	
	printf("\n");

	ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 17);		//ajouter 17 � la fin du tableau myTab2
	afficheTab(myTab2, TAB2SIZE, nbElts);

	free(myTab2);									//Restitution au syst�me de la m�moire devenue inutile
	return (EXIT_SUCCESS);

}