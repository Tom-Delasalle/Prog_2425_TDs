#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	float a = 0.0, b = 0.0, c = 0.0;
	float x1 = 0.0, x2 = 0.0;

	printf_s("Please type in order and separated by a space the values of a, b and c for the equation ax^2+bx+c : ");
	scanf_s("%f %f %f", &a, &b, &c);

	float det = b * b - (4 * a * c);
	if (det < 0) {

		printf_s("This equation does not have any solution.");

		return EXIT_SUCCESS;
	}
	else if (det == 0) {

		x1 = (-b) / (2 * a);
		printf_s("This equation only has one root, which is equal to %f", x1);

		return EXIT_SUCCESS;
	}
	else {

		x1 = ((-b) + sqrt(det)) / (2 * a);
		x2 = ((-b) - sqrt(det)) / (2 * a);
		printf_s("This equation has two roots, which are equal to %f and %f", x1, x2);

		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;

}