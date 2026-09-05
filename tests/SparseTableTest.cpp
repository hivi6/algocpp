#include <iostream>
using namespace std;

#include "algocpp/SparseTable.h"

int main() {
	vector<int> a = {1, 5, 2, 0, 4, 7, 8};
	SparseTable s(a);

	for (auto x: a) cout << x << " ";
	cout << endl;

	auto n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << "min(a[" << i << "..." << j << "]: " 
				<< s.query(i, j) << endl;
		}
	}

	return 0;
}

