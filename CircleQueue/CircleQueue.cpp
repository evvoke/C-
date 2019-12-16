#include <iostream>
#include "CircleQueue.h"
using namespace std;

Queue::Queue() {}

Queue::~Queue() {
	free(front);
}

void Queue::enQueue(int value) {
	if (isFull()) {
		cout << "Queue is full." << endl;
		return;
	}
	if (isEmpty()) {
		front = new QueueNode;
		front->data = value;
		front->link = NULL;
		back = front;
		cout << value << " has been added to the queue." << endl;
	}
	else {
		QueueNodePtr tempPtr = new QueueNode;
		tempPtr->data = value;
		tempPtr->link = NULL;
		back->link = tempPtr;
		back = tempPtr;
		cout << value << " has been added to the queue." << endl;
	}
}

void Queue::deQueue() {
	if (isEmpty()) {
		cout << "Queue is empty." << endl;
		return;
	}
	int value = front->data;
	QueueNodePtr discard;
	discard = front;
	front = front->link;
	if (front == NULL) {
		back = NULL;
	}
	delete discard;
	cout << value << " has been removed from the queue." << endl;
	return;
}

void Queue::status() {
	int count = 0;
	QueueNodePtr here = front;
	while (here != NULL) {
		here = here->link;
		count++;
	}
	cout << "Status: " << count << endl;
	return;
}

bool Queue::isEmpty() {
	return (front == NULL);
}

bool Queue::isFull() {
	int count = 0;
	QueueNodePtr here = front;
	while (here != NULL) {
		here = here->link;
		count++;
	}
	return (count >= maxSize);
}