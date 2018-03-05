/*
 * Vector2f.h
 *
 *  Created on: May 20, 2016
 *      Author: stevosnipes
 */

#ifndef SRC_VECTOR2F_H_
#define SRC_VECTOR2F_H_

class Vector2f{
public:
	//used for struct functions
	struct Vec2{
		float x;
		float y;
	};

	float x;
	float y;

	static float length(const Vector2f &vec2);
	float length();
	static Vector2f getUnitVector(const Vector2f &vec2);
	static void getUnitVectorThis(Vector2f &vec2);
	void makeThisUnitVector();
	Vector2f getUnitVector();
	static Vector2f add(const Vector2f &left, const Vector2f &right);
	static Vector2f sub(const Vector2f &left, const Vector2f &right);
	static Vector2f scale(const Vector2f &vec2, float scale);
	static void scaleThis(Vector2f &vec2, float scale);
	void scaleThis(float scale);
	Vector2f getScaledVector(float scale);
	static void printVector2f(const Vector2f &vec2);
	void printThis();

	Vector2f();
	Vector2f(float x, float y);
};



#endif /* SRC_VECTOR2F_H_ */
