/*
 * Matrix4f.h
 *
 *  Created on: May 27, 2016
 *      Author: stevosnipes
 */

#ifndef SRC_MATRIX4F_H_
#define SRC_MATRIX4F_H_

#include "Vector2f.h"
#include "Vector3f.h"

class Matrix4f{
public:
	struct MatrixFloats{
		float matrix[16];
	};
	static MatrixFloats createMatrix(float floats[]);
	static void printMatrix(MatrixFloats &mat);
	static Vector3f rotatedCameraDirectionVector(Vector3f rotation, Vector3f direction);
	static Vector3f multiplyVector3f(MatrixFloats left, Vector3f vector);
	static MatrixFloats cameraMotionMatrix(Vector3f rotation);
	static MatrixFloats createPerspectiveMatrix(float aspectRatio, float fov, float nearPlane, float farPlane);
	static MatrixFloats createOrthographicMatrix(float right, float left, float top, float bottom, float near, float far);
	static MatrixFloats createViewMatrix(Vector3f position, Vector3f rotation);
	static MatrixFloats lightingBiasMatrix();
	static void transpose(MatrixFloats &mat);
	static MatrixFloats multiply(MatrixFloats left, MatrixFloats right);
	static MatrixFloats createTransformation(Vector3f translation, Vector3f rotation, float scale);
	static MatrixFloats createTransformation(Vector3f translation, Vector3f rotation, float width, float height);
	static MatrixFloats rotationMatrix(Vector3f rotation);
	static MatrixFloats translationMatrix(Vector3f translation);
	static MatrixFloats scalingMatrix(float scale);
	static MatrixFloats scalingMatrix(float x, float y);
	static void setIdentity(MatrixFloats &mat);
	static MatrixFloats getIdentity();
};



#endif /* SRC_MATRIX4F_H_ */
