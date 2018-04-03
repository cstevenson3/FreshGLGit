/*
 * ShaderPreloader.h
 *
 *  Created on: Mar 7, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_SHADERPRELOADER_H_
#define SRC_SHADERPRELOADER_H_

#include <string>
using namespace std;
#include "Shader.h"
#include "StringHashTable.h"

class ShaderPreloader{
private:
	StringHashTable<Shader> shadersTable;
public:
	ShaderPreloader();
	ShaderPreloader(int capacity);
	bool preloadShader(string fileLocation);
	Shader getShader(string fileLocation);
	void deloadShader(string fileLocation);
};



#endif /* SRC_SHADERPRELOADER_H_ */
