/*
	Jasdeep Sandhu 121190151
	Project 1
	Assignment 1
*/

#include "Book.h"

Book::Book() {
	author = "";
	title = "";
	date = "";
}

Book::Book(string new_author, string new_title, string new_date) {
	author = new_author;
	title = new_title;
	date = new_date;
}

void Book::setData(string new_author, string new_title, string new_date) {
	author = new_author;
	title = new_title;
	date = new_date;
}

string Book::getAuthor() const {
	return author;
}

string Book::getTitle() const {
	return title;
}

string Book::getDate() const {
	return date;
}

bool operator< (const Book &book1, const Book &book2) {
	return (book1.author < book2.author);
}