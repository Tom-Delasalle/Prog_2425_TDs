#include <stdio.h>
#include <stdlib.h>

int main() {

	int x = 14, y = 13;
	if (x > y)
	{
		if (x < 20)
		{
			x -= 10;
		}
		else
		{
			x += 10;
		}
	}
	printf("%d\n", x); // Displays 4

	x = 4;
	y = 3;
	x = x + y;
	y = x - y;
	printf("%d\n", y); // Displays 4

	x = 0;
	y = 100;
	int count = 0;
	while (x * x <= y)
	{
		x += 1;
		count++;
	}
	printf_s("%d\n", count); // The instruction is repeated 11 times

	return EXIT_SUCCESS;

}