#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() {}

Stack::~Stack() {
	free(head);
}
void Stack::push(int value) {
	if (isfull()) {
		cout << "Stack is full." << endl;
		return;
	}
	else {
		StackFramePtr tempNode = (struct StackFrame*) malloc(sizeof(struct StackFrame));
		tempNode->data = value;
		tempNode->link = head;
		head = tempNode;
		cout << value << " has been added to the stack." << endl;
	}
}
void Stack::pop() {
	if (isempty()) {
		cout << "Stack is empty." << endl;
		return;
	}
	else {
		cout << "Popped the value:" << head->data << endl;
		head = head->link;
	}
}
bool Stack::isempty() {
	return (head == NULL);
}
bool Stack::isfull() {
	int count = 0;
	StackFramePtr here = head;
	while (here != NULL) {
		here = here->link;
		count++;
	}
	return (count >= maxSize);
}
int Stack::status() {
	int count = 0;
	StackFramePtr here = head;
	while (here != NULL) {
		here = here->link;
		count++;
	}
	return count;
}