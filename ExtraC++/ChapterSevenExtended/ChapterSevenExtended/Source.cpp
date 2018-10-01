#include <string>
#include <iostream>

using namespace std;

string AdjustInput(string in) {
	string rem = in;
	string last = in.substr(0, in.find(','));
	rem = in.substr(in.find(',') + 1);
	string first = rem.substr(0, in.find(','));
	rem = rem.substr(rem.find(',') + 1);
	string reordered = first + " " + rem + " " + last;
	cout << reordered << endl;
	return reordered;
}

void ChapterSevenNine() {
	string input;
	cout << "Last, First, Middle" << endl;
	cin >> input;
	input = AdjustInput(input);
}

void ChapterSevenTen() {
	//Oil sits in water
	//Prompts:
		//Oil Rate per Minute
		//Thickness of Oil
		//Days Surface Covered
	double oilRate;
	double surfaceThickness;
	double daysCovered;
	const double gallToCCm = 3785.41;

	cout << "Enter the rate at which the ruptured pipe is spilling oil (Gallons per minute): " << endl;
	cin >> oilRate;

	cout << "Enter the thickness of the oil on the surface of the water (in cm): " << endl;
	cin >> surfaceThickness;
	
	cout << "Enter the number of days for which the area is covered by the oil: " << endl;
	cin >> daysCovered;
	
	//Outputs for each day:
		//Area (KM)
		//Volume (Gallons)
	
	double volume = (oilRate * gallToCCm * (24 * 60 * daysCovered));
	double surfaceArea = volume / surfaceThickness;

	cout << "Surface Area (km2): " << surfaceArea / 10000000000 << endl;
	cout << "Volume (Gallons): " << volume / gallToCCm << endl;
}

void ChapterSevenEleven() {
	cout << "Enter a string: " << endl;
	string in;
	cin >> in;
	cout << endl;
	int ascii = 0;
	for (int i = 0; i < size(in); i++) {
		ascii += (int)in[i];
	}
	cout << "ASCII Value: " << ascii << endl;
}

int main() {
	char pause;
	cout << " --- Problem 9 --- " << endl;
	ChapterSevenNine();
	cout << " --- End Problem 9 --- " << endl << endl;

	cout << " --- Problem 10 --- " << endl;
	ChapterSevenTen();
	cout << " --- End Problem 10 --- " << endl << endl;

	cout << " --- Problem 11 --- " << endl;
	ChapterSevenEleven();
	cout << " --- End Problem 11 --- " << endl << endl;

	cout << "Pause..." << endl;
	cin >> pause;
	return 0;
}