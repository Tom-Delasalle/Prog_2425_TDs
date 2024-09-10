#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {

	char word[32] = {'\0'};
	bool acceptedWord = false, isLetter = true, stop = false;
	int currentLen = 0;

	while (acceptedWord == false) {

		if (word != NULL) {
			for (int i = 0; i <= (strlen(word) + 1); i++) {
				word[i] = '\0';
			}
		}
		printf_s("\nPlease enter a word that is more than 3 and less than 20 characters long : ");
		scanf("%s", &word);
		// Checking if the word is less than 20 caracters and if all the caracters are letters
		isLetter = true;
		currentLen = 0;
		stop = false;
		while (isLetter == true && currentLen <= 20 && stop == false) {
			if (word[currentLen] == '\0') {
				if (currentLen <= 2) {
					isLetter = false;
				}
				else {
					stop = true;
				}
			}
			else if ((word[currentLen] >= 'a' && word[currentLen] <= 'z') || (word[currentLen] >= 'A' && word[currentLen] <= 'Z')) {
				word[currentLen] = toupper(word[currentLen]);
				currentLen++;
			}
			else {
				isLetter = false;
			}

		}
		if (isLetter == true && currentLen <= 19) {
			acceptedWord = true;
		}

	}

	bool victory = false;
	int nbrOfTries = 10;
	char wordDisplay[21] = {'\0'};
	char typedLetter = '\0';

	for (int j = 0; j < currentLen; j++) {
		wordDisplay[j] = '_';
	}
	wordDisplay[currentLen] = '\0';
	// Main Game :
	printf_s("\nPlease enter a singular letter.");
	while (victory == false && nbrOfTries >= 1) {
		
		printf_s("\n %s | Number of tries left : %d | Your letter : ", wordDisplay, nbrOfTries);
		scanf("%c", &typedLetter);

		if ((typedLetter >= 'a' && typedLetter <= 'z') || (typedLetter >= 'A' && typedLetter <= 'Z')) {

			typedLetter = toupper(typedLetter);
			for (int k = 0; k < currentLen; k++) {
				if (typedLetter == word[k]) {
					wordDisplay[k] = typedLetter;
				}
			}
			victory = true;
			for (int l = 0; l < currentLen; l++) {
				if (wordDisplay[l] == '_') {
					victory = false;
				}
				
			}
			if (victory == true) {
				printf_s("\n\tThe word was %s\n", wordDisplay);
			}
			nbrOfTries--;

		}
		else {
			printf_s("\nPlease enter a singular letter.");
		}

	}

	return EXIT_SUCCESS;
}