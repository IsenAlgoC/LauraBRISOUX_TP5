#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "tab.h"

#define TAB2SIZE 100



	

int main() {
	/*int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 10);*/

	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }

	for (int i = 0; i < 20; i++) {
		myTab2[i] = i + 1;
	}
	afficheTab(myTab2, TAB2SIZE, 20);
	return (EXIT_SUCCESS);

}