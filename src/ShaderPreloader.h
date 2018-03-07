/*
 * ShaderPreloader.h
 *
 *  Created on: Mar 7, 2018
 *      Author: stevosnipes
 */

#ifndef SHADERPRELOADER_H_
#define SHADERPRELOADER_H_

#include "StringHashTable.h"

class ShaderPreloader{
private:
	StringHashTable<Shader> shadersTable;
public:
	ShaderPreloader(int capacity);
	bool preloadShader(string fileLocation);
	Shader getShader(string fileLocation);
	void deloadFile(string fileLocation);
};



#endif /* SHADERPRELOADER_H_ */
