/*
 * Shader.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: stevosnipes
 */

#include "Shader.h"
#include <iostream>
using namespace std;

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

void Shader::printShader(){
	cout << "---------------" << endl;

	cout << "Name: " << name << endl;

	cout << endl;

	cout << "Attributes: " << endl;
	for(unsigned int i = 0; i < attributes.size(); i++){
		cout << attributes[i].name << endl;
	}

	cout << endl;

	cout << "Uniforms: " << endl;
	for(unsigned int i = 0; i < uniforms.size(); i++){
		cout << uniforms[i].name << endl;
	}

	cout << "---------------" << endl;
}
