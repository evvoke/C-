#include <iostream>
#include <string>
#include "myfriends.h"
using namespace std;

int main() {
	FriendList *testFriendList = new FriendList;
	int option = 0;
	while (option != 5) {
		cout << "Choose An Option:" << endl <<
			"1. Insert Name." << endl <<
			"2. Display Name." << endl <<
			"3. Search Name." << endl <<
			"4. Delete Name." << endl <<
			"5. Exit." << endl <<
			"Option: ";
		cin >> option;

		string name, birthdate, address, contact_number;

		switch (option) {
		case 1:
			cin.ignore();
			cout << endl << "Enter Name: ";
			getline(cin, name); 
			cout << "Enter Birth Date: ";
			getline(cin, birthdate);
			cout << "Enter Address: ";
			getline(cin, address);
			cout << "Enter Contact Number: ";
			getline(cin, contact_number);
			cout << endl;
			testFriendList->insert(name, birthdate, address, contact_number);
			break;
		case 2:
			cout << endl << "List of friends:" << endl;
			testFriendList->display();
			break;
		case 3:
			cout << endl << "Enter name to be searched: ";
			cin >> name;
			testFriendList->search(name);
			break;
		case 4:
			cout << endl << "Enter name to be deleted: ";
			cin >> name;
			testFriendList->remove(name);
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "Enter Valid Option" << endl;
		}

	}
	delete testFriendList;
	return 0;
}