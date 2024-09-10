#include <stdlib.h>
#include <stdio.h>

int recFactor(int amount, int result, int mult) {

	if (amount <= 0) {
		return result;
	}

	result *= mult;
	mult++;
	amount--;
	int finalResult = recFactor(amount, result, mult);

	return finalResult;

}

int main() {

	int execSuccess = 0;

	while (execSuccess == 0) {

		int number = 0;

		printf_s("Type a simple positive number : ");
		scanf_s("%d", &number);

		if (number >= 0) {

			int resultFor = 1, resultWhile = 1, resultRec = 1;

			if (number == 0 || number == 1) {

				printf_s("\nfor : %d, while : %d, recursive : %d", resultFor, resultWhile, resultRec);
				execSuccess = 1;

			}
			else {
				// For method :
				for (int i = 1; i <= number; i++) {
					resultFor *= i;
				}
				// While method :
				int j = 1;
				while (j <= number){
					resultWhile *= j;
					j++;
				}
				// Recursive method :
				resultRec = recFactor(number, 1, 1);

				printf_s("\nfor : %d, while : %d, recursive : %d", resultFor, resultWhile, resultRec);
				execSuccess = 1;

			}
		}
	}

	return EXIT_SUCCESS;

}