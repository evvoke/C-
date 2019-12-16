#include <iostream>
#include <string>
#include "myfriends.h"
using namespace std;

FriendList::FriendList() {}

void FriendList::insert(string name, string birthdate, string address, string contact_number) {
	//create new node and assign values
	NodePtr tempNode = new Node;
	tempNode->name = name;
	tempNode->birthdate = birthdate;
	tempNode->address = address;
	tempNode->contact_number = contact_number;

	//point node as new head
	tempNode->prev = NULL;
	tempNode->next = head;
	if (head != NULL) {
		head->prev = tempNode;
	}
	head = tempNode;
}

void FriendList::display() {
	NodePtr here = head;
	//if empty
	if (head == NULL) {
		cout << "There are no entries yet..." << endl << endl;
		return;
	}

	//print values
	while (here != NULL) {
		cout << "-> " <<
			head->name << ", " <<
			head->birthdate << ", " <<
			head->address << ", " <<
			head->contact_number << endl;
		here = here->next;
	}
	cout << endl;
	return;
}

void FriendList::search(string name) {
	NodePtr here = head;
	//if empty
	if (head == NULL) {
		cout << "List is empty" << endl << endl;
		return;
	}

	//get node that contains value
	while (here->name != name && here->next != NULL) {
		here = here->next;
	}

	//if found, print values
	if (here->name == name) {
		cout << here->name << ", " <<
			here->birthdate << ", " <<
			here->address << ", " <<
			here->contact_number << endl << endl;
		return;
	}

	//if not found
	cout << name << " is not on the list" << endl << endl;
	return;
}

void FriendList::remove(string name) {
	//if empty
	if (head == NULL) {
		cout << "There are no entries to remove" << endl << endl;
		return;
	}

	Node* here = head;

	//if head contains node
	if (head->name == name) {
		//if head is only node
		if (head->next == NULL) {
			head = NULL;
			cout << name << " has been deleted from the list" << endl << endl;
			return;
		}
		//if there are more nodes besides head
		else {
			head->next->prev = NULL;
			head = head->next;
			here->next = NULL;
			cout << name << " has been deleted from the list" << endl << endl;
			return;
		}
	}

	//find node containing name to delete
	while (here->name != name && here->next != NULL) {
		here = here->next;
	}

	//if node contains name
	if (here->name == name) {
		//if next node is present
		if (here->next != NULL) {
			here->next->prev = here->prev;
		}
		//if previous node is present
		if (here->prev != NULL) {
			here->prev->next = here->next;
		}
		cout << name << " has been deleted from the list" << endl << endl;
		return;
	}

	//if not found in list
	if (here->next == NULL) {
		cout << "There are no entries containing that name" << endl << endl;
		return;
	}

	return;
}

