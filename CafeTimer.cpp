// 
// 
// 

#include "CafeTimer.h"


CafeTimer::CafeTimer()
{
	initial_time = 0;
	current_time = 0;
	interval = 0;
	last_interval_time = 0;
	repeat_count = -1;
	is_running = false;
	is_paused = false;
	interval_is_setted = false;
	cbFun = NULL;
	diffTime = 0;
	
}

CafeTimer::~CafeTimer()
{
}

void CafeTimer::start()
{
	if (isPaused()) {
		int paused_time = millis() - current_time;
		current_time = millis();
		initial_time += paused_time;
		last_interval_time += paused_time;
	}
	else {
		reset();
		repeat_count = total_repeat_count;
	}

	is_running = true;
	is_paused = false;
}

void CafeTimer::stop()
{
	is_running = false;
	is_paused = false;
}

void CafeTimer::pause()
{
	is_running = true;
	is_paused = false;
}

void CafeTimer::reset()
{
	initial_time = millis();
	current_time = initial_time;
	last_interval_time = initial_time;
}

void CafeTimer::execute()
{
	
	if (cbFun != NULL) {
		cbFun();
	}
	else {
		Serial.println("DoNothing");
	}
}

bool CafeTimer::isPaused()
{
	return is_paused;
}

bool CafeTimer::isRunning()
{
	return is_running;
}

bool CafeTimer::isStopped()
{
	return !is_paused && !is_running;
}

void CafeTimer::setInterval(unsigned long interval, unsigned int repeat_count)
{
	this->interval = interval;
	this->repeat_count = repeat_count;
	total_repeat_count = repeat_count;
	interval_is_setted = true;
}

void CafeTimer::setInterval(unsigned long interval, GeneralMessageFunction cbFunc)

{
	setInterval(interval, -1);
	setCBFunc(cbFunc);
}

void CafeTimer::clearInterval()
{
	repeat_count = -1;
}

void CafeTimer::setTimeout(unsigned long timeout)
{
	
	setInterval(timeout, 1);
	

}

void CafeTimer::update()
{
	if (is_running) {
		current_time = millis();

		if (interval_is_setted) {
			if (current_time - last_interval_time >= interval) {
				if (repeat_count == 0) {
					stop();
					return;
				}
				else if (repeat_count > 0) {
					repeat_count -= 1;
				}
				execute();  //°õ¦æCallBack
			
				//
				last_interval_time = current_time - diffTime;
				diffTime = 0;

			}
		}
	}
}

void CafeTimer::setCBFunc(GeneralMessageFunction cb_func)
{
	this->cbFun = cb_func;
}

unsigned long CafeTimer::get_last_interval_time()
{
	return last_interval_time;
}

void CafeTimer::setDiffTime(int diffTime)
{
	//Serial.print("DiffTime:");
	//Serial.println(diffTime);
	
	//last_interval_time -= diffTime;
	this->diffTime = diffTime;
}
