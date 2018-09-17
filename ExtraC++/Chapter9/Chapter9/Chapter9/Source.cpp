#include <iostream>
#include <string>
#include <iomanip>

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
void ProblemNineFive() {

}

int main() {
	//ProblemNineOne();
	ProblemNineFour();
	return 0;
}