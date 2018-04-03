/*
 * ShaderPreloader.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: stevosnipes
 */

#include "ShaderPreloader.h"
#include "XMLproperties.h"
#include "LoadShader.h"

ShaderPreloader::ShaderPreloader(){
	shadersTable = StringHashTable<Shader>(128);
}

ShaderPreloader::ShaderPreloader(int capacity){
	shadersTable = StringHashTable<Shader>(capacity);
}

bool ShaderPreloader::preloadShader(string fileLocation){
	return shadersTable.add(fileLocation, loadShader(fileLocation));
}

Shader ShaderPreloader::getShader(string fileLocation){
	return shadersTable.get(fileLocation, loadShader);
}

void ShaderPreloader::deloadShader(string fileLocation){
	shadersTable.remove(fileLocation);
}
