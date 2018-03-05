/*
 * FileTest.h
 *
 *  Created on: Feb 25, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_FILEBASICS_H_
#define SRC_FILEBASICS_H_

#include <string>
#include <vector>
using namespace std;

class FileBasics{
public:
	static void printFile(const string &fileLocation);
	static vector<string> getFileAsVectorOfLines(const string &fileLocation);
};



#endif /* SRC_FILEBASICS_H_ */
