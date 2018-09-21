#include "IUtil.h"
#include "CafeTimer.h"
#include "CafeButton.h"

#define BOUNCING 50
CafeTimer timer;
CafeButton button(3); //Button Pin 3

void setup()
{

  /* add setup code here */
	Serial.begin(9600);
	Serial.println("Here");
	timer.start();
	//timer.setCBFunc(hello);
	timer.setInterval(1000, hello);
	button.setBouncing(BOUNCING);
	button.setITimeDiff(&timer);
	


}
unsigned long timerCount = 0;
unsigned long last_time;
void hello() {
	
	timerCount++;
	Serial.println(timerCount);
	//last_time = timer.get_last_interval_time();
	//Serial.println(last_time);
}
void buttonClick() {

	timer.setDiffTime(BOUNCING);
	Serial.println("Click");
}


void loop()
{

  /* add main program code here */
	
	//delay(1000);
	//timer.execute();
	timer.update();
	byte value = button.readValue();
	//
	//delay(1000);
	button.click(buttonClick);
	

}
