// 
// 
// 

#include "CafeButton.h"


CafeButton::CafeButton(byte pin)
{
	this->pin = pin;
	this->buttonState = 1;
	this->lastButtonState = 1;
	this->diff = NULL;  // ®É¶¡®t¤¶­±
	pinMode(pin, INPUT);
}

CafeButton::~CafeButton()
{
}

int CafeButton::readValue()
{
	return digitalRead(pin);
}

void CafeButton::setInitHighOrLow(byte HIGHorLOW)
{
	this->buttonState = HIGHorLOW;
	this->lastButtonState = HIGHorLOW;

}

void CafeButton::click(GeneralMessageFunction cbFun)
{
	buttonState = readValue();
	

	// compare the buttonState to its previous state
	if (buttonState != lastButtonState) {
		// if the state has changed, increment the counter
		if (buttonState == LOW) {
			// if the current state is HIGH then the button went from off to on:
			buttonPushCounter++;
			//Serial.println("on");
			

		}
		else {
			// if the current state is LOW then the button went from on to off:
			if (buttonPushCounter > 0) {
				buttonPushCounter = 0;
				//Serial.println("Run callBack Function");
				cbFun();
			}
			
		}
		// Delay a little bit to avoid bouncing
		//Serial.print("delay:");
		//Serial.println(bouncing);
		if ( diff != NULL) {
		  diff->setDiffTime(bouncing);
		}
		delay(bouncing);

		
	}
	lastButtonState = buttonState;
}

void CafeButton::setBouncing(int bouncing)
{
	this->bouncing = bouncing;
}

byte CafeButton::getButtonState()
{
	return this->buttonState;
}

void CafeButton::setITimeDiff(ITimeDiff * idiff)
{
	this->diff = idiff;
}
