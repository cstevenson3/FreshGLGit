/*
 * Vector2f.cpp
 *
 *  Created on: May 20, 2016
 *      Author: stevosnipes
 */

#include "Vector2f.h"

#include <cmath>
#include <iostream>

float Vector2f::length(const Vector2f &vec2){
	return (float) std::sqrt(std::pow(vec2.x, 2)+std::pow(vec2.y, 2));
}
float Vector2f::length(){
	return (float) std::sqrt(std::pow(x, 2)+std::pow(y, 2));
}
Vector2f Vector2f::getUnitVector(const Vector2f &vec2){
	Vector2f result;
	float magnitude = length(vec2);
	if(magnitude==0){
		result=vec2;
		return result;
	}
	result.x=(float) (vec2.x/magnitude);
	result.y=(float) (vec2.y/magnitude);
	return result;
}
void Vector2f::getUnitVectorThis(Vector2f &vec2){
	float magnitude = length(vec2);
	if(magnitude!=0){
		vec2.x/=magnitude;
		vec2.y/=magnitude;
	}
}
void Vector2f::makeThisUnitVector(){
	float magnitude = length();
	if(magnitude!=0){
		x/=magnitude;
		y/=magnitude;
	}
}

Vector2f Vector2f::getUnitVector(){
	Vector2f result;
	float magnitude = length();
	if(magnitude==0){
		return Vector2f(x,y);
	}
	result.x=(float) (x/magnitude);
	result.y=(float) (y/magnitude);
	return result;
}

Vector2f Vector2f::add(const Vector2f &left, const Vector2f &right){
	Vector2f result;
	result.x=left.x+right.x;
	result.y=left.y+right.y;
	return result;
}
Vector2f Vector2f::sub(const Vector2f &left, const Vector2f &right){
	Vector2f result;
	result.x=left.x-right.x;
	result.y=left.y-right.y;
	return result;
}
Vector2f Vector2f::scale(const Vector2f &vec2, float scale){
	Vector2f result;
	result.x=vec2.x*scale;
	result.y=vec2.y*scale;
	return result;
}
void Vector2f::scaleThis(Vector2f &vec2, float scale){
	vec2.x*=scale;
	vec2.y*=scale;
}
void Vector2f::scaleThis(float scale){
	x*=scale;
	y*=scale;
}
Vector2f Vector2f::getScaledVector(float scale){
	return Vector2f(x*=scale,y*=scale);
}
void Vector2f::printVector2f(const Vector2f &vec2){
	std::cout << "Vector: " << vec2.x << ", " << vec2.y << ", " << ";" << std::endl;
}
void Vector2f::printThis(){
	std::cout << "Vector: " << x << ", " << y << ", " << ";" << std::endl;
}

Vector2f::Vector2f(){
	x=0;
	y=0;
}
Vector2f::Vector2f(float xa, float ya){
	x=xa;
	y=ya;
}


