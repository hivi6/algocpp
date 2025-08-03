#ifndef ALGOCPP_SHELLSORT_H
#define ALGOCPP_SHELLSORT_H

#include "algocpp/Vector.h"

/**
 * Sorting a given array using the shell sort algorithm.
 *
 * Time complexity:
 * 	O(N^(3/2))
 * 	O(N) - partially sorted array
 *
 * Space complexity:
 * 	O(1)
 *
 * params:
 * 	v	Vector to be sorted
 */
void shellSort(Vector &v) {
	// find the increment sequence; using knuth sequence
	int h = 1;
	while (h < v.size()/3) h = 3*h + 1; 

	while (h >= 1) {
		// h-sort the array
		for (int i = h; i < v.size(); i++) {
			for (int j = i; j >= h && v[j] < v[j-h]; j -= h) {
				// swap
				auto temp = v[j];
				v[j] = v[j-h];
				v[j-h] = temp;
			}
		}

		h = h/3;
	}
}

#endif // ALGOCPP_SHELLSORT_H

