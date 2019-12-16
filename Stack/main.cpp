#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	Stack testStack;
	int option = 0;
	while (option != 5) {
		int value;
		cout << "Please Select:" << endl <<
				"1. push" << endl <<
				"2. pop" << endl <<
				"3. status" << endl <<
				"4. exit" << endl <<
				"Your option: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Value to push:";
			cin >> value;
			testStack.push(value);
			cout << endl;
			break;
		case 2:
			testStack.pop();
			cout << endl;
			break;
		case 3:
			cout << "Status: " << testStack.status() << endl << endl;
			break;
		case 4:
			return 0;
			break;
		}
	}


	return 0;
}