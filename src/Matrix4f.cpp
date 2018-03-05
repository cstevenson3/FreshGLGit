/*
h * Matrix4f.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: stevosnipes
 */

#include "Matrix4f.h"

#include <iostream>
#include <cmath>

Matrix4f::MatrixFloats Matrix4f::createMatrix(float floats[16]){
	MatrixFloats mf;
	for(int i=0;i<16;i++){
		mf.matrix[i]=floats[i];
	}
	return mf;
}

void Matrix4f::transpose(MatrixFloats &mat){
	MatrixFloats temp = mat;
	mat.matrix[1]=temp.matrix[4];
	mat.matrix[2]=temp.matrix[8];
	mat.matrix[3]=temp.matrix[12];
	mat.matrix[4]=temp.matrix[1];
	mat.matrix[6]=temp.matrix[9];
	mat.matrix[7]=temp.matrix[13];
	mat.matrix[8]=temp.matrix[2];
	mat.matrix[9]=temp.matrix[6];
	mat.matrix[11]=temp.matrix[14];
	mat.matrix[12]=temp.matrix[3];
	mat.matrix[13]=temp.matrix[7];
	mat.matrix[14]=temp.matrix[11];
}

Matrix4f::MatrixFloats Matrix4f::multiply(MatrixFloats left, MatrixFloats right){
    MatrixFloats result;

    result.matrix[0] = left.matrix[0] * right.matrix[0] + left.matrix[4] * right.matrix[1] + left.matrix[8] * right.matrix[2] + left.matrix[12] * right.matrix[3];
    result.matrix[1] = left.matrix[1] * right.matrix[0] + left.matrix[5] * right.matrix[1] + left.matrix[9] * right.matrix[2] + left.matrix[13] * right.matrix[3];
    result.matrix[2] = left.matrix[2] * right.matrix[0] + left.matrix[6] * right.matrix[1] + left.matrix[10] * right.matrix[2] + left.matrix[14] * right.matrix[3];
    result.matrix[3] = left.matrix[3] * right.matrix[0] + left.matrix[7] * right.matrix[1] + left.matrix[11] * right.matrix[2] + left.matrix[15] * right.matrix[3];

    result.matrix[4] = left.matrix[0] * right.matrix[4] + left.matrix[4] * right.matrix[5] + left.matrix[8] * right.matrix[6] + left.matrix[12] * right.matrix[7];
    result.matrix[5] = left.matrix[1] * right.matrix[4] + left.matrix[5] * right.matrix[5] + left.matrix[9] * right.matrix[6] + left.matrix[13] * right.matrix[7];
    result.matrix[6] = left.matrix[2] * right.matrix[4] + left.matrix[6] * right.matrix[5] + left.matrix[10] * right.matrix[6] + left.matrix[14] * right.matrix[7];
    result.matrix[7] = left.matrix[3] * right.matrix[4] + left.matrix[7] * right.matrix[5] + left.matrix[11] * right.matrix[6] + left.matrix[15] * right.matrix[7];

    result.matrix[8] = left.matrix[0] * right.matrix[8] + left.matrix[4] * right.matrix[9] + left.matrix[8] * right.matrix[10] + left.matrix[12] * right.matrix[11];
    result.matrix[9] = left.matrix[1] * right.matrix[8] + left.matrix[5] * right.matrix[9] + left.matrix[9] * right.matrix[10] + left.matrix[13] * right.matrix[11];
    result.matrix[10] = left.matrix[2] * right.matrix[8] + left.matrix[6] * right.matrix[9] + left.matrix[10] * right.matrix[10] + left.matrix[14] * right.matrix[11];
    result.matrix[11] = left.matrix[3] * right.matrix[8] + left.matrix[7] * right.matrix[9] + left.matrix[11] * right.matrix[10] + left.matrix[15] * right.matrix[11];

    result.matrix[12] = left.matrix[0] * right.matrix[12] + left.matrix[4] * right.matrix[13] + left.matrix[8] * right.matrix[14] + left.matrix[12] * right.matrix[15];
    result.matrix[13] = left.matrix[1] * right.matrix[12] + left.matrix[5] * right.matrix[13] + left.matrix[9] * right.matrix[14] + left.matrix[13] * right.matrix[15];
    result.matrix[14] = left.matrix[2] * right.matrix[12] + left.matrix[6] * right.matrix[13] + left.matrix[10] * right.matrix[14] + left.matrix[14] * right.matrix[15];
    result.matrix[15] = left.matrix[3] * right.matrix[12] + left.matrix[7] * right.matrix[13] + left.matrix[11] * right.matrix[14] + left.matrix[15] * right.matrix[15];

    return result;
}

