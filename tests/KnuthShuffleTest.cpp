#include <iostream>
using namespace std;

#include "algocpp/Vector.h"
#include "algocpp/KnuthShuffle.h"

int main() {
	Vector v;
	for (int i = 0; i <= 10; i++) v.pushBack(i);
	cout << "v: " << v << endl;

	knuthShuffle(v);
	cout << "shuffled v: " << v << endl;

	return 0;
}
