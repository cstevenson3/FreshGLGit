/*
 * ShaderPreloader.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: stevosnipes
 */

#include "ShaderPreloader.h"
#include "XMLproperties.h"

ShaderPreloader::ShaderPreloader(){
	shadersTable = StringHashTable<Shader>(128);
}

ShaderPreloader::ShaderPreloader(int capacity){
	shadersTable = StringHashTable<Shader>(capacity);
}

Shader ShaderPreloader::loadShader(string fileLocation){
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

bool ShaderPreloader::preloadShader(string fileLocation){
	return shadersTable.add(fileLocation, loadShader(fileLocation));
}

Shader ShaderPreloader::getShader(string fileLocation){
	return shadersTable.get(fileLocation);
}
