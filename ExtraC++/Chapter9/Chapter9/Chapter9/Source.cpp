#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct comptuerType {
	string manufacturer;
	string modelType;
	string processorType;
	int ram;
	int hdd;
	int year;
	double price;
} typedef ComputerType;

//9-1
void getData(ComputerType * storage) {
	cout << "Manufacturer:" << endl;
	cin >> (*storage).manufacturer;
	cout << "Model Type:" << endl;
	cin >> (*storage).modelType;
	cout << "Processor Type:" << endl;
	cin >> (*storage).processorType;
	cout << "RAM (GB):" << endl;
	cin >> (*storage).ram;
	cout << "HDD Space (GB):" << endl;
	cin >> (*storage).hdd;
	cout << "Year:" << endl;
	cin >> (*storage).year;
	cout << "Price:" << endl;
	cin >> (*storage).price;
	cout << endl;
}

void ProblemNineOne() {
	ComputerType pc;
	getData(&pc);
	cout << pc.manufacturer << endl;
	cout << pc.modelType << endl;
	cout << pc.processorType << endl;
	cout << pc.ram << endl;
	cout << pc.hdd << endl;
	cout << pc.year << endl;
	cout << pc.price << endl;

	char c;
	cin >> c;
}

//9-4
struct menuItemType {
	string menuItem;
	double menuPrice;
} typedef MenuItemType;

void getDataFour(bool * choices) {
	char c;
	for (int i = 0; i < 8; i++){
		cin >> c;
		choices[i] = (c == 't' ? true : false);
	}
}

void showMenu(MenuItemType * menu) {
	for (int i = 0; i < 8; i++){
		cout << menu[i].menuItem << " " << menu[i].menuPrice << endl;
	}
}

void printCheck(MenuItemType * menu, bool * choices) {
	double sumCost = 0.0;
	for (int i = 0; i < 8; i++) {
		if ((choices[i])) {
			cout << menu[i].menuItem << " -> " << menu[i].menuPrice << endl;
			sumCost += menu[i].menuPrice;
		}
	}
	cout << "Taxes: "  << sumCost * .05 << endl;
	cout << "Total: " << sumCost * 1.05 << endl;
}

void ProblemNineFour() {
	cout << fixed << setprecision(2) << endl;
	MenuItemType * menuWrapper;
	menuWrapper = new MenuItemType[8];
	menuWrapper[0].menuItem = "Plain Egg";
	menuWrapper[0].menuPrice = 1.45;
	menuWrapper[1].menuItem = "Bacon and Egg";
	menuWrapper[1].menuPrice = 2.45;
	menuWrapper[2].menuItem = "Muffin";
	menuWrapper[2].menuPrice = 0.99;
	menuWrapper[3].menuItem = "French Toast";
	menuWrapper[3].menuPrice = 1.99;
	menuWrapper[4].menuItem = "Fruit Basket";
	menuWrapper[4].menuPrice = 2.49;
	menuWrapper[5].menuItem = "Cereal";
	menuWrapper[5].menuPrice = 0.69;
	menuWrapper[6].menuItem = "Coffee";
	menuWrapper[6].menuPrice = 0.50;
	menuWrapper[7].menuItem = "Tea";
	menuWrapper[7].menuPrice = 0.75;
	showMenu(menuWrapper);

	bool * menuArray;
	menuArray = new bool [8];
	getDataFour(menuArray);
	printCheck(menuWrapper, menuArray);

	char c;
	cin >> c;
}

//9-5
//void ProblemNineFive() {
//
//}

//Extra Work

//9-2 Struct
struct studentType {
		string studentFName = "first";
		string studentLName = "last";
		int testScore = 0;
		char grade = 'F';
};

void GetStudentData(studentType * sArray) {
	ifstream infile ("studentList.txt");
	string line;
	int counter = 0;
	if (infile.is_open()){
		while (getline(infile, line)) {
			sArray[counter].studentFName = line.substr(0, line.find(','));
			line = line.substr(line.find(',')+1);
			sArray[counter].studentLName = line.substr(0, line.find(','));
			line = line.substr(line.find(',')+1);
			sArray[counter].testScore = stoi(line);
			counter++;
		}
		infile.close();
	}
}

