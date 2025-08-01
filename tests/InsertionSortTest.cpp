#include <iostream>
using namespace std;

#include "algocpp/Vector.h"
#include "algocpp/InsertionSort.h"

int main() {
	Vector v;
	for (int i = 10; i >= 0; i--) v.pushBack(i);
	cout << "v: " << v << endl;

	insertionSort(v);
	cout << "sorted v: " << v << endl;

	return 0;
}
