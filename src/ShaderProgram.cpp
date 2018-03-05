/*
 * ShaderProgram.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: stevosnipes
 */

#define GLEW_STATIC
#include <GL/glew.h>
#include "ShaderProgram.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

FilePreloader ShaderProgram::files = FilePreloader(MAX_SHADERS);

GLuint ShaderProgram::linkProgramReturnID(GLuint vertexShaderID, GLuint fragmentShaderID){
	GLuint programID = glCreateProgram();
	glAttachShader(programID,vertexShaderID);
	glAttachShader(programID,fragmentShaderID);

	GLchar infoLog[512];

	glLinkProgram(programID);
	GLint linkSuccess;
	glGetProgramiv(programID,GL_VALIDATE_STATUS,&linkSuccess);
	if(linkSuccess==GL_FALSE){
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		cout << "ShaderProgram: linking of program " << programID << " failed"<< endl; //TODO absolutely ulysess
		cout << infoLog << endl;
	}

	glValidateProgram(programID);
	GLint validateSuccess;
	glGetProgramiv(programID,GL_VALIDATE_STATUS,&validateSuccess);
	if(validateSuccess==GL_FALSE){
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		cout << "ShaderProgram: validation of program " << programID << " failed"<< endl; //TODO absolutely ulysess
		cout << infoLog << endl;
	}
	return programID;
}

GLuint ShaderProgram::loadShaderReturnID(string fileName, GLuint type){
	vector<string> shaderVector = files.getFile(fileName);
	string shaderSource;
	string line;
	for(unsigned int i = 0; i < shaderVector.size(); i++){
		line = shaderVector[i];
		if(line.empty()){
			continue;
		}
		shaderSource.append(line).append("\n");
	}
	const GLchar* shaderCode = shaderSource.c_str();
	/* working code
	string code;
	ifstream shaderFile;
	shaderFile.exceptions(ifstream::badbit);
	try
	{
		shaderFile.open(fileName.c_str());
		stringstream shaderStream;;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		code = shaderStream.str();
	}
	catch(ifstream::failure &e)
	{
		cout << "ShaderProgram: Shader not read- " << fileName << endl;
	}
	const GLchar* shaderCode = code.c_str();
	//cout << code.c_str() << endl;
	end working code */
	/*

	ifstream infile(fileName);
	if(!infile.is_open()){
		cout << "file not open" << endl;
	}
	string shaderSource;
	string line;
	while(getline(infile,line)){
		if(line.empty()){
			continue;
		}
		//cout<<line.c_str()<<endl;
		shaderSource.append(line).append("\n");
	}
	infile.close();
	const GLchar* shaderCode = shaderSource.c_str();
	cout << shaderCode << endl;
	*/
	GLuint shaderID = glCreateShader(type);
	glShaderSource(shaderID,1,&shaderCode,NULL);
	glCompileShader(shaderID);
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		cout << "ShaderProgram: shader compilation failed" << endl;
		cout << infoLog << endl;
	};
	return shaderID;
}

void ShaderProgram::start(GLuint programID){
	glUseProgram(programID);
}

void ShaderProgram::stop(){
	glUseProgram(0);
}

void ShaderProgram::stop(GLuint programID){
	glUseProgram(0);
}

void ShaderProgram::cleanupProgram(GLuint programID, GLuint vertexShaderID, GLuint fragmentShaderID){
	stop(programID);
	glDetachShader(programID,vertexShaderID);
	glDetachShader(programID,fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	glDeleteProgram(programID);
}

GLuint ShaderProgram::getUniformLocation(GLuint programID, char uniformName[]){
	return glGetUniformLocation(programID,uniformName);
}

void ShaderProgram::loadMatrix(int location, Matrix4f::MatrixFloats mat4){
	glUniformMatrix4fv(location,1,false,mat4.matrix);
}

void ShaderProgram::loadFloat(int location, float value){
	glUniform1f(location,value);
}

void ShaderProgram::loadInt(int location, int value){
	glUniform1i(location,value);
}

void ShaderProgram::loadVec3(int location, Vector3f value){
	glUniform3f(location,value.x,value.y,value.z);
}

void ShaderProgram::loadBoolean(int location, bool value){
	glUniform1f(location,value?1:0);
}

void ShaderProgram::printAllAttributes(GLuint programID){
	GLint i;
	GLint count;

	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)

	GLsizei bufSize = 256; // maximum name length
	//glGetProgramiv(programID,GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &bufSize);

	GLchar name[bufSize]; // variable name in GLSL
	GLsizei length; // name length

	glGetProgramiv(programID, GL_ACTIVE_UNIFORMS, &count);
	printf("Active Uniforms: %d\n", count);

	for (i = 0; i < count; i++)
	{
	    glGetActiveUniform(programID, (GLuint)i, bufSize, &length, &size, &type, name);
	    printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
	    cout << glGetUniformLocation(programID,name) << endl;
	    cout << endl;
	}

	glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &count);
	printf("Active Attributes: %d\n", count);

	for (i = 0; i < count; i++)
	{
	    glGetActiveAttrib(programID, (GLuint)i, bufSize, &length, &size, &type, name);
	    printf("Attribute #%d Type: %u Name: %s\n", i, type, name);
	}
}

vector<ShaderProgram::Attribute> ShaderProgram::getAttributes(GLuint programID){
	GLint numberOfAttributes;
	glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &numberOfAttributes);

	vector<Attribute> result = vector<Attribute>();

	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)

	GLsizei bufSize = 256; // maximum name length
	//glGetProgramiv(programID,GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &bufSize);

	GLchar name[bufSize]; // variable name in GLSL
	GLsizei length; // name length

	for(int i = 0; i < numberOfAttributes; i++){
		glGetActiveAttrib(programID, (GLuint)i, bufSize, &length, &size, &type, name);
		Attribute attribute;
		attribute.location = i;
		attribute.type = type;
		attribute.name = name;
		result.push_back(attribute);
	}
	return result;
}

vector<ShaderProgram::Uniform> ShaderProgram::getUniforms(GLuint programID){
	GLint numberOfUniforms;
	glGetProgramiv(programID, GL_ACTIVE_UNIFORMS, &numberOfUniforms);

	vector<Uniform> result = vector<Uniform>();

	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)

	GLsizei bufSize = 256; // maximum name length
	//glGetProgramiv(programID,GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &bufSize);

	GLchar name[bufSize]; // variable name in GLSL
	GLsizei length; // name length

	for(int i = 0; i < numberOfUniforms; i++){
		glGetActiveUniform(programID, (GLuint)i, bufSize, &length, &size, &type, name);
		Uniform uniform;
		uniform.location = i;
		uniform.type = type;
		uniform.name = name;
		result.push_back(uniform);
	}
	return result;
}
