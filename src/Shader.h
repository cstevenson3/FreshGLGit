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
	vector<ShaderProgram::Attribute> attributes;
	vector<ShaderProgram::Uniform> uniforms;
	//Shader();
};



#endif /* SRC_SHADER_H_ */
