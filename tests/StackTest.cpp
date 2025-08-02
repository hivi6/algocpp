#include <iostream>
using namespace std;

#include "algocpp/Stack.h"

void printStack(const Stack& s) {
	cout << "top: " << s.top() << " size: " << s.size() 
		<< " s: " << s << endl;
}

int main() {
	Stack s;
	cout << "+=== pushing elements in the stack ===+" << endl;
	for (int i = 0; i < 10; i++) {
		s.push(i);
		printStack(s);
	}

	cout << "+=== poping out elements in the stack ===+" << endl;
	while (!s.empty()) {
		printStack(s);
		s.pop();
	}
	return 0;
}
