// IUtil.h
#這是新的註解
#ifndef _IUTIL_h
#define _IUTIL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
typedef void(*GeneralMessageFunction) ();

class ITimeDiff
{
public:
	virtual void setDiffTime(int) = 0;

};

#endif

