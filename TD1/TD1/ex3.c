#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {

	int execSuccess = 0;

	while (execSuccess == 0) {
		
		char upToDown = "\0";

		printf_s("\nPlease enter a single uppercase character : ");
		scanf("%c", &upToDown);

		if (upToDown >= 'A' && upToDown <= 'Z') {

			upToDown = tolower(upToDown);
			printf_s("\n%c", upToDown);

			execSuccess = 1;
		}
	}
	
	return EXIT_SUCCESS;

}