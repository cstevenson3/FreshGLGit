/*
 * Shader.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: stevosnipes
 */

#include "Shader.h"

Shader::Shader(string _name, int _id, vector<ShaderProgram::Attribute> _attributes, vector<ShaderProgram::Uniform> _uniforms){
	name = _name;
	id = _id;
	attributes = _attributes;
	uniforms = _uniforms;
}
