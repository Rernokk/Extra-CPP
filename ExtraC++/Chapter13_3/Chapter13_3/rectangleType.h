#ifndef RECTTYPE
#define RECTTYPE

#include <iostream>

using namespace std;

class rectangleType {
	friend ostream& operator<< (ostream& sout, const rectangleType&);
public:
	rectangleType();
	rectangleType(double w, double h);

	double area() const;
	double perimeter() const;
	void setDimension(double w, double h);

	double getHeight() const;
	double getWidth() const;
	
	bool operator == (const rectangleType&) const;
	bool operator != (const rectangleType&) const;

protected:
	double width;
	double height;
};

#endif