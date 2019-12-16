#include <iostream>
#include <string>
#include <list>
using namespace std;

class Student {
public:
	int studentID;
	string name;
	float mark;
};

class Hash {
private:
	int size;
	list<Student>* hashTable;
public:
	Hash(int size) {
		this->size = size;
		hashTable = new list<Student>[size];
	}
	void insertKey(int studentID, string name, float mark) {
		Student* p = new Student;
		p->studentID = studentID;
		p->name = name;
		p->mark = mark;
		int index = getIndex(studentID);
		hashTable[index].push_back(*p);
	}
	void deleteKey(int studentID) {
		int index = getIndex(studentID);
		list<Student>::iterator i = hashTable[index].begin();
		for (i; i != hashTable[index].end(); i++) {
			if (i->studentID == studentID) {
				hashTable[index].erase(i);
				break;
			}
		}
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << i;
			for (Student x : hashTable[i]) {
				cout << " --> Student ID(" << x.studentID << ") Name(" << x.name << ") Mark(" << x.mark << ")";
			}
			cout << endl;
		}
	}
	bool searchID(int studentID) {
		int index = getIndex(studentID);
		list<Student>::iterator i = hashTable[index].begin();
		for (i; i != hashTable[index].end(); i++) {
			if (i->studentID == studentID) {
				cout << "Student ID(" << i->studentID << ") Name(" << i->name << ") Mark(" << i->mark << ")" << endl;
				return true;
			}
		}
		cout << "Student ID not found..." << endl;
		return false;
	}
	int getIndex(int value) {
		return (value % size);
	}
};

int main() {
	int option = 0, studentID, size;
	float mark;
	string name;

	cout << "Class size: ";
	cin >> size;
	Hash h(size);
	cout << endl;

	while (option != 6) {
		cout << "Choices:" << endl <<
			"1. Insert" << endl <<
			"2. Delete" << endl <<
			"3. Display" << endl <<
			"4. Search" << endl <<
			"5. Exit" << endl <<
			"Option: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << endl << "Insert Student ID: ";
			cin >> studentID;
			cin.ignore();
			cout << "Insert Name: ";
			getline(cin, name);
			cout << "Insert Mark: ";
			cin >> mark;

			h.insertKey(studentID, name, mark);

			break;
		case 2:
			cin.ignore();
			cout << endl << "Delete Student ID: ";
			cin >> studentID;
			if (h.searchID(studentID)) {
				h.deleteKey(studentID);
			}
			break;
		case 3:
			cout << endl << "--Display--" << endl;
			h.display();
			break;
		case 4:
			cout << endl << "Search Student ID: ";
			cin >> studentID;
			h.searchID(studentID);
			break;
		case 5:
			return 0;
		default:
			cout << "Option Invalid!";
		};
		cout << endl;
	}

	return 0;
}