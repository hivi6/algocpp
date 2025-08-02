#include <iostream>
using namespace std;

#include "algocpp/Vector.h"
#include "algocpp/MergeSort.h"

int main() {
	Vector v;
	for (int i = 10; i >= 0; i--) v.pushBack(i);
	cout << "v: " << v << endl;

	mergeSort(v);
	cout << "sorted v: " << v << endl;

	return 0;
}
