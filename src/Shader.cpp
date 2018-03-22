/*
 * Shader.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: stevosnipes
 */

#include "Shader.h"

Shader::Shader(string _name, int _id, vector<ShaderProgram::Attribute> _attributes, vector<ShaderProgram::Uniform> _uniforms, string _vertexShaderLocation, string _fragmentShaderLocation, int _vertexShaderID, int _fragmentShaderID){
	name = _name;
	id = _id;
	attributes = _attributes;
	uniforms = _uniforms;

	vertexShaderLocation = _vertexShaderLocation;
	fragmentShaderLocation = _fragmentShaderLocation;
	vertexShaderID = _vertexShaderID;
	fragmentShaderID = _fragmentShaderID;
}

Shader::Shader(){
	name = "";
	id = 0;
}
