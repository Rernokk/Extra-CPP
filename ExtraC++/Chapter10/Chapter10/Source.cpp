#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//10-11
class personType {
private:
	string firstName = "";
	string middleName = "";
	string lastName = "";

public:
	bool CompareFirstName(string comp) {
		return firstName == comp;
	}
	bool operator==(const personType & rhs) const {
		return lastName == rhs.lastName && firstName == rhs.firstName;
	}
	void SetFirstName(string in)
	{
		firstName = in;
	}
	void SetMiddleName(string in) {
		middleName = in;
	}
	void SetLastName(string in)
	{
		lastName = in;
	}
	void PrintFullName() {
		cout << firstName << " " << middleName << " " << lastName << endl;
	}
};

void TenEleven() {
	personType person1 = personType();
	person1.SetFirstName("Bri");
	person1.SetMiddleName("Lu");
	person1.SetLastName("Kang");

	personType person2 = personType();
	person2.SetFirstName("Brian");
	person2.SetMiddleName("Lu");
	person2.SetLastName("Kang");

	person1.PrintFullName();
	person2.PrintFullName();

	cout << "Comparing:" << endl;
	cout << (person1 == person2 ? "True" : "False") << endl;
}

//10-12
class bookType {
private:
	string title;
	string author[4];
	string publisher;
	int isbn;
	double price;
	int copies;
	int numberAuthors;
public:
	void PrintTitle() {
		cout << title << endl;
	}

	void SetTitle(string in) {
		title = in;
	}

	string GetTitle() {
		return title;
	}

	bool operator==(string & const ref) const {
		return (ref == title);
	}

	void PrintCopies() {
		cout << "Copies in stock: " << copies << endl;
	}

	void SetCopyCount(int amnt) {
		copies = amnt;
	}

	void operator += (int & const amnt) {
		copies += amnt;
	}

	int GetCopyCount() {
		return copies;
	}

	friend ostream& operator<< (ostream& os, bookType & const ref) {
		os << ref.title;
		for (int i = 0; i < 4; i++) {
			if (ref.author[i] != "") {
				os << ", " << ref.author[i];
			}
		}
		cout << ", " << ref.copies << " copies" << endl;
		return os;
	}

	bool operator==(const string & rhs) const {
		return rhs == title;
	}
	
	bookType() {
		title = "";
		for (int i = 0; i < 4; i++) {
			author[i] = "";
		}
		publisher = "";
		isbn = -1;
		price = 0.0;
		copies = 0;
	}

	bookType(string t, string a[4], string p, int i, double pr, int c) {
		title = t;
		for (int i = 0; i < 4; i++) {
			author[i] = a[i];
			if (a[i] != "") {
				numberAuthors++;
			}
		}
		publisher = p;
		isbn = i;
		price = pr;
		copies = c;
	}
};

void TenTwelve() {
	bookType book1 = bookType("The Tell-Tale Heart", new string[4]{ "Edgar Allen Poe","","","" }, "Publisher", 1234, 1.10, 15);
	bookType bookArray[100];

	bookArray[37] = bookType("The Tell-Tale Heart", new string[4]{ "Edgar Allen Poe"," Edgar Allen Zoe","","" }, "Publisher", 1234, 1.10, 15);
	for (int i = 0; i < 100; i++) {
		if (bookArray[i] == "The Tell-Tale Heart") {
			cout << "The book " << bookArray[i].GetTitle() << " is found at index: " << i << endl;
			break;
		}
	}
	cout << book1 << endl;
}

//10-13
class memberType {
	private:
		string name;
		int memberID;
		int booksBought;
		double amntSpent;

	public:
		string GetName()
		{
			return name;
		}
		int GetID() {
			return memberID;
		}
		int GetBooksBought() {
			return booksBought;
		}
		double GetAmountSpent() {
			return amntSpent;
		}

		void SetName(string iName) {
			name = iName;
		}
		void SetID(int iId) {
			memberID = iId;
		}
		void SetBooksBought(int iBooks) {
			booksBought = iBooks;
		}
		void SetAmountSpent(double amnt) {
			amntSpent = amnt;
		}

		friend ostream& operator<< (ostream& os, memberType & const ref) {
			os << ref.memberID << ": " << ref.name << " has bought " << ref.booksBought << " books for a total of $" << fixed << setprecision(2) << ref.amntSpent;
			return os;
		}

		memberType() {
			name = "";
			memberID = -1;
			booksBought = -1;
			amntSpent = 0.0;
		}
		
		memberType(string iName, int iId, int iBooks, double amnt) {
			name = iName;
			memberID = iId;
			booksBought = iBooks;
			amntSpent = amnt;
		}
};
void TenThirteen() {
	memberType newMembers[3] = { memberType("Jay Z", 0, 3, 37.80), memberType("Tim McIlrath", 1, 8, 64.40), memberType("Ozzy Osbourne", 2, 1, 4.20)};
	for (int i = 0; i < 3; i++) {
		cout << newMembers[i] << endl;
	}
}

int main() {
	TenEleven();
	cout << endl;
	TenTwelve();
	cout << endl;
	TenThirteen();

	char c;
	cin >> c;
	return 0;
}