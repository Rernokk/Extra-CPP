#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#define SIZE 10

using namespace std;

//8-6
void ProblemSix() {
	ifstream infile("TestFile.txt");
	vector<char[64]> studentIds;
	string answerKey;
	getline(infile, answerKey);

	do {
		string line;
		getline(infile, line);
		if (line.length() > 0) {
			cout << line.substr(0, line.find(' '));
			string answers = line.substr(line.find(' ') + 1);
			double right = 0;
			for (int i = 0; i < answerKey.length(); i++) {
				if (answerKey[i] == answers[i]) {
					right += 2;
				}
				else if (answerKey[i] != ' ') {
					right--;
				}
			}
			int score = 100 * (right / (2 * answerKey.length()));
			cout << " " << score << "% ";
			if (score >= 90) {
				cout << "A" << endl;
			}
			else if (score >= 80) {
				cout << "B" << endl;
			}
			else if (score >= 70) {
				cout << "C" << endl;
			}
			else if (score >= 60) {
				cout << "D" << endl;
			}
			else {
				cout << "F" << endl;
			}
		}
		else {
			break;
		}
	} while (infile.good());
	cout << "End Problem Six" << endl;
}

//8-7
struct candidate {
	string name;
	int votes;
};

void ProblemSeven() {
	int totalVotes = 0;
	candidate candidateList[5];
	for (int i = 0; i < 5; i++) {
		cout << "Candidate: " << endl;
		string name;
		cin >> name;

		cout << "Votes: " << endl;
		int votes;
		cin >> votes;
		totalVotes += votes;

		candidateList[i].name = name;
		candidateList[i].votes = votes;
		cout << endl;
	}

	cout << setw(16) << fixed << left << "Candidate";
	cout << setw(16) << fixed << left << "Votes Received";
	cout << setw(16) << fixed << left << "% of Total Votes" << endl;
	for (int i = 0; i < 5; i++) {
		cout << setw(16) << fixed << left << candidateList[i].name;
		cout << setw(16) << fixed << candidateList[i].votes;
		cout << setw(16) << fixed << setprecision(2) << 100 * ((double)(candidateList[i].votes) / (double)totalVotes);
		cout << endl;
	}
	cout << setw(16) << fixed << "Total";
	cout << setw(16) << fixed << totalVotes << endl;
	cout << endl;
	cout << "The Winner of the Election is ";
	candidate top = candidateList[0];
	for (int i = 1; i < 5; i++) {
		if (candidateList[i].votes > top.votes) {
			top = candidateList[i];
		}
	}
	cout << top.name << "!" << endl;
}

//8-13
void GetStudentData(string namesList[SIZE], int scoreList[SIZE][5], char gradeList[SIZE]) {
	ifstream fin("StudentScores.txt");
	for (int i = 0; i < SIZE; i++) {
		string input;
		getline(fin, input);
		namesList[i] = input.substr(0, input.find(' '));
		input = input.substr(input.find(' ') + 1);
		for (int j = 0; j < 5; j++) {
			if (input.length() > 0) {
				int score = stoi(input.substr(0, input.find(' ')));
				scoreList[i][j] = score;
				if (input.find(' ') != -1) {
					input = input.substr(input.find(' ') + 1);
				}
			}
		}
	}
}

void PrintResults(string names[SIZE], int scores[SIZE][5], char grades[SIZE]) {
	double avg = 0.0;
	for (int j = 0; j < SIZE; j++) {
		cout << names[j] << " ";
		double pAvg = 0.0;
		for (int i = 0; i < 5; i++) {
			pAvg += scores[j][i];
			avg += scores[j][i];
		}
		pAvg *= .2;
		cout << "Average: " << pAvg;

		if (pAvg >= 90) {
			grades[j] = 'A';
		}
		else if (pAvg >= 80) {
			grades[j] = 'B';
		}
		else if (pAvg >= 70) {
			grades[j] = 'C';
		}
		else if (pAvg >= 60) {
			grades[j] = 'D';
		}
		else {
			grades[j] = 'F';
		}
		cout << " Grade: " << grades[j];
		cout << endl;
	}
	avg /= SIZE * 5;
	cout << endl;
	cout << "Class Average: " << avg << endl;
}

void ProblemThirteen() {
	string names[SIZE];
	int scores[SIZE][5];
	char grades[SIZE];

	GetStudentData(names, scores, grades);
	PrintResults(names, scores, grades);
	cout << endl;
}

int main() {
	//ProblemSix();
	//ProblemSeven();
	ProblemThirteen();

	char c;
	cin >> c;
	return 0;
}