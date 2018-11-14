#include "pch.h"
#include <assert.h>

boxType::boxType() : rectangleType() {
	length = 0;
}

boxType::boxType(double l, double w, double h) : rectangleType(w, h) {
	length = l;
}

double boxType::getLength() const {
	return length;
}

void boxType::setDimension(double l, double w, double h) {
	length = l;
	rectangleType::setDimension(w, h);
}

double boxType::volume() const {
	return length * width * height;
}

double boxType::area() const {
	return 2 * (length * width) + 2 * (length * height) + 2 * (width * height);
}

bool boxType::operator==(const boxType& box) const {
	return box.volume() == volume();
}
bool boxType::operator!=(const boxType& box) const {
	return !(box.volume() == volume());
}

boxType boxType::operator+ (const boxType& box) const {
	return boxType(length + box.length, width + box.width, height + box.height);
}
boxType boxType::operator- (const boxType& box) const {
	return boxType(length - box.length, width - box.width, height - box.height);
}
boxType boxType::operator* (const boxType& box) const {
	return boxType(length * box.length, width * box.width, height * box.height);
}
boxType boxType::operator/ (const boxType& box) const {
	return boxType(length / box.length, width / box.width, height / box.height);
}

boxType boxType::operator++() {
	boxType temp = *this;
	length ++;
	width ++;
	height ++;
	return temp;
}

boxType boxType::operator--() {
	boxType temp = *this;
	assert(length <= 1 || height <= 1 || width <= 1);
	length--;
	width--;
	height--;
	return temp;
}

bool boxType::operator<(const boxType& box) const {
	return volume() < box.volume();
}
bool boxType::operator>(const boxType& box) const {
	return volume() > box.volume();
}
bool boxType::operator<=(const boxType& box) const {
	return volume() <= box.volume();
}
bool boxType::operator>=(const boxType& box) const {
	return volume() >= box.volume();
}

ostream& operator<< (ostream& sout, const boxType& box) {
	sout << "Width: " << box.getWidth();
	sout << ", Height: " << box.getHeight();
	sout << ", Length: " << box.getLength();
	return sout;
}

istream  & operator>> (istream& sin, boxType& box) {
	double w, h, l;
	cout << "Length:" << endl;
	sin >> l;
	cout << "Width: " << endl;
	sin >> w;
	cout << "Height: " << endl;
	sin >> h;
	box.setDimension(l,w,h);
	return sin;
}