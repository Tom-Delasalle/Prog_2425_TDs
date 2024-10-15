#include <iostream>
#include <set>

using namespace std;

int main() {

	int a[] = { 7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2 }; // Table a with 18 values ranging from 1 to 10
	multiset<int> s(&a[0], &a[17]);						 // Creates multiset int clas s from a, and in this case s will have every values from a sorted
	multiset<int>::iterator p = s.begin();				 // Creates iterator p pointing to the first element of s
	while (p != s.end()) cout << *p++ << " ";			 // While p has not reached the end of s, print current pointed element and go to next pointer
	return 0;

}
