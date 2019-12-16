/*
	Jasdeep Sandhu 121190151
	Project 2
	Assignment 1
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Dictionary.h"
using namespace std;

void AddNewWord(map<string, vector<Dictionary>> &dictionaryData);
void PrintWords(map<string, vector<Dictionary>> &dictionaryData);
void FindWord(map<string, vector<Dictionary>> &dictionaryData);
void DeleteWord(map<string, vector<Dictionary>> &dictionaryData);
void PrintMenu();

int main() {
	map<string, vector<Dictionary>, less<string>> dictionaryData;
	int option = 0;
	
	while (1) {
		PrintMenu();
		cin >> option;
		cin.ignore();
		cout << endl;

		switch (option) {
			case 1:
				AddNewWord(dictionaryData);
				cout << endl;
				break;
			case 2:
				PrintWords(dictionaryData);
				cout << endl;
				break;
			case 3:
				FindWord(dictionaryData);
				cout << endl;
				break;
			case 4:
				DeleteWord(dictionaryData);
				cout << endl;
				break;
			case 5:
				return 0;
			default:
				cout << "-- Please Enter A Valid Number! -- " << endl;
				cout << endl;
				break;
		}
	}
}

void AddNewWord(map<string, vector<Dictionary>> &dictionaryData) {
	string cin_word, cin_meaning, cin_synonym, cin_antonym, cin_example_sentence;

	cout << "Enter Word:" << endl;
	getline(cin, cin_word);
	cout << "Enter Meaning:" << endl;
	getline(cin, cin_meaning);
	cout << "Enter Synonym:" << endl;
	getline(cin, cin_synonym);
	cout << "Enter Antonym:" << endl;
	getline(cin, cin_antonym);
	cout << "Enter Example Sentence:" << endl;
	getline(cin, cin_example_sentence);
	
	
	Dictionary *newValues = new Dictionary;
	(*newValues).setData(cin_word, cin_meaning, cin_synonym, cin_antonym, cin_example_sentence);
	dictionaryData[cin_word].push_back(*newValues);
	cout << endl << "--------------------" << endl;
	cout << "'" << cin_word << "' Added To Dictionary";
	cout << endl << "--------------------" << endl;
	
	return;
}

void PrintWords(map<string, vector<Dictionary>> &dictionaryData) {
	cout << "--------------------" << endl;
	cout << "Words Entered: (Sorted Alphabetically by Words)" << endl;

	for (map<string, vector<Dictionary>>::iterator keyIter = dictionaryData.begin(); keyIter != dictionaryData.end(); ++keyIter) {
		cout << endl << "Word: " << (*keyIter).first << endl;
		for (vector<Dictionary>::iterator valueIter = (*keyIter).second.begin(); valueIter != (*keyIter).second.end(); ++valueIter) {
			cout << "Meaning: " << (*valueIter).getMeaning() << endl <<
					"Synonym: " << (*valueIter).getSynonym() << endl <<
					"Antonym: " << (*valueIter).getAntonym() << endl <<
					"Example Sentence: " << (*valueIter).getExampleSentence() << endl;
		}
	}
	cout << "--------------------" << endl;

	return;
}


void FindWord(map<string, vector<Dictionary>> &dictionaryData) {
	string cin_word;

	cout << "Search word: ";
	getline(cin, cin_word);
	cout << "--------------------";

	map<string, vector<Dictionary>>::iterator keyIter = dictionaryData.find(cin_word);

	if (keyIter != dictionaryData.end()) {
		cout << endl << "Word: " << (*keyIter).first << endl;
		vector<Dictionary>::iterator valueIter = (*keyIter).second.begin(); 
		cout << "Meaning: " << (*valueIter).getMeaning() << endl <<
				"Synonym: " << (*valueIter).getSynonym() << endl <<
				"Antonym: " << (*valueIter).getAntonym() << endl <<
				"Example Sentence: " << (*valueIter).getExampleSentence() << endl;
	} else {
		cout << "Word is not in dictionary..." << endl;
	}
	cout << "--------------------" << endl;
}

void DeleteWord(map<string, vector<Dictionary>> &dictionaryData) {
	string cin_word;

	cout << "Delete word: ";
	getline(cin, cin_word);
	cout << "--------------------" << endl;

	map<string, vector<Dictionary>>::iterator keyIter = dictionaryData.find(cin_word);

	if (keyIter != dictionaryData.end()) {
		dictionaryData.erase(cin_word);
		cout << "Word '" << cin_word << "' Deleted" << endl;
	}
	else {
		cout << "Word is not in dictionary..." << endl;
	}
	cout << "--------------------" << endl;
}

void PrintMenu() {
	cout << "Select from the following choices:\n";
	cout << "1. Add new word\n";
	cout << "2. Print listing sorted by word\n";
	cout << "3. Search for word\n";
	cout << "4. Delete word\n";
	cout << "5. Quit\n";
	cout << "Choice : ";

	return;
}