#ifndef ALGOCPP_MERGESORT_H
#define ALGOCPP_MERGESORT_H

#include "algocpp/Vector.h"

/**
 * Merging 2 subarrays, in sorted order
 *
 * Time complexity:
 * 	O(N)
 *
 * Space complexity:
 * 	O(N)
 *
 * params:
 * 	v	Vector on which merging needs to be done
 * 	left	start of the left subarray
 * 	mid	end of the left subarray
 * 	right	end of the right subarray
 */
void mergeSortMerger(Vector &v, int left, int mid, int right) {
	Vector leftVector, rightVector, mainVector;
	for (int i = left; i <= mid; i++) leftVector.pushBack(v[i]);
	for (int i = mid+1; i <= right; i++) rightVector.pushBack(v[i]);

	int i = 0, j = 0, k = left;
	while (i < leftVector.size() && j < rightVector.size()) {
		if (leftVector[i] < rightVector[j])
			v[k++] = leftVector[i++];
		else
			v[k++] = rightVector[j++];
	}
	while (i < leftVector.size()) v[k++] = leftVector[i++];
	while (j < rightVector.size()) v[k++] = rightVector[j++];
}

/**
 * Divide and conquer sorting an array
 *
 * Time complexity:
 * 	O(NlgN)
 *
 * Space complexity:
 * 	O(N)
 *
 * params:
 * 	v	Vector that needs to be sorted
 *	left	start of the vector (inclusive)
 *	right	end of the vector (inclusive)
 */
void mergeSortHelper(Vector &v, int left, int right) {
	if (left >= right) return;
	auto mid = left + (right - left) / 2;
	mergeSortHelper(v, left, mid);
	mergeSortHelper(v, mid+1, right);
	mergeSortMerger(v, left, mid, right);
}

/**
 * Sorting a given array using the merge sort algorithm
 *
 * Time complexity:
 * 	O(NlgN)
 *
 * Space complexity:
 * 	O(NlgN)
 *
 * params:
 * 	v	Vector that needs to be sorted
 */
void mergeSort(Vector &v) {
	mergeSortHelper(v, 0, v.size()-1);
}

#endif // ALGOCPP_MERGESORT_H

