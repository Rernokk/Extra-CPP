#ifndef BOXTYPE
#define BOXTYPE

#include "rectangleType.h"
#include <iostream>

using namespace std;

class boxType : public rectangleType
{
	friend ostream& operator<< (ostream& sout, const boxType&);
	friend istream& operator>> (istream& sout, const boxType&);

public:
	boxType();
	boxType(double l, double w, double h);
	~boxType() = default;
	
	double getLength() const;

	void setDimension(double l, double w, double h);
	double volume() const;
	double area() const;
	
	bool operator==(const boxType& box) const;
	bool operator!=(const boxType& box) const;
	bool operator<=(const boxType& box) const;
	bool operator>=(const boxType& box) const;
	bool operator<(const boxType& box) const;
	bool operator>(const boxType& box) const;
	
	boxType operator+(const boxType& box) const;
	boxType operator-(const boxType& box) const;
	boxType operator*(const boxType& box) const;
	boxType operator/(const boxType& box) const;

	boxType operator++();
	boxType operator--();

private:
	double length;

};

#endif