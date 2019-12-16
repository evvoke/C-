#include <iostream>
#include <map>
#include <string>
#include "Astrology.h"

using namespace std;

void insert(map<string, Astrology> &astrologyData);
void deletion(map<string, Astrology> &astrologyData);
void display(map<string, Astrology> &astrologyData);
void size(map<string, Astrology> &astrologyData);

int main()
{
	map<string, Astrology> astrologyData;
	int option = 0;

	while (1) {
		cout << "Please Select:\n";
		cout << "1. Add new entry\n";
		cout << "2. Delete entry\n";
		cout << "3. Display entry\n";
		cout << "4. Display number of entries\n";
		cout << "5. Quit\n";
		cout << "Choice : ";
		cin >> option;
		cin.ignore();
		cout << endl;

		switch (option) {
		case 1:
			insert(astrologyData);
			cout << endl;
			break;
		case 2:
			deletion(astrologyData);
			cout << endl;
			break;
		case 3:
			display(astrologyData);
			cout << endl;
			break;
		case 4:
			size(astrologyData);
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
	return 0;
}

void insert(map<string, Astrology> &astrologyData) {
	string nStar, nDob, nDailyPrediction;

	cout << "Enter Star:" << endl;
	getline(cin, nStar);
	cout << "Enter Date Of Birth:" << endl;
	getline(cin, nDob);
	cout << "Enter Daily Prediction:" << endl;
	getline(cin, nDailyPrediction);

	Astrology *astroValues = new Astrology;
	astroValues->setStar(nStar);
	astroValues->setDob(nDob);
	astroValues->setDailyPrediction(nDailyPrediction);

	astrologyData.emplace(nStar, *astroValues);
	return;
}

void deletion(map<string, Astrology> &astrologyData) {
	string nStar;
	cout << "Delete Star: ";
	getline(cin, nStar);

	map<string, Astrology>::iterator keyIter = astrologyData.find(nStar);
	if (keyIter != astrologyData.end()) {
		astrologyData.erase(nStar);
		cout << "Star '" << nStar << "' Deleted" << endl;
	}
	else {
		cout << "Star is not in dictionary..." << endl;
	}
	return;
}
void display(map<string, Astrology> &astrologyData) {
	if (astrologyData.size() != 0) {
		for (map<string, Astrology>::iterator keyIter = astrologyData.begin(); keyIter != astrologyData.end(); ++keyIter) {
			keyIter->second.showReadings();
		}
	}
	else {
		cout << "-- There are no entries --" << endl;
	}
	return;
}

void size(map<string, Astrology> &astrologyData) {
	cout << "Size is: " << astrologyData.size() << endl;
	return;
}