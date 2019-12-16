#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
	int data;
	QueueNode* link;
};
typedef QueueNode* QueueNodePtr;

class Queue {
private:
	const int maxSize = 10;
	struct QueueNode* front;
	struct QueueNode* back;
public:
	Queue();
	Queue(const Queue& aQueue);
	~Queue();
	void enQueue(int value);
	void deQueue();
	void status();
	bool isEmpty();
	bool isFull();
};

#endif // !QUEUE_H
