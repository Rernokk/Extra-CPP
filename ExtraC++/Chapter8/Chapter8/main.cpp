//Chapter 8 Problems

#include <string>
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

//Prototype Delcarations
void problemOne();
void problemFour();
void problemNine();

//Main Overall Chapter
int main() {
	int prompt = 0;
	int numberArray[3] = {1, 4, 9};

	cout << "Problem :" << endl;
	for (int i = 1; i <= size(numberArray); i++) {
		cout << "[" << i << "]: 8-" << numberArray[i-1] << endl;
	}

	cin >> prompt;
	switch (prompt) {
		case (1):
			problemOne();
			break;
		case (2):
			problemFour();
			break;
		case (3):
			problemNine();
			break;
	}

	cout << "End Output." << endl;
	cin >> prompt;
	return 0;
}

void problemOne() {
	double alpha[50];
	for (int i = 0; i < size(alpha); i++) {
		if (i < 25) {
			alpha[i] = i * i;
		}
		else {
			alpha[i] = i * 3;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << alpha[i * 10 + j] << " ";
		}
		cout << endl;
	}
	cout << "End Problem One" << endl;
}

void problemFour() {
	int studentArray[8] = {0};
	double input;
	do {
		cin >> input;
		if (input >= 0){
			if (input == 200) {
				studentArray[7]++;
			} else {
				studentArray[(int)floorf(input / 25.0)]++;
			}
		}
	} while (input != -1);

	for (int i = 0; i < 8; i++) {
		if (i == 7) {
			cout << 200 * (i / 8.0) << "-" << 200 * (i / 8.0) + 25 << ": " << studentArray[i] << endl;
		} else {
			cout << 200 * (i / 8.0) << "-" << 200 * (i / 8.0) + 24 << ": " << studentArray[i] << endl;
		}
	}
	cout << "End Problem Four" << endl;
}

//Problem Nine
void getData(int ** arrayData) {
	for (int i = 0; i < 12; i++) {
		int hVal;
		int lVal;

		cout << "Highest: " << endl;
		cin >> hVal;
		cout << "Lowest: " << endl;
		cin >> lVal;

		arrayData[i][0] = hVal;
		arrayData[i][1] = lVal;
	}
}

void averageHigh(int ** data) {
	double sum = 0.0;
	for (int i = 0; i < 12; i++) {
		sum += data[i][0];
	}

	cout << "Average High: " << sum / 12.0 << endl;
}

void averageLow(int ** data) {
	double sum = 0.0;
	for (int i = 0; i < 12; i++) {
		sum += data[i][1];
	}

	cout << "Average Low: " << sum / 12.0 << endl;

}

void indexHighTemp(int ** data) {
	int indHighest = 0;
	int highestTemp = 0;
	for (int i = 0; i < 12; i++) {
		if (data[i][0] > highestTemp) {
			highestTemp = data[i][0];
			indHighest = i;
		}
	}

	cout << "Highest Index: " << indHighest << endl;
}

void indexLowTemp(int ** data) {
	int indLowest = 0;
	int lowestTemp = 10000;
	for (int i = 0; i < 12; i++) {
		if (data[i][0] < lowestTemp) {
			lowestTemp = data[i][1];
			indLowest = i;
		}
	}

	cout << "Lowest Index: " << indLowest << endl;

}

void problemNine() {
	int ** temperatureArray;
	temperatureArray = new int *[12];
	for (int i = 0; i < 12; i++) {
		temperatureArray[i] = new int[2];
	}
	getData(temperatureArray);

	averageHigh(temperatureArray);
	averageLow(temperatureArray);
	indexHighTemp(temperatureArray);
	indexLowTemp(temperatureArray);

	cout << "End Problem 9" << endl;
}