/*
 * ShaderProgram.h
 *
 *  Created on: Apr 3, 2016
 *      Author: stevosnipes
 */

#ifndef SHADERPROGRAM_H_
#define SHADERPROGRAM_H_

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include "Vector3f.h"
#include "Matrix4f.h"

#include <vector>
#include <string>
using namespace std;

class ShaderProgram{
	//TODO all the shader stuff
private:

public:
	struct Attribute{
		int location;
		string name;
		GLenum type;
	};

	struct Uniform{
		int location;
		string name;
		GLenum type;
	};

	static GLuint loadShaderReturnID(string fileName, GLuint type);
	static GLuint linkProgramReturnID(GLuint vertexShader, GLuint fragmentShader);
	static GLuint getUniformLocation(GLuint programID, char uniformName[]);
	static void loadFloat(int location, float value);
	static void loadInt(int location, int value);
	static void loadVec3(int location, Vector3f value);
	static void loadBoolean(int location, bool value);
	static void loadMatrix(int location, Matrix4f::MatrixFloats value);
	static void start(GLuint programID);
	static void stop();
	static void stop(GLuint programID);
	static void cleanupProgram(GLuint programID, GLuint vertexShaderID, GLuint fragmentShaderID);
	static void printAllAttributes(GLuint programID);
	static vector<Attribute> getAttributes(GLuint programID);
	static vector<Uniform> getUniforms(GLuint programID);
};


#endif /* SHADERPROGRAM_H_ */
