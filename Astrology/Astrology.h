#ifndef ASTROLOGY_H
#define ASTROLOGY_H

using namespace std;

class Astrology {
	private:
		string star, dob, dailyPrediction;
	public:
		Astrology() {
			star = "";
			dob = ""; 
			dailyPrediction = "";
		}
		void setStar(string nStar) {
			star = nStar;
			return;
		}
		void setDob(string nDob) {
			dob = nDob;
			return;
		}
		void setDailyPrediction(string nDailyPrediction) {
			dailyPrediction = nDailyPrediction;
			return;
		}
		string getStar() {
			return star;
		}
		string getDob() {
			return dob;
		}
		string getDailyPrediction() {
			return dailyPrediction;
		}
		void showReadings() {
			cout << "Star: " << getStar() << endl <<
					"Date of Birth: " << getDob() << endl <<
					"Reading: " << getDailyPrediction() << endl << endl;
			return;
		}
};

#endif //ASTROLOGY_H
