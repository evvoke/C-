/*
	Jasdeep Sandhu 121190151
	Project 2
	Assignment 1
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
using namespace std;

class Dictionary
{
public:
	Dictionary();
	Dictionary(string new_word, string new_meaning, string new_synonym, string new_antonym, string new_example_sentence);
	void setData(string new_word, string new_meaning, string new_synonym, string new_antonym, string new_example_sentence);
	string getWord() const;
	string getMeaning() const;
	string getSynonym() const;
	string getAntonym() const;
	string getExampleSentence() const;
private:
	string word, meaning, synonym, antonym, example_sentence;
};

#endif