void FindHighestScore(studentType * sArray) {
	vector<string> studentNames;
	int highestGrade = 0;
	for (int i = 0; i < 20; i++) {
		if (sArray[i].testScore >= 90) {
			sArray[i].grade = 'A';
		}
		else if(sArray[i].testScore >= 80) {
			sArray[i].grade = 'B';
		}
		else if(sArray[i].testScore >= 70) {
			sArray[i].grade = 'C';
		}
		else if(sArray[i].testScore >= 60) {
			sArray[i].grade = 'D';
		}
		else {
			sArray[i].grade = 'F';
		}
		if (sArray[i].testScore > highestGrade) {
			highestGrade = sArray[i].testScore;
			studentNames.clear();
			studentNames.push_back(sArray[i].studentLName + ", " + sArray[i].studentFName + ", " + to_string(sArray[i].testScore) + ": " + sArray[i].grade);
		}
		else if (sArray[i].testScore == highestGrade) {
			studentNames.push_back(sArray[i].studentLName + ", " + sArray[i].studentFName + ", " + to_string(sArray[i].testScore) + ": " + sArray[i].grade);
		}
	}

	for (int i = 0; i < 20; i++) {
		cout << sArray[i].studentLName + ", " << sArray[i].studentFName + ", " << to_string(sArray[i].testScore) + ": " + sArray[i].grade << endl;
	}
	cout << endl;
	cout << "Highest Scores: " << endl;
	for (int i = 0; i < studentNames.size(); i++) {
		cout << studentNames[i] << endl;
	}
}

//9-2
void ProbTwo() {
	cout << " -------- Problem Two -------- " << endl;
	
	studentType studentArray[20];
	GetStudentData(studentArray);
	FindHighestScore(studentArray);

	cout << " ------ End Problem Two ------ " << endl;
	char c;
	cin >> c;
}

//9-6
struct characterType {
	char charTypeLower;
	char charTypeUpper;
	int countLower = 0;
	int countUpper = 0;
};

bool OpenFile(ifstream * inFile, ofstream * outFile) {
	inFile->open("SixInFile.txt");
	if (inFile->fail()) {
		cout << "In File not found... Exiting." << endl;
		return false;
	}
	outFile->open("SixOutFile.txt");
	if (outFile->fail()) {
		cout << "Out File not found... Exiting." << endl;
		return false;
	}
	return true;
}

void Count(ifstream * inFile, ofstream * outFile, characterType charArray [26]) {
	char character;
	if (inFile->is_open()) {
		while (inFile->get(character)){
			for (int i = 0; i < 26; i++) {
				if (charArray[i].charTypeUpper == character) {
					charArray[i].countUpper++;
				}
				else if (charArray[i].charTypeLower == character) {
					charArray[i].countLower++;
				}
			}
		}
		inFile->close();
	}
}

void PrintResult(characterType charArray [26]) {
	for (int i = 0; i < 26; i++) {
		double total = charArray[i].countUpper + charArray[i].countLower;
		cout << charArray[i].charTypeUpper << ": " << charArray[i].countUpper << " (" << charArray[i].countUpper / total << "%), " << charArray[i].charTypeLower << ": " << charArray[i].countLower << " (" << charArray[i].countLower / total << "%)";
		cout << endl;
	}
}

void ProbSix() {
	cout << " -------- Problem Six -------- " << endl;
	ifstream inFile;
	ofstream outFile;
	characterType charArray[26];

	for (int i = 0; i < 26; i++) {
		charArray[i].charTypeUpper = (char)(65 + i);
		charArray[i].charTypeLower = tolower(charArray[i].charTypeUpper);
	}

	if (OpenFile(&inFile, &outFile)){
		Count(&inFile, &outFile, charArray);
		PrintResult(charArray);
	}
	cout << endl;
	cout << " ------ End Problem Six ------ " << endl;
	char c;
	cin >> c;
}

//9-7
struct footballPlayerType {
	string name;
	string position;
	int touchdowns;
	int catches;
	double passingYards;
	double receivingYards;
	double rushingYards;
};

void SevenInData() {

}

void FindPlayer() {

}

void SevenOutData() {

}

void DrawMenu() {
	
}

void ProbSeven() {

	cout << " -------- Problem Seven -------- " << endl;

	footballPlayerType playerArray[10];
	DrawMenu();

	cout << " ------ End Problem Seven ------ " << endl;
	char c;
	cin >> c;
}


int main() {
	//ProblemNineOne();
	//ProblemNineFour();
	//ProbTwo();
	//ProbSix();
	ProbSeven();
	return 0;
}