Matrix4f::MatrixFloats Matrix4f::createTransformation(Vector3f translation, Vector3f rotation, float scale){
	MatrixFloats scaleMatrix = Matrix4f::scalingMatrix(scale);
	MatrixFloats rotationMatrix = Matrix4f::rotationMatrix(rotation);
	MatrixFloats translationMatrix = Matrix4f::translationMatrix(translation);
	return Matrix4f::multiply(translationMatrix,Matrix4f::multiply(rotationMatrix,scaleMatrix));
}

Matrix4f::MatrixFloats Matrix4f::createTransformation(Vector3f translation, Vector3f rotation, float width, float height){
	MatrixFloats scaleMatrix = Matrix4f::scalingMatrix(width,height);
	MatrixFloats rotationMatrix = Matrix4f::rotationMatrix(rotation);
	MatrixFloats translationMatrix = Matrix4f::translationMatrix(translation);
	return Matrix4f::multiply(translationMatrix,Matrix4f::multiply(rotationMatrix,scaleMatrix));
}

Matrix4f::MatrixFloats Matrix4f::rotationMatrix(Vector3f rotation){
	MatrixFloats result = MatrixFloats();
	setIdentity(result);
	double cosx = std::cos(rotation.x);
	double cosy = std::cos(rotation.y);
	double cosz = std::cos(rotation.z);
	double sinx = std::sin(rotation.x);
	double siny = std::sin(rotation.y);
	double sinz = std::sin(rotation.z);
	result.matrix[0]=(float) (cosy*cosz);
	result.matrix[1]=(float) (sinx*siny*cosz+cosx*sinz);
	result.matrix[2]=(float) (-1*cosx*siny*cosz+sinx*sinz);
	result.matrix[4]=(float) (-1*cosy*sinz);
	result.matrix[5]=(float) (-1*sinx*siny*sinz+cosx*cosz);
	result.matrix[6]=(float) (cosx*siny*sinz+sinx*cosz);
	result.matrix[8]=(float) siny;
	result.matrix[9]=(float) (-1*sinx*cosy);
	result.matrix[10]=(float) (cosx*cosy);
	return result;
}

void Matrix4f::printMatrix(MatrixFloats &mat){
	for(int row=0;row<4;row++){
		for(int column=0;column<4;column++){
			std::cout << mat.matrix[column*4+row] << ", ";
		}
		std::cout << std::endl;
	}
}

Vector3f Matrix4f::rotatedCameraDirectionVector(Vector3f rotation, Vector3f direction){
	MatrixFloats cameraMotionMatrix = Matrix4f::cameraMotionMatrix(rotation);
	return multiplyVector3f(cameraMotionMatrix,direction);
}

Vector3f Matrix4f::multiplyVector3f(MatrixFloats left, Vector3f vector) {
	Vector3f result= Vector3f();
	result.x=left.matrix[0]*vector.x+left.matrix[4]*vector.y+left.matrix[8]*vector.z;
	//+left.matrix[12];
	result.y=left.matrix[1]*vector.x+left.matrix[5]*vector.y+left.matrix[9]*vector.z;
	//+left.matrix[13];
	result.z=left.matrix[2]*vector.x+left.matrix[6]*vector.y+left.matrix[10]*vector.z;
	//+left.matrix[14];
	return result;
}

Matrix4f::MatrixFloats Matrix4f::cameraMotionMatrix(Vector3f rotation){
	MatrixFloats result = rotationMatrix(rotation);
	//double cosx = Math.cos(Math.toRadians(rotation.x));
	double cosy = std::cos(rotation.y);
	double cosx = std::cos(rotation.x);
	//double cosz = Math.cos(Math.toRadians(rotation.z));
	double sinx = std::sin(rotation.x);
	double siny = std::sin(rotation.y);
	//double sinz = Math.sin(Math.toRadians(rotation.z));
	/*
	result.matrix[1]=(float) (-sinz);
	result.matrix[5]=1f;
	result.matrix[9]=(float) (-sinx);
	*/
	setIdentity(result);
	result.matrix[0]=(float) cosy;
	result.matrix[1]=(float) 0;
	result.matrix[2]=(float) -siny;
	result.matrix[4]=(float) 0;
	result.matrix[5]=(float) 1;
	result.matrix[6]=(float) 0;
	result.matrix[8]=(float) siny*cosx;
	result.matrix[9]=(float) -sinx;
	result.matrix[10]=(float) -cosx*-cosy;
	return result;
}

