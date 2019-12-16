#ifndef STACK_H
#define STACK_H

struct StackFrame {
	int data;
	StackFrame* link;
};
typedef StackFrame* StackFramePtr;

class Stack {
private:
	const int maxSize = 10;
	StackFramePtr head;
public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();
	void push(int value);
	void pop();
	bool isempty();
	bool isfull();
	int status();
};

#endif //STACK_H