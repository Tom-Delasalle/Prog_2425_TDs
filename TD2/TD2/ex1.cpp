#include <iostream>
//#define multiplier(x,y) ((x) * (y))
#ifndef multiplier
	constexpr
	int multiplier(int x, int y) {
		return (x * y);
	}
#endif // !multiplier



using namespace std;

int main() {
	
	int a;
	int b;
	cout << "Entrer une valeur : " << endl;
	cin >> a;
	cout << "Entrer une autre valeur : " << endl;
	cin >> b;
	cout << multiplier(a + 1, b + 1) << endl;

	return EXIT_SUCCESS;

}

// (b) : Il est possible d'utiliser le mot clé "constexpr" mais pas "consteval"