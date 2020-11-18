#include<stdlib.h>
#include<stdio.h>

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

