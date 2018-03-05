/*
 * HashTableStringToVectorString.h
 *
 *  Created on: Feb 26, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_HASHTABLESTRINGTOVECTORSTRING_H_
#define SRC_HASHTABLESTRINGTOVECTORSTRING_H_

#include <string>
#include <vector>
using namespace std;

class HashTableStringToVectorString{
private:
	int maxSize;
	vector<pair<string,vector<string> > > table;
	bool keyIsValid(string key);
public:
	/* rules:
	 * don't have more than MAX_PAIRS elements
	 *
	 */
	vector<string> error;
	HashTableStringToVectorString();
	HashTableStringToVectorString(int _maxSize);
	int getMaxSize();
	bool add(string key, vector<string> value);
	void remove(string key);
	vector<string> get(string key);
};



#endif /* SRC_HASHTABLESTRINGTOVECTORSTRING_H_ */
