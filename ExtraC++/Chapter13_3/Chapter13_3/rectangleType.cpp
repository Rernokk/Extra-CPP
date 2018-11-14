#include "pch.h"

rectangleType::rectangleType() {
	height = 0;
	width = 0;
}

rectangleType::rectangleType(double w, double h) {
	height = h;
	width = w;
}

void rectangleType::setDimension(double w, double h) {
	height = h;
	width = w;
}

double rectangleType::getWidth() const {
	return width;
}

double rectangleType::getHeight() const {
	return height;
}

double rectangleType::area() const {
	return width * height;
}

double rectangleType::perimeter() const {
	return 2 * (width + height);
}

bool rectangleType::operator==(const rectangleType& rect) const {
	return rect.width == width && rect.height == height;
}

bool rectangleType::operator!= (const rectangleType& rect) const {
	return !(rect.width == width && rect.height == height);
}

ostream& operator<<(ostream& sout, const rectangleType& rect) {
	sout << "Width: " << rect.width << ", Height: " << rect.height;
	return sout;
}