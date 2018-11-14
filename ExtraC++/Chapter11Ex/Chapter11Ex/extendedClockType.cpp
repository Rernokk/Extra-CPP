#include "pch.h"

extendedClockType::extendedClockType() : clockType::clockType() {
	tz = 0;
}

extendedClockType::extendedClockType(int h, int m, int s, int tz){
	this->tz = tz;
	hr = h;
	min = m;
	sec = s;

	hr += tz;
	if (hr > 24) {
		hr -= 24;
	}
	else if (hr < 0) {
		hr += 24;
	}
}

std::ostream& operator<<(std::ostream& sout, const extendedClockType& clock) {
	sout << clock.hr << ":" << clock.min << ":" << clock.sec << "(" << clock.tz << " TZ)";
	return sout;
}