/*
 * FileTest.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: stevosnipes
 */

#include <iostream>
#include <fstream>
#include "FileBasics.h"

/**
 * Outputs the file found at fileLocation
 * @param fileLocation The directory of the file
 * @return No return
 */
void FileBasics::printFile(const string &fileLocation){
	string line;
	ifstream file(fileLocation.c_str());
	if(file.is_open()){
		while(getline(file,line)){
			cout << line << endl;
		}
		file.close();
	}else{
		cout << "File at " << fileLocation << " not opened";
	}
}

/**
 * Maintains empty lines
 * @param fileLocation The directory of the file
 * @return A vector list of each line in the file
 */
vector<string> FileBasics::getFileAsVectorOfLines(const string &fileLocation){
	vector<string> result = vector<string>();
	string line;
	ifstream file(fileLocation.c_str());
	if(file.is_open()){
		while(getline(file,line)){
			result.push_back(line);
		}
		file.close();
	}else{
		cout << "File at " << fileLocation << " not opened";
	}
	return result;
}
