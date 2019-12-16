#include <iostream>
#include <string>
#include <list>
using namespace std;

class Person {
public:
	int ID;
	string name;
};

//linear List start---------------
class List {
	list<Person>* linearList;
public:
	List(int size) {
		linearList = new list<Person>[size];
	}
	void insert(int key, string name) {
		Person* p = new Person;
		p->ID = key;
		p->name = name;
		linearList->push_back(*p);
	}
	void deleteKey(int key) {
		list<Person>::iterator i = linearList->begin();
		for (i; i != linearList->end(); i++) {
			if (i->ID == key) {
				linearList->erase(i);
				break;
			}
		}
	}
	bool searchCost(int key, int cost) {
		list<Person>::iterator i = linearList->begin();
		for (i; i != linearList->end(); i++, cost++) {
			if (i->ID == key) {
				cout << "Linear Cost: " << cost;
				return true;
			}
		}
		cout << "ID not found..." << endl;
		return false;
	}
	void display() {
		list<Person>::iterator i = linearList->begin();
		for (i; i != linearList->end(); i++) {
			cout << "ID: " << i->ID << ", Name: " << i->name << endl;
		}
	}
};
//linear list end ---------------

//hash table start ---------------
class Hash {
private:
	int size;
	list<Person>* hashTable;
public:
	Hash(int size) {
		this->size = size;
		hashTable = new list<Person>[size];
	}
	void insertKey(int key, string name) {
		Person* p = new Person;
		p->ID = key;
		p->name = name;
		int index = getIndex(key);
		hashTable[index].push_back(*p);
	}
	void deleteKey(int key) {
		int index = getIndex(key);
		list<Person>::iterator i = hashTable[index].begin();
		for (i; i != hashTable[index].end(); i++) {
			if (i->ID == key) {
				hashTable[index].erase(i);
				break;
			}
		}
	}
	bool searchKey(int key) {
		int index = getIndex(key);
		list<Person>::iterator i = hashTable[index].begin();
		for (i; i != hashTable[index].end(); i++) {
			if (i->ID == key) {
				cout << "ID: " << i->ID << ", Name: " << i->name << endl;
				return true;
			}
		}
		cout << "ID not found..." << endl;
		return false;
	}
	void searchCost(int key, int cost) {
		int index = getIndex(key);
		list<Person>::iterator i = hashTable[index].begin();
		for (i; i != hashTable[index].end(); i++, cost++) {
			if (i->ID == key) {
				cout << "Hash Cost: " << cost;
				return;
			}
		}
		return;
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << i;
			for (Person x : hashTable[i]) {
				cout << " --> " << x.ID << ":" << x.name;
			}
			cout << endl;
		}
	}
	int getIndex(int value) {
		return (value % size);
	}
};
//hash table end -----------------

//tree start----------------------
struct node {
	int key;
	string name;
	node* left;
	node* right;
};

class Tree {
	node* root;
public:
	Tree() {
		root = nullptr;
	}
	void insertKey(int key, string name) {
		node* tempNode = root, * newNode;
		while (tempNode != NULL) {
			if (key < tempNode->key && tempNode->left) {
				tempNode = tempNode->left;
			}
			else if (key > tempNode->key&& tempNode->right) {
				tempNode = tempNode->right;
			}
			else if (key == tempNode->key) {
				cout << "Key already exists...";
				return;
			}
			else {
				break;
			}
		}

		newNode = new node;
		newNode->key = key;
		newNode->name = name;
		newNode->left = newNode->right = NULL;
		if (!root) {
			root = newNode;
		}
		else if (key < tempNode->key) {
			tempNode->left = newNode;
		}
		else if (key > tempNode->key) {
			tempNode->right = newNode;
		}
		return;
	}
	void displayInOrder() {
		inOrder(root);
	}
	node* inOrder(node* currentNode) {
		if (!currentNode) {
			return NULL;
		}
		inOrder(currentNode->left);
		cout << currentNode->key << ": " << currentNode->name << endl;
		inOrder(currentNode->right);
	}
	void deleteKey(int key) {
		deleteFromRoot(key, root);
	}
	void deleteFromRoot(int key, node*& rootNode) {
		if (key < rootNode->key) {
			deleteFromRoot(key, rootNode->left);
		}
		else if (key > rootNode->key) {
			deleteFromRoot(key, rootNode->right);
		}
		else {
			deleteFromTree(rootNode);
		}
	}
	void deleteFromTree(node*& currentNode) {
		node* tempNode;
		if (currentNode == NULL) {
			cout << "cannot delete empty node";
		}
		else if (currentNode->left == NULL) { 
			tempNode = currentNode;
			currentNode = currentNode->right;
			delete tempNode;
		}
		else if (currentNode->right == NULL) { 
			auto_ptr<node> tempNode(currentNode);
			currentNode = currentNode->left;
		}
		else { 
			tempNode = currentNode->right;
			while (tempNode->left) {
				tempNode = tempNode->left; 
			}
			tempNode->left = currentNode->left; 
			tempNode = currentNode;
			tempNode->right = currentNode->right; 
			delete tempNode;
		}
	}
	void searchCost(int key, int cost) {
		searchCostTree(root, key, cost);
	}
	void searchCostTree(node* currentNode, int key, int cost) {
		if (currentNode == NULL) {
			cout << "Null Node" << endl;
		}
		else if (currentNode->key == key) {
			cout << "Binary Tree Cost: " << cost;
		}
		else if (key < currentNode->key ) {
			searchCostTree(currentNode->left, key, cost++);
		}
		else if (key > currentNode->key) {
			searchCostTree(currentNode->right, key, cost++);
		}
		return;
	}
};
//tree end -----------------------

//main start ---------------------
int main() {
	int option = 0, id, l_cost, t_cost, h_cost;;
	string name;

	Hash h(10);
	List l(20);
	Tree t;

	while (option != 6) {
		cout << "Choices:\n" <<
			"1. insert\n" <<
			"2. search\n" <<
			"3. display\n" <<
			"4. delete\n" <<
			"5. searching cost\n" <<
			"6. exit:\n" <<
			"Option: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "insert ID: ";
			cin >> id;
			cin.ignore();
			cout << "insert Name: ";
			getline(cin, name);

			h.insertKey(id, name);
			t.insertKey(id, name);
			l.insert(id, name);

			break;
		case 2:
			cout << "search ID: ";
			cin >> id;
			h.searchKey(id);
			break;
		case 3:
			cout << "\n--HASH TABLE--" << endl;
			h.display();
			cout << endl << "--BINARY TREE--" << endl;
			t.displayInOrder();
			cout << endl << "--LINEAR SEARCH--" << endl;
			l.display();
			break;
		case 4:
			cout << "delete ID: ";
			cin >> id;
			if (h.searchKey(id)) {
				cout << " -> Deleted!!" << endl;
				h.deleteKey(id);
				t.deleteKey(id);
				l.deleteKey(id);
			}

			break;
		case 5:
			l_cost = h_cost = t_cost = 1;

			cout << "--SEARCH COST--" << endl << "search ID: ";
			cin >> id;
			if (h.searchKey(id)) {
				cout << endl;
				h.searchCost(id, h_cost);
				cout << endl;
				l.searchCost(id, h_cost);
				cout << endl;
				t.searchCost(id, h_cost);
				cout << endl;
			}
			break;
		case 6:
			return 0;
		default:
			cout << "option invalid!";
		};
		cout << endl;
	}

	return 0;
}
//main end -----------------------