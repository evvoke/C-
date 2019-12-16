#ifndef SORT_H
#define SORT_H

using namespace std;

template <typename T>
class mySort {
private:
	T *n_array;
	int n_count;
public:
	mySort(T *array, int count) {
		n_array = new  T[count];
		n_array = array;
		n_count = count;
	}
	void sortAlgorithm() {
		for (int j = 0; j < n_count; j++) {
			for (int i = 0; i < n_count-1; i++) {
				if (n_array[i] > n_array[i + 1]) {
					mySwap(n_array[i], i, n_array[i + 1], i + 1);
				}
			}
		}
	}
	void mySwap(T value1, int i1, T value2, int i2) {
		n_array[i1] = value2;
		n_array[i2] = value1;
	}
	void printArrays() {
		for (int i = 0; i < n_count; i++) {
			cout << n_array[i] << " ";
		}
		cout << endl;
	}
};

#endif //SORT_H