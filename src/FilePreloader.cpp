/*
 * FilePreloader.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: stevosnipes
 */

#include "FilePreloader.h"
#include "FileBasics.h"
/*
 * creates a structure in which files can be preloaded and accessed later, or accessed immediately
 */


FilePreloader::FilePreloader(int capacity){
	table = HashTableStringToVectorString(capacity);
}


/*
 * preload a file (i.e. heads up that it will be needed)
 */
bool FilePreloader::preloadFile(string fileLocation){
	vector<string> file = FileBasics::getFileAsVectorOfLines(fileLocation);
	bool success = table.add(fileLocation,file);
	return success;
}

vector<string> FilePreloader::getFile(string fileLocation){
	vector<string> file = table.get(fileLocation);
	if(file == table.error){
		file = FileBasics::getFileAsVectorOfLines(fileLocation);
	}
	return file;
}

void FilePreloader::deloadFile(string fileLocation){
	table.remove(fileLocation);
}
