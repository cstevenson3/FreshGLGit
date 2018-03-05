/*
 * Time.h
 *
 *  Created on: Mar 28, 2016
 *      Author: stevosnipes
 */

#ifndef TIME_H_
#define TIME_H_
#include <iostream>
#include <chrono>
#include <ctime>

class Time{
private:
	//static void setLastTime(int time);
	//static void getTime(int &time);
public:
	static double initTime;
	static double lastDTTime;
	static double dt();
	static void init();
	static double getTime();
	static double timeSinceInit();
	static int sleep(int millis);
	//static long lastTime;
	//static void setInitialTime();
	//static long dt();
	//static float getSystemTimeMillis();
	//static int returnAfterTimeMillis(int time);
};



#endif /* TIME_H_ */
