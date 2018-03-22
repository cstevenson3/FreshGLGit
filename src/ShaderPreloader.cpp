/*
 * ShaderPreloader.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: stevosnipes
 */

#include "ShaderPreloader.h"

ShaderPreloader::ShaderPreloader(){
	shadersTable = StringHashTable<Shader>(128);
}

ShaderPreloader::ShaderPreloader(int capacity){
	shadersTable = StringHashTable<Shader>(capacity);
}

bool ShaderPreloader::preloadShader(string fileLocation){
	return true;
}

