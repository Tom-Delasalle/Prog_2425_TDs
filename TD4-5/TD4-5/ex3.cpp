#include <iostream>

using namespace std;

template<typename Iter>
typename Iter::value_type partial_dot(Iter first1, Iter last1, Iter first2, Iter last2) {

	int i = 0;
	Iter tempTab[];
	while (first1 != last1 || first2 != last2) {
		tempTab[i] = first1 * first2;
		++first1;
		++last1;
	}

}

int main() {

	return EXIT_SUCCESS;

}