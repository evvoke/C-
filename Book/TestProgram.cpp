/*
	Jasdeep Sandhu 121190151
	Project 1
	Assignment 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
using namespace std;

void AddNewBook(vector<Book> *bookdata);
void PrintBooks(vector<Book> &bookdata);
void SortBooks(vector<Book> &bookdata);
void PrintMenu();

int main() {
	vector<Book> bookdata;
	int option = 0;
	
	while (1) {
		PrintMenu();
		cin >> option;
		cin.ignore();
		cout << endl;

		switch (option) {
			case 1:
				AddNewBook(&bookdata);
				cout << endl;
				break;
			case 2:
				SortBooks(bookdata);
				PrintBooks(bookdata);
				cout << endl;
				break;
			case 3:
				return 0;
			default:
				cout << "-- Please Enter A Valid Number! -- " << endl;
				cout << endl;
				break;
		}
	}
}

void AddNewBook(vector<Book> *bookdata) {
	string cin_author, cin_title, cin_date;

	cout << "Enter Title:" << endl;
	getline(cin, cin_title);
	cout << "Enter Author:" << endl;
	getline(cin, cin_author);
	cout << "Enter Date:" << endl;
	getline(cin, cin_date);
	
	Book *newBook;
	newBook = new Book;
	newBook->setData(cin_author, cin_title, cin_date);
	bookdata->push_back(*newBook);

	return;
}

void PrintBooks(vector<Book> &bookdata) {
	cout << "Books Entered: (Sorted Alphabetically by Author)" << endl;

	vector<Book>::iterator iter = bookdata.begin();
	while (iter < bookdata.end()) {
		cout << iter->getAuthor() << "; " <<
				iter->getTitle() << "; " <<
				iter->getDate() << "." << endl;
		iter++;
	}

	return;
}

void SortBooks(vector<Book> &bookdata) {
	sort(bookdata.begin(), bookdata.end());
	return;
}

void PrintMenu() {
	cout << "Select from the following choices:\n";
	cout << "1. Add new book\n";
	cout << "2. Print listing sorted by author\n";
	cout << "3. Quit\n";
	cout << "Choice : ";

	return;
}