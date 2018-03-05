/*
 * Vector3f.h
 *
 *  Created on: May 30, 2016
 *      Author: stevosnipes
 */

#ifndef SRC_VECTOR3F_H_
#define SRC_VECTOR3F_H_

class Vector3f{
public:
	//used for struct functions
	struct Vec3{
		float x;
		float y;
		float z;
	};

	float x;
	float y;
	float z;

	static float length(const Vector3f &vec3);
	float length();
	static Vector3f getUnitVector(const Vector3f &vec3);
	static void getUnitVectorThis(Vector3f &vec3);
	void makeThisUnitVector();
	Vector3f getUnitVector();
	static Vector3f add(const Vector3f &left, const Vector3f &right);
	static Vector3f sub(const Vector3f &left, const Vector3f &right);
	static Vector3f scale(const Vector3f &vec3, float scale);
	static void scaleThis(Vector3f &vec3, float scale);
	void scaleThis(float scale);
	Vector3f getScaledVector(float scale);
	static void printVector3f(const Vector3f &vec3);
	void printThis();

	Vector3f();
	Vector3f(float x, float y, float z);
};



#endif /* SRC_VECTOR3F_H_ */
