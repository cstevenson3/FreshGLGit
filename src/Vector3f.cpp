/*
 * Vector3f.cpp
 *
 *  Created on: May 30, 2016
 *      Author: stevosnipes
 */

#include "Vector3f.h"

#include <cmath>
#include <iostream>

float Vector3f::length(const Vector3f &vec3){
	return (float) std::sqrt(std::pow(vec3.x, 2)+std::pow(vec3.y, 2)+std::pow(vec3.z, 2));
}
float Vector3f::length(){
	return (float) std::sqrt(std::pow(x, 2)+std::pow(y, 2)+std::pow(z, 2));
}
Vector3f Vector3f::getUnitVector(const Vector3f &vec3){
	Vector3f result;
	float magnitude = length(vec3);
	if(magnitude==0){
		result=vec3;
		return result;
	}
	result.x=(float) (vec3.x/magnitude);
	result.y=(float) (vec3.y/magnitude);
	result.z=(float) (vec3.z/magnitude);
	return result;
}
void Vector3f::getUnitVectorThis(Vector3f &vec3){
	float magnitude = length(vec3);
	if(magnitude!=0){
		vec3.x/=magnitude;
		vec3.y/=magnitude;
		vec3.z/=magnitude;
	}
}
void Vector3f::makeThisUnitVector(){
	float magnitude = length();
	if(magnitude!=0){
		x/=magnitude;
		y/=magnitude;
		z/=magnitude;
	}
}
Vector3f Vector3f::getUnitVector(){
	Vector3f result;
	float magnitude = length();
	if(magnitude==0){
		return Vector3f(x,y,z);
	}
	result.x=(float) (x/magnitude);
	result.y=(float) (y/magnitude);
	result.z=(float) (z/magnitude);
	return result;
}
Vector3f Vector3f::add(const Vector3f &left, const Vector3f &right){
	Vector3f result;
	result.x=left.x+right.x;
	result.y=left.y+right.y;
	result.z=left.z+right.z;
	return result;
}
Vector3f Vector3f::sub(const Vector3f &left, const Vector3f &right){
	Vector3f result;
	result.x=left.x-right.x;
	result.y=left.y-right.y;
	result.z=left.z-right.z;
	return result;
}
Vector3f Vector3f::scale(const Vector3f &vec3, float scale){
	Vector3f result;
	result.x=vec3.x*scale;
	result.y=vec3.y*scale;
	result.z=vec3.z*scale;
	return result;
}
void Vector3f::scaleThis(Vector3f &vec3, float scale){
	vec3.x*=scale;
	vec3.y*=scale;
	vec3.z*=scale;
}
void Vector3f::scaleThis(float scale){
	x*=scale;
	y*=scale;
	z*=scale;
}
Vector3f Vector3f::getScaledVector(float scale){
	return Vector3f(x*=scale,y*=scale,z*=scale);
}
void Vector3f::printVector3f(const Vector3f &vec3){
	std::cout << "Vector: " << vec3.x << ", " << vec3.y << ", " << vec3.z << ";" << std::endl;
}
void Vector3f::printThis(){
	std::cout << "Vector: " << x << ", " << y << ", " << z << ";" << std::endl;
}

Vector3f::Vector3f(){
	x=0;
	y=0;
	z=0;
}
Vector3f::Vector3f(float xa, float ya, float za){
	x=xa;
	y=ya;
	z=za;
}


