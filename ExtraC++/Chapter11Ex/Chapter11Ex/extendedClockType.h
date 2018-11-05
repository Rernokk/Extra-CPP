#ifndef EXTENDEDCLOCKTYPE_H
#define EXTENDEDCLOCKTYPE_H

#include "clockType.h"

class extendedClockType : public clockType {
	public:
		extendedClockType() = default;
		extendedClockType(int iHr, int iMin, int iSec, int tz);
};

#endif
