#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

#include <iostream>
#include <iomanip>

class clockType
{
	friend std::ostream& operator<<(std::ostream& sout, const clockType& clock);

	public:
		//Constructors
		clockType();
		clockType(int iHr, int iMin, int iSec);

		//Accessors/Mutators
		void setTime (int iHr, int iMin, int iSec);
		void getTime (int &iHr, int &iMin, int &iSec);

		//Methods
		void incrementSeconds();
		void incrementMinutes();
		void incrementHours();

		bool operator==(const clockType& other);

	protected:
		int hr;
		int min;
		int sec;
};

#endif