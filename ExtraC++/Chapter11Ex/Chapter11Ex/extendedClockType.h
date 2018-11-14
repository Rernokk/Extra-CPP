#ifndef EXTENDEDCLOCKTYPE_H
#define EXTENDEDCLOCKTYPE_H

#include "clockType.h"

class extendedClockType : public clockType {
	friend std::ostream& operator<<(std::ostream& sout, const extendedClockType& clock);
	public:
		extendedClockType();
		extendedClockType(int iHr, int iMin, int iSec, int tz);

	private:
		int tz;
};

#endif
