#ifndef ALGOCPP_INSERTIONSORT_H
#define ALGOCPP_INSERTIONSORT_H

#include "algocpp/Vector.h"

/**
 * Sort a given vector using the insertion sort algorithm
 *
 * Time complexity:
 * 	O(N^2) - when array is random
 * 	Omega(N) - when array is partially or fully sorted already
 *
 * Space complexity:
 * 	O(1)
 *
 * params:
 * 	v	Array that needs sorting
 */
void insertionSort(Vector &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (v[j-1] < v[j]) break;

			// swap
			auto temp = v[j-1];
			v[j-1] = v[j];
			v[j] = temp;
		}
	}
}

#endif // ALGOCPP_INSERTIONSORT_H
