#include "pch.h"
#include "clockType.h"
#include <iostream>

clockType::clockType() {
	hr = 0;
	min = 0;
	sec = 0;
}

clockType::clockType(int h, int m, int s) {
	hr = h;
	min = m;
	sec = s;
}

void clockType::setTime(int h, int m, int s) {
	hr = h;
	min = m;
	sec = s;
}

void clockType::getTime(int& h, int& m, int& s) {
	h = hr;
	m = min;
	s = sec;
}

void clockType::incrementHours() {
	hr++;
	if (hr >= 24) {
		hr -= 24;
	}
}

void clockType::incrementMinutes() {
	min++;
	if (min >= 60) {
		incrementHours();
		min -= 60;
	}
}

void clockType::incrementSeconds() {
	sec++;
	if (sec >= 60) {
		incrementMinutes();
		sec -= 60;
	}
}

//Operators
std::ostream& operator<<(std::ostream& sout, const clockType& clock) {
	sout << clock.hr << ":" << clock.min << ":" << clock.sec;
	return sout;
}

bool clockType::operator==(const clockType& other) {
	return (hr == other.hr && min == other.min && sec == other.sec);
}