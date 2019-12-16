/*
	Jasdeep Sandhu 121190151
	Project 2
	Assignment 1
*/

#include "Dictionary.h"

Dictionary::Dictionary() {
	word = "";
	meaning = "";
	synonym = "";
	antonym = "";
	example_sentence = "";
}

Dictionary::Dictionary(string new_word, string new_meaning, string new_synonym, string new_antonym, string new_example_sentence) {
	word = new_word;
	meaning = new_meaning;
	synonym = new_synonym;
	antonym = new_antonym;
	example_sentence = new_example_sentence;
}

void Dictionary::setData(string new_word, string new_meaning, string new_synonym, string new_antonym, string new_example_sentence) {
	word = new_word;
	meaning = new_meaning;
	synonym = new_synonym;
	antonym = new_antonym;
	example_sentence = new_example_sentence;
}

string Dictionary::getWord() const {
	return word;
}

string Dictionary::getMeaning() const {
	return meaning;
}

string Dictionary::getSynonym() const {
	return synonym;
}

string Dictionary::getAntonym() const {
	return antonym;
}

string Dictionary::getExampleSentence() const {
	return example_sentence;
}