/*
 * Shader.h
 *
 *  Created on: Mar 5, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_SHADER_H_
#define SRC_SHADER_H_

#include "ShaderProgram.h"

class Shader{
public:
	string name;
	int id;
	vector<ShaderProgram::Attribute> attributes;
	vector<ShaderProgram::Uniform> uniforms;

	Shader(string _name, int _id, vector<ShaderProgram::Attribute> _attributes, vector<ShaderProgram::Uniform> _uniforms);
};



#endif /* SRC_SHADER_H_ */
