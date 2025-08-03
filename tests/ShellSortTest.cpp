#include <iostream>
using namespace std;

#include "algocpp/Vector.h"
#include "algocpp/ShellSort.h"

int main() {
	Vector v;
	for (int i = 10; i >= 0; i--) v.pushBack(i);
	cout << "v: " << v << endl;

	shellSort(v);
	cout << "sorted v: " << v << endl;

	return 0;
}
