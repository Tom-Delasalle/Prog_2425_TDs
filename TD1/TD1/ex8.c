#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {

	int tabRow = 0, tabCol = 0, posNbrs = 0;

	while (posNbrs == 0) {

		printf_s("Choose the length of the table's rows : ");
		scanf("%d", &tabRow);
		printf_s("\nChoose the length of the table's columns : ");
		scanf("%d", &tabCol);
		printf_s("\n");
		if (tabCol >= 1 && tabRow >= 1) {
			posNbrs = 1;
		}

	}
	
	int** tab = (int**)malloc(tabCol * sizeof(int));
	if (tab == NULL) {
		return EXIT_FAILURE;
	}
	for (int r = 0; r < tabCol; r++) {
		tab[r] = (int*)malloc(tabRow * sizeof(int));
		if (tab[r] == NULL) {
			for (r; r >= 0; r--) {
				free(tab[r]);
			}
			free(tab);
			return EXIT_FAILURE;
		}
	}

	srand(time(NULL));
	for (int i = 0; i < tabRow; i++) {
		for (int j = 0; j < tabCol; j++) {
			tab[j][i] = rand() % 999;
		}
	}

	int temp = 0, lowest = 1000, lastCol = 0, lastRow = 0, currentCol = 0, currentRow = 0;

	// Warning : the rest of this code doesn't work as intended and causes a debug error
	for (int k = 0; k < (tabCol * tabRow); k++) {
		for (int l = 0; l < tabRow; l++) {
			for (int m = 0; m < tabCol; m++) {
				if (tab[m][l] <= lowest && tab[m][l] >= temp && currentCol != m && currentRow != l) {
					lowest = tab[m][l];
					lastCol = m;
					lastRow = l;
				}
			}
		}
		temp = tab[lastCol][lastRow];
		tab[lastCol][lastRow] = tab[currentCol][currentRow];
		tab[currentRow][currentCol] = temp;
		lowest = 1000;
		currentRow++;
		if (currentRow == tabRow) {
			currentRow = 0;
			currentCol++;
		}
	}

	for (int n = 0; n < tabRow; n++) {
		for (int o = 0; o < tabCol; o++) {
			printf_s("%d ", tab[o][n]);
		}
		printf_s("\n");
	}

	for (int p = 0; p < tabRow; p++) {
		free(tab[p]);
	}
	free(tab);

	return EXIT_SUCCESS;

}