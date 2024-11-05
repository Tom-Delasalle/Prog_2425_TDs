#include <iostream>
#include <vector>

using namespace std;

template<typename Iter>
typename Iter::value_type partial_dot(Iter first1, Iter last1, Iter first2, Iter last2) {
	
	typename Iter::value_type temp = 0;
	while (first1 != last1 || first2 != last2) {
		temp += (*first1) * (*first2);
		++first1;
		++first2;
	}

	return temp;

}

int main() {

	vector<int> vector1 = { 5, 2, 1, -4, 4 };
	vector<int> vector2 = { 4, -3, 6, 1, 2 };

	int prodScal = partial_dot(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
	cout << prodScal << "\n";

	return EXIT_SUCCESS;

}