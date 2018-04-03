/*
 * LoadShader.h
 *
 *  Created on: Mar 22, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_LOADSHADER_H_
#define SRC_LOADSHADER_H_

#include "ShaderProgram.h"
#include <string>
using namespace std;
#include "XMLproperties.h"
#include "Shader.h"

Shader loadShader(string fileLocation){
	XMLproperties shaderProps = XMLproperties(fileLocation);
	string vertexShaderLocation = shaderProps.getValue("vertex");
	string fragmentShaderLocation = shaderProps.getValue("fragment");

	int vertexShaderID = ShaderProgram::loadShaderReturnID(vertexShaderLocation, GL_VERTEX_SHADER);
	int fragmentShaderID = ShaderProgram::loadShaderReturnID(fragmentShaderLocation, GL_FRAGMENT_SHADER);

	int id = ShaderProgram::linkProgramReturnID(vertexShaderID, fragmentShaderID);

	vector<ShaderProgram::Attribute> attributes = ShaderProgram::getAttributes(id);
	vector<ShaderProgram::Uniform> uniforms = ShaderProgram::getUniforms(id);

	Shader shader = Shader(fileLocation, id, attributes, uniforms, vertexShaderLocation, fragmentShaderLocation, vertexShaderID, fragmentShaderID);

	return shader;
}



#endif /* SRC_LOADSHADER_H_ */
