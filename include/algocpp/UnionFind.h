#ifndef ALGOCPP_UNIONFIND_H
#define ALGOCPP_UNIONFIND_H

#include "Vector.h"

/**
 * UnionFind
 *
 * A data structure to find if two components are related
 *
 * members:
 * 	id	keeping track of the roots
 * 	sz	keeping track of the size of the roots
 */
class UnionFind {
	Vector id, sz;

public:
	UnionFind(int n) {
		id = Vector(n, 0);
		sz = Vector(n, 1); // size of roots going to be 1
		for (int i = 0; i < id.size(); i++)
			id[i] = i; // all roots are going to be itself
	}

	/**
	 * unite 2 components
	 *
	 * params:
	 * 	p	first component; p = [0, n)
	 * 	q	second component; q = [0, n)
	 */
	void unite(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;

		if (sz[pRoot] < sz[qRoot]) {
			sz[qRoot] += sz[pRoot];
			id[pRoot] = qRoot;
		}
		else {
			sz[pRoot] += sz[qRoot];
			id[qRoot] = pRoot;
		}
	}

	/**
	 * Find the root of a component
	 *
	 * params:
	 * 	p	whose root needs to be found
	 */
	int find(int p) {
		while (p != id[p]) p = id[p];
		return p;
	}

	/**
	 * Number of elements
	 */
	int size() {
		return id.size();
	}
};

#endif // ALGOCPP_UNIONFIND_H
