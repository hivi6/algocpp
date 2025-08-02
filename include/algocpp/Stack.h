#ifndef ALGOCPP_STACK_H
#define ALGOCPP_STACK_H

#include "algocpp/Vector.h"

class Stack {
	Vector elems;

public:
	/**
	 * Default constructor, initializes the stack as empty
	 */
	Stack() {}

	/**
	 * Get if the stack is empty
	 *
	 * returns:
	 * 	bool	if the stack is empty
	 */
	bool empty() const {
		return elems.size() == 0;
	}

	/**
	 * Size of the stack
	 *
	 * returns
	 * 	int	size of the stack
	 */
	int size() const {
		return elems.size();
	}

	/**
	 * Push value to the top of the stack
	 *
	 * params:
	 * 	value	value to be inserted at the top of the stack
	 */
	void push(int value) {
		elems.pushBack(value);
	}

	/**
	 * Pop the top of the stack
	 */
	void pop() {
		elems.popBack();
	}

	/**
	 * Get the top of the stack
	 *
	 * returns:
	 * 	int	top of the stack
	 */
	const int& top() const {
		return elems.back();
	}

	int& top() {
		return elems.back();
	}

	/**
	 * Stdout
	 *
	 * params:
	 * 	out	output stream
	 * 	s	stack that needs to be output
	 */
	friend std::ostream& operator<<(std::ostream& out, const Stack &s) {
		return out << s.elems;
	}
};

#endif // ALGOCPP_STACK_H
