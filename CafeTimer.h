// CafeTimer.h

#ifndef _CAFETIMER_h
#define _CAFETIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <inttypes.h>
#include "IUtil.h"


class CafeTimer : public ITimeDiff
{
public:
	CafeTimer();
	~CafeTimer();
	void execute();
	//
	void start();
	void stop();
	void pause();
	void reset();
	
	

	bool isPaused();
	bool isRunning();
	bool isStopped();
	void setInterval(unsigned long interval, unsigned int repeat_count = -1);
	void setInterval(unsigned long interval, GeneralMessageFunction cbFunc);
	void clearInterval();
	void setTimeout(unsigned long timeout);
	void update();
	//
	void setCBFunc(GeneralMessageFunction);
	unsigned long get_last_interval_time();
	void setDiffTime(int);  //設定時間差
private:
	unsigned long initial_time;
	unsigned long current_time;

	bool is_running;
	bool is_paused;

	unsigned long interval;
	unsigned long last_interval_time;
	unsigned int repeat_count;
	unsigned int total_repeat_count;
	bool interval_is_setted;
	GeneralMessageFunction cbFun;
	unsigned int diffTime = 0;


};



#endif

