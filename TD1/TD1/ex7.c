#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {

	int tabLen = 0;
	printf_s("Choose a length for the table : ");
	scanf("%d", &tabLen);
	printf_s("\n");
	int* tab = (int*)malloc(tabLen * sizeof(int));
	if (tab == NULL) {
		return EXIT_FAILURE;
	}
	int temp = 0;
	srand(time(NULL));
	
	for (int i = 0; i < tabLen; i++) {
		tab[i] = rand() % 999;
	}

	for (int j = 0; j < tabLen; j++) {
		for (int k = 0; k < (tabLen - 1); k++) {
			if (tab[k] > tab[k + 1]) {
				temp = tab[k];
				tab[k] = tab[k + 1];
				tab[k + 1] = temp;
			}
		}
	}

	for (int l = 0; l < tabLen; l++) {
		printf_s("%d ", tab[l]);
	}

	return EXIT_SUCCESS;

}