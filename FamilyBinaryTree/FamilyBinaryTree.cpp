#include <iostream>
#include <string>
#include <list>
using namespace std;

class Family_Member {
	struct node {
		int age;
		float height;
		string name;
		node* LChild;
		node* Rchild;
	};
	node* root;
public:
	Family_Member() {
		root = nullptr;
	}
	void insertKey(int age, float height, string name) {
		node* tempNode = root, * newNode;
		while (tempNode != NULL) {
			if (name == tempNode->name) {
				cout << "Key already exists...";
				return;
			}
			else if (name < tempNode->name && tempNode->LChild) {
				tempNode = tempNode->LChild;
			}
			else if (name > tempNode->name&& tempNode->Rchild) {
				tempNode = tempNode->Rchild;
			}
			else {
				break;
			}
		}

		newNode = new node;
		newNode->age = age;
		newNode->height = height;
		newNode->name = name;
		newNode->LChild = newNode->Rchild = NULL;
		if (!root) {
			root = newNode;
		}
		else if (name < tempNode->name) {
			tempNode->LChild = newNode;
		}
		else if (name > tempNode->name) {
			tempNode->Rchild = newNode;
		}

		return;
	}

	void deleteKey(string name) {
		if (root == NULL) {
			cout << "No name in list." << endl;
			return;
		}
		node* tempNode = root, * newNode;
		while (tempNode != NULL) {
			if (name == tempNode->name) {
				break;
			}
			else if (name < tempNode->name && tempNode->LChild) {
				tempNode = tempNode->LChild;
			}
			else if (name > tempNode->name&& tempNode->Rchild) {
				tempNode = tempNode->Rchild;
			}
			else {
				cout << "Name not in family..." << endl;
				return;
			}
		}
		deleteFromRoot(name, root);
	}
	void deleteFromRoot(string name, node*& rootNode) {
		if (name < rootNode->name) {
			deleteFromRoot(name, rootNode->LChild);
		}
		else if (name > rootNode->name) {
			deleteFromRoot(name, rootNode->Rchild);
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
		else if (currentNode->LChild == NULL) {
			tempNode = currentNode;
			currentNode = currentNode->Rchild;
			delete tempNode;
		}
		else if (currentNode->Rchild == NULL) {
			auto_ptr<node> tempNode(currentNode);
			currentNode = currentNode->LChild;
		}
		else {
			tempNode = currentNode->Rchild;
			while (tempNode->LChild) {
				tempNode = tempNode->LChild;
			}
			tempNode->LChild = currentNode->LChild;
			tempNode = currentNode;
			tempNode->Rchild = currentNode->Rchild;
			delete tempNode;
		}
	}

	void searchName(string name) {
		if (root == NULL) {
			cout << "No name in list." << endl;
			return;
		}
		node* tempNode = root, * newNode;
		while (tempNode != NULL) {
			if (name == tempNode->name) {
				cout << tempNode->name << ": Age(" << tempNode->age << "), Height(" << tempNode->height << ")" << endl;
				return;
			}
			else if (name < tempNode->name && tempNode->LChild) {
				tempNode = tempNode->LChild;
			}
			else if (name > tempNode->name&& tempNode->Rchild) {
				tempNode = tempNode->Rchild;
			}
			else {
				cout << "Name not in family..." << endl;
				break;
			}
		}
		return;
	}

	void displayInOrder() {
		if (root == NULL) {
			cout << "No name in list." << endl;
			return;
		}
		inOrder(root);
	}
	node* inOrder(node* currentNode) {
		if (!currentNode) {
			return NULL;
		}
		inOrder(currentNode->LChild);
		cout << currentNode->name << ": Age(" << currentNode->age << "), Height(" << currentNode->height << ")" << endl;
		inOrder(currentNode->Rchild);
	}
};

int main() {
	int option = 0, age;
	float height;
	string name;

	Family_Member family;

	while (option != 6) {
		cout << "Choices:\n" <<
			"1. insert\n" <<
			"2. delete\n" <<
			"3. search\n" <<
			"4. display\n" <<
			"5. exit:\n" <<
			"Option: ";
		cin >> option;
		cin.ignore();
		switch (option) {
		case 1:
			cout << endl << "Insert Name: ";
			getline(cin, name);
			cout << "Insert Age: ";
			cin >> age;
			cout << "Insert Height: ";
			cin >> height;

			family.insertKey(age, height, name);

			break;
		case 2:
			cout << endl << "Delete Name: ";
			getline(cin, name);
			family.deleteKey(name);

			break;
		case 3:
			cout << endl << "Search Name: ";
			getline(cin, name);
			family.searchName(name);
			break;
		case 4:
			cout << endl << "--Display--" << endl;
			family.displayInOrder();
			break;
		case 5:
			return 0;
		default:
			cout << "Option Invalid.";
		};
		cout << endl;
	}

	return 0;
}