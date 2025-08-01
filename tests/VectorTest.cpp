#include <iostream>
using namespace std;

#include "algocpp/Vector.h"

void printVector(const Vector& A) {
	cout << "size: " << A.size() << " capacity: " << A.capacity()
		<< " elems: " << A << endl;
}

int main() {
	Vector a;

	cout << "+=== Empty Vector ===+" << endl;
	printVector(a);
	cout << endl;

	cout << "+=== Check how size and capacity grows ===+" << endl;
	for (int i = 0; i <= 10; i++) {
		a.pushBack(i);
		printVector(a);
	}
	cout << endl;

	cout << "+=== Get front and back elements ===+" << endl;
	cout << "front: " << a.front() << " back: " << a.back() << endl;
	cout << endl;

	cout << "+=== Check if reserve set is less than size ===+" << endl;
	a.reserve(3);
	printVector(a);
	cout << endl;

	cout << "+=== Get front and back elements again ===+" << endl;
	cout << "front: " << a.front() << " back: " << a.back() << endl;
	cout << endl;

	cout << "+=== Setting all the values to 10 ===+" << endl;
	for (int i = 0; i < a.size(); i++)
		a[i] = 10;
	printVector(a);
	cout << endl;

	cout << "+=== Get front and back elements again x2 ===+" << endl;
	cout << "front: " << a.front() << " back: " << a.back() << endl;
	cout << endl;

	cout << "+=== Copy the content of the vector a ===+" << endl;
	Vector b(a);
	printVector(b);
	cout << endl;

	return 0;
}
