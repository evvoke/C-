#include <iostream>
#include "CircleQueue.h"
using namespace std;

int main() {
	Queue *testQueue = new Queue;

	//enQueue
	for (int i = 0; i < 10; i++) {
		testQueue->enQueue(i+1);
	}
	testQueue->status();
	cout << "-----------" << endl;
	//enQueue full Queue
	testQueue->enQueue(11);
	testQueue->status();

	cout << "===========" << endl;

	//deQueue
	for (int i = 0; i < 10; i++) {
		testQueue->deQueue();
	}
	cout << "-----------" << endl;
	//deQueue empty Queue
	testQueue->deQueue();
	testQueue->status();
	return 0;
}