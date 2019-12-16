#include <iostream>
#include "sort.h"

using namespace std;

int main() {
	char charArray[] = { 'c','e','a','d','b' };
	int intarray[] = { 3,2,5,1,4 };
	float floatArray[] = { 1.1f,5.6f,4.2f,3.4f,2.1f };

	mySort<char> sortedCharArray(charArray, 5);
	mySort<int> sortedIntArray(intarray, 5);
	mySort<float> sortedFloatArray(floatArray, 5);

	//before sort
	cout << "Before Sort:" << endl;
	sortedCharArray.printArrays();
	sortedIntArray.printArrays();
	sortedFloatArray.printArrays();
	cout << endl;

	//sort
	sortedCharArray.sortAlgorithm();
	sortedIntArray.sortAlgorithm();
	sortedFloatArray.sortAlgorithm();

	//after sort
	cout << "After Sort:" << endl;
	sortedCharArray.printArrays();
	sortedIntArray.printArrays();
	sortedFloatArray.printArrays();

	return 0;
}