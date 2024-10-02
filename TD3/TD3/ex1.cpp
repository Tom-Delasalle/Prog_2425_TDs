#include <iostream>

using namespace std;

class A {
public:
	A() { x = 0; cout << "1"; }
	A(int px) { x = px; cout << "2"; }
	A(const A& pa) { x = pa.x; cout << "3"; }
protected:
	int x;
};
class B {
public:
	B(const A& pa = A()) : a(pa) { cout << "4"; }
	B(const A& pa, int py) { a = pa; y = py; cout << "5"; }
protected:
	A a;
	int y;
};
class C : public B {
public:
	C(int pz = 1) { z = pz; cout << "6"; }
	C(A pa) : B(pa) { z = 0; cout << "7"; }
	C(const B& pb) : B(pb), a(1) { z = 0; cout << "8"; }
protected:
	A a;
	int z;
};
int main() {

	cout << "-- A --\n";		// Print -- A --
	A a0; cout << endl;			// Create a0 from A class with no default variables, meaning that a0.x = 0 , then print 1
	A a1(3); cout << endl;		// Create a1 from A class with 3 as a default number, meaning that a1.x = 3 , then print 2
	A a2(a1); cout << endl;		// Create a2 from A class with a1 as a default variable, meaning that a2.x = a1.x so a2.x = 3 , then print 3
	A a3 = a2; cout << endl;	// Create a3 from A class which is identical to a2 . Debug printed 3, meaning that a3.x = a2.x so a3.x = 3
	a3 = a1; cout << endl;		// Make a3 identical to a1 . From what we have seen, we can suppose that a3.x = a1.x so a3.x = 3
	cout << "-- B --\n";		// Print -- B --
	B b0(a0, 3); cout << endl;	// Debug printed 1 and 5, so the line created b0.a from A class and b0.a.x = 0 and b0.y = 3
	B b1(a1); cout << endl;		// Debug printed 3 and 4, so the line created b1.a from A class and b1.a.x = a1.x so b1.a.x = 3 and b0.y is not initialized
	B b2; cout << endl;			// Debug printed 1, 3 and 4, so the line created by default a new A class var with AVar.x = 0 , then b2.a.x = 0 and y is not initialized
	cout << "-- C --\n";		// Print -- C --
	C c0; cout << endl;			// Debug printed 1 3 4 1 and 6, 
	C c1(a1); cout << endl;		// Debug printed 3 3 4 1 and 7
	C c2(b2); cout << endl;		// Debug printed 3 2 and 8

}