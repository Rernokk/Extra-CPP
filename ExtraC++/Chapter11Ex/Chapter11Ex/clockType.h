#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

#include <iostream>
#include <iomanip>

class clockType
{
	public:
		//Constructors
		clockType() = default;
		clockType(int iHr, int iMin, int iSec);

		//Accessors/Mutators
		void setTime (int iHr, int iMin, int iSec);
		void getTime (int &iHr, int &iMin, int &iSec);

		//Methods
		void printTime();
		void incrementSeconds();
		void incrementMinutes();
		void incrementHours();
		bool equalTime(const clockType& other) const;

	protected:
		int hr;
		int min;
		int sec;
};

#endif