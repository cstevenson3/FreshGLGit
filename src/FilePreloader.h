/*
 * FilePreloader.h
 *
 *  Created on: Feb 27, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_FILEPRELOADER_H_
#define SRC_FILEPRELOADER_H_

#include "HashTableStringToVectorString.h"

class FilePreloader{
private:
	HashTableStringToVectorString table;
public:
	FilePreloader(int capacity);
	bool preloadFile(string fileLocation);
	vector<string> getFile(string fileLocation);
	void deloadFile(string fileLocation);
};



#endif /* SRC_FILEPRELOADER_H_ */
