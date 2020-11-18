#include "tab.h"





	

int main() {
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 10);
	printf("\n");

	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 20;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }

	for (int i = 0; i < nbElts; i++) {
		myTab2[i] = i + 1;
	}
	afficheTab(myTab2, TAB2SIZE, nbElts);
	//free(myTab2);
	printf("\n");

	ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 17);
	afficheTab(myTab2, TAB2SIZE, nbElts);

	return (EXIT_SUCCESS);

}