Matrix4f::MatrixFloats Matrix4f::translationMatrix(Vector3f translation){
	MatrixFloats result;
	setIdentity(result);
	result.matrix[12]=translation.x;
	result.matrix[13]=translation.y;
	result.matrix[14]=translation.z;
	return result;
}

Matrix4f::MatrixFloats Matrix4f::scalingMatrix(float scale){
	MatrixFloats result = MatrixFloats();
	setIdentity(result);
	result.matrix[0]=scale;
	result.matrix[5]=scale;
	result.matrix[10]=scale;
	return result;
}

Matrix4f::MatrixFloats Matrix4f::scalingMatrix(float x, float y){
	MatrixFloats result = MatrixFloats();
	setIdentity(result);
	result.matrix[0]=x;
	result.matrix[5]=y;
	result.matrix[10]=1;
	return result;
}

void Matrix4f::setIdentity(MatrixFloats &mat){
	mat.matrix[0]=1;
	mat.matrix[1]=0;
	mat.matrix[2]=0;
	mat.matrix[3]=0;
	mat.matrix[4]=0;
	mat.matrix[5]=1;
	mat.matrix[6]=0;
	mat.matrix[7]=0;
	mat.matrix[8]=0;
	mat.matrix[9]=0;
	mat.matrix[10]=1;
	mat.matrix[11]=0;
	mat.matrix[12]=0;
	mat.matrix[13]=0;
	mat.matrix[14]=0;
	mat.matrix[15]=1;
}

Matrix4f::MatrixFloats Matrix4f::createPerspectiveMatrix(float aspectRatio, float fov, float nearPlane, float farPlane) {
	MatrixFloats projectionMatrix = MatrixFloats();
	setIdentity(projectionMatrix);
	projectionMatrix.matrix[0]=(float) ((1/std::tan(fov/2))/aspectRatio);
	projectionMatrix.matrix[5]=(float) ((1/std::tan(fov/2)));
	projectionMatrix.matrix[10]=(float) ((-1*(nearPlane+farPlane))/(farPlane-nearPlane));
	projectionMatrix.matrix[11]=-1;
	projectionMatrix.matrix[14]=(float) ((-2*(nearPlane*farPlane))/(farPlane-nearPlane));
	projectionMatrix.matrix[15]=0;
	return projectionMatrix;
}

Matrix4f::MatrixFloats Matrix4f::createOrthographicMatrix(float right, float left, float top, float bottom, float near, float far) {
	MatrixFloats projectionMatrix = MatrixFloats();
	setIdentity(projectionMatrix);
	projectionMatrix.matrix[0]=2/(right-left);
	projectionMatrix.matrix[5]=2/(top-bottom);
	projectionMatrix.matrix[10]=-2/(far-near);
	projectionMatrix.matrix[12]=-(right+left)/(right-left);
	projectionMatrix.matrix[13]=-(top+bottom)/(top-bottom);
	projectionMatrix.matrix[14]=-(far+near)/(far-near);
	projectionMatrix.matrix[15]=1;
	return projectionMatrix;
}

Matrix4f::MatrixFloats Matrix4f::createViewMatrix(Vector3f position, Vector3f rotation) {
	Vector3f passPosition = Vector3f(-1*position.x,-1*position.y,-1*position.z);
	Vector3f passRotation = Vector3f(-1*rotation.x,-1*rotation.y,-1*rotation.z);
	MatrixFloats rotationMatrix = Matrix4f::rotationMatrix(passRotation);
	MatrixFloats translationMatrix = Matrix4f::translationMatrix(passPosition);
	return(Matrix4f::multiply(rotationMatrix, translationMatrix));
}

Matrix4f::MatrixFloats Matrix4f::lightingBiasMatrix(){
	MatrixFloats result = MatrixFloats();
	setIdentity(result);
	result.matrix[0]=0.5;
	result.matrix[5]=0.5;
	result.matrix[10]=0.5;
	result.matrix[12]=0.5;
	result.matrix[13]=0.5;
	result.matrix[14]=0.5;
	return result;
}

Matrix4f::MatrixFloats Matrix4f::getIdentity(){
	MatrixFloats mat = MatrixFloats();
	mat.matrix[0]=1;
	mat.matrix[1]=0;
	mat.matrix[2]=0;
	mat.matrix[3]=0;
	mat.matrix[4]=0;
	mat.matrix[5]=1;
	mat.matrix[6]=0;
	mat.matrix[7]=0;
	mat.matrix[8]=0;
	mat.matrix[9]=0;
	mat.matrix[10]=1;
	mat.matrix[11]=0;
	mat.matrix[12]=0;
	mat.matrix[13]=0;
	mat.matrix[14]=0;
	mat.matrix[15]=1;
	return mat;
}
