// CafeButton.h

#ifndef _CAFEBUTTON_h
#define _CAFEBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <inttypes.h>
#include "IUtil.h"

class CafeButton
{
public:
	CafeButton(byte);
	~CafeButton();
	int readValue();
	void setInitHighOrLow(byte);
	void click(GeneralMessageFunction);
	void setBouncing(int);
	byte getButtonState();
	void setITimeDiff(ITimeDiff*);
	
private:
	byte buttonState = 1;         // current state of the button
	byte lastButtonState = 1;     // previous state of the button
	byte pin;
	byte buttonPushCounter = 0;
	int bouncing = 50;  //default bouncing 50
	ITimeDiff *diff = NULL;  //
	
};

#endif

