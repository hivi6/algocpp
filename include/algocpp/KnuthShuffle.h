#ifndef ALGOCPP_KNUTHSHUFFLE_H
#define ALGOCPP_KNUTHSHUFFLE_H

#include <cstdlib>
#include <ctime>

#include "algocpp/Vector.h"

/**
 * Shuffle a given array using knuth shuffle algorithm
 *
 * Time complexity:
 * 	O(N)
 *
 * Space complexity:
 * 	O(1)
 *
 * params:
 * 	v	Vector that needs shuffling
 */
void knuthShuffle(Vector &v) {
	std::srand(std::time(0));
	for (int i = 0; i < v.size(); i++) {
		int left = std::rand() % (i+1);

		// swap
		auto temp = v[i];
		v[i] = v[left];
		v[left] = temp;
	}
}

#endif // ALGOCPP_KNUTHSHUFFLE_H
