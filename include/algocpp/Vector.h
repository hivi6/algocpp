#ifndef ALGOCPP_VECTOR_H
#define ALGOCPP_VECTOR_H

#include <iostream>

/**
 * Vector
 * 
 * Resizable Array
 *
 * members:
 * 	elems	raw array pointer to elements
 *	sz	size of the array
 *	cap	capacity of the array
 */
class Vector {
	int *elems;
	int sz, cap;

public:
	/**
	 * Default Constructor, initializes an empty vector
	 */
	Vector(): elems{nullptr}, sz{0}, cap{0} {}

	/**
	 * Constructor that initializes an array of a given size
	 *
	 * params:
	 * 	size	size of the initial array
	 */
	Vector(int size): elems{new int[size]}, sz{size}, cap{size} {}

	/**
	 * Constructor that intializes an array of a given size and initial
	 * value
	 *
	 * params:
	 * 	size	size of the initial array
	 * 	init	initial value of the elements
	 */
	Vector(int size, int init): elems{new int[size]}, sz{size}, cap{size} {
		for (int i = 0; i < size; i++)
			elems[i] = init;
	}

	/**
	 * Constructor that moves a given vector to this
	 *
	 * params:
	 * 	v	moving vector
	 */
	Vector(Vector& v): elems{v.elems}, sz{v.sz}, cap{v.cap} {
		v.elems = nullptr;
		v.sz = v.cap = 0;
	}

	/**
	 * Constructor that copies the content from a given vector to this
	 *
	 * params:
	 * 	v	copy vector
	 */
	Vector(const Vector& v): elems{new int[v.sz]}, sz{v.sz}, cap{v.cap} {
		for (int i = 0; i < sz; i++)
			elems[i] = v.elems[i];
	}

	/**
	 * Destructor cleaning up all the elements
	 */
	~Vector() {
		delete[] elems;
	}

	/**
	 * Get the size of the vector
	 *
	 * returns:
	 * 	int	size of the vector
	 */
	int size() const {
		return sz;
	}

	/**
	 * Get the capacity of the vector
	 *
	 * returns:
	 * 	int	capacity of the vector
	 */
	int capacity() const {
		return cap;
	}

	/**
	 * Reserve a given capacity for the elems array.
	 *
	 * params:
	 * 	capacity	the new capacity of the vector
	 */
	void reserve(int capacity) {
		if (capacity < sz) {
			sz = capacity;
		}
		else if (capacity > cap) {
			int *newElems = new int[capacity];
			for (int i = 0; i < sz; i++)
				newElems[i] = elems[i];
			if (elems) delete[] elems;
			elems = newElems;
			cap = capacity;
		}
	}

	/**
	 * Access a given element
	 *
	 * params:
	 * 	index	Access element in a given index
	 *
	 * returns:
	 * 	int	element at the given index
	 */
	const int& operator[](int index) const {
		return elems[index];
	}

	int& operator[](int index) {
		return elems[index];
	}

	/**
	 * Push an element at the back of the array
	 *
	 * params:
	 * 	value	element that needs to be pushed back
	 */
	void pushBack(int value) {
		if (cap <= sz) reserve((cap+1) * 2);
		elems[sz++] = value;
	}

	/**
	 * Pop an element out the back of the array
	 */
	void popBack() {
		if (sz > 0) sz--;
	}
	
	/**
	 * Get the front element of the array
	 *
	 * returns:
	 * 	int	element at the front of the array
	 */
	int& front() {
		return elems[0];
	}

	const int& front() const {
		return elems[0];
	}

	/**
	 * Get the back element of the array
	 *
	 * returns:
	 * 	int	element at the back of the array
	 */
	int& back() {
		return elems[sz-1];
	}

	const int& back() const {
		return elems[sz-1];
	}

	/**
	 * Print the array
	 *
	 * returns:
	 * 	ostream
	 */
	friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
		out << "[";
		for (int i = 0; i < v.size(); i++) {
			out << v[i];
			if (i != v.size()-1) out << " ";
		}
		out << "]";
		return out;
	}
};

#endif // ALGOCPP_VECTOR_H
