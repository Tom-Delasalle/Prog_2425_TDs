#include <iostream>
#include <iomanip>

const auto TAB_LENGTH = 12;
using namespace std;

void printTab(int nbr, int a) {

	cout << setw(3) << nbr << "   * " << setw(3) << a << "   = " << setw(3) << nbr * a << endl;
}

int main() {

	int nbr = 0;

	while (nbr >= 10 || nbr <= 0) {
		cout << "\nEntrez une valeur entre 1 et 9 : " << endl;
		cin >> nbr;
	}

	for (int i = 0; i <= TAB_LENGTH; ++i) {
		printTab(nbr, i);
	}

	return EXIT_SUCCESS;

}