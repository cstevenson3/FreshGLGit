/*
 * Time.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: stevosnipes
 */

#include "Time.h"

#include <iostream>

double Time::initTime=0;
double Time::lastDTTime=0;

void Time::init(){
	initTime = getTime();
	lastDTTime = initTime;
}

double Time::dt(){
	double currentTime = getTime();
	double dt = currentTime - lastDTTime;
	lastDTTime = currentTime;
	return dt;
}

double Time::getTime(){
	std::chrono::time_point<std::chrono::system_clock> start;
	start = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(start.time_since_epoch()).count();
}

double Time::timeSinceInit(){
	return getTime() - initTime;
}
int Time::sleep(int millis){
	double startTime = getTime();
	double currentTime = startTime;
	while(startTime + millis > currentTime){
		currentTime = getTime();
	}
	return 0;
}
