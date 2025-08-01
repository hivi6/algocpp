#ifndef ALGOCPP_SELECTIONSORT_H
#define ALGOCPP_SELECTIONSORT_H

#include "algocpp/Vector.h"

/**
 * Sort the given vector using the selection sort algorithm
 *
 * Time complexity:
 * 	O(N^2)
 *
 * Space complexity:
 * 	O(1) - No extra space
 *
 * params:
 * 	v	Vector that is going to be sorted
 */
void selectionSort(Vector &v) {
	for (int i = 0; i < v.size(); i++) {
		int minIndex = i;
		for (int j = i+1; j < v.size(); j++) {
			if (v[j] < v[minIndex])
				minIndex = j;
		}

		// swap the minimum with the current i-th index
		auto temp = v[i];
		v[i] = v[minIndex];
		v[minIndex] = temp;
	}
}

#endif // ALGOCPP_SELECTIONSORT_H
