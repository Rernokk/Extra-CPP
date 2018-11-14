#include "pch.h"

using namespace std;

cylinderType::cylinderType() : circleType() {
	height = 0;
};

cylinderType::cylinderType(double r, double h) : circleType(r) {
	height = h;
}

void cylinderType::calculateVolume() {
	volume = area() * height;
}

void cylinderType::calculateSurfaceArea() {
	surfaceArea = area() * 2 + circumference() * height;
}

double cylinderType::getHeight() {
	return height;
}

double cylinderType::getSurfaceArea() {
	calculateSurfaceArea();
	return surfaceArea;
}

double cylinderType::getVolume() {
	calculateVolume();
	return volume;
}

void cylinderType::setHeight(double h) {
	height = h;
}

void cylinderType::setBaseRadius(double r) {
	setRadius(r);
}