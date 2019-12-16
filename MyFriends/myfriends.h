#ifndef FRIENDNODE_H
#define FRIENDNODE_H

#include <iostream>
#include <string>
using namespace std;
class FriendList {
public:
	struct Node {
		string name;
		string birthdate;
		string address;
		string contact_number;
		struct Node* prev;
		struct Node* next;
	};
	typedef Node* NodePtr;
	NodePtr head = NULL;

	FriendList();
	void insert(string name, string birthdate, string address, string contact_number);
	void display();
	void search(string name);
	void remove(string name);
};

#endif // FRIENDNODE_H
