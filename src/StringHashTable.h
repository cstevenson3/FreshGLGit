/*
 * StringHashTable.h
 *
 *  Created on: Mar 5, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_STRINGHASHTABLE_H_
#define SRC_STRINGHASHTABLE_H_

#include <string>
#include <vector>
using namespace std;

#include "HashFunctions.h"

template <class ValueType>

class StringHashTable{
private:
	int DEFAULT_CAPACITY = 128;
	const string AVAILABLE_INDEX = "wwww";

	int maxSize;
	vector<pair<string,ValueType> > table;
	bool keyIsValid(string key){
		return key!=AVAILABLE_INDEX;
	}
public:

	StringHashTable& operator=(const StringHashTable& other){
		maxSize = other.maxSize;
		table = other.table;
		return *this;
	}

	/* rules:
	 * don't have more than MAX_PAIRS elements
	 *
	 */
	StringHashTable(){
		maxSize = DEFAULT_CAPACITY;
		table = vector<pair<string,ValueType> >(maxSize,pair<string, ValueType>(AVAILABLE_INDEX,ValueType()));
	}

	StringHashTable(int _maxSize){
		maxSize = _maxSize;
		table = vector<pair<string,ValueType> >(maxSize,pair<string, ValueType>(AVAILABLE_INDEX,ValueType()));
	}

	int getMaxSize(){
		return maxSize;
	}

	bool add(string key, ValueType value){
		int hash = HashFunctions::basicStringToIntHash(key);
		int start_index = hash % maxSize;
		int increment = 0;
		bool noIndexFree = false;
		while(table[((start_index + increment) % maxSize)].first!=AVAILABLE_INDEX){
			increment++;
			if(increment >= maxSize){
				noIndexFree = true;
				break;
			}
		}
		if(noIndexFree){
			return false;
		}else{
			int final_index = ((start_index + increment) % maxSize);
			table[final_index] = pair<string,ValueType>(key,value);
			return true;
		}
	}

	void remove(string key){
		int hash = HashFunctions::basicStringToIntHash(key);
		int start_index = hash % maxSize;
		int increment = 0;
		bool keyNotFound = false;
		while(table[((start_index + increment) % maxSize)].first!=key){
			increment++;
			if(increment >= maxSize){
				keyNotFound = true;
				break;
			}
		}
		if(keyNotFound){
			return;
		}else{
			table[((start_index + increment) % maxSize)].first = AVAILABLE_INDEX;
		}
	}

	ValueType get(string key){
		int hash = HashFunctions::basicStringToIntHash(key);
		int start_index = hash % maxSize;
		int increment = 0;
		bool keyNotFound = false;
		while(table[((start_index + increment) % maxSize)].first!=key){
			increment++;
			if(increment >= maxSize){
				keyNotFound = true;
				break;
			}
		}
		if(keyNotFound){
			//vector<string> error = vector<string>();
			//error.push_back("key not found");
			return ValueType();
		}else{
			int final_index = ((start_index + increment) % maxSize);
			return table[final_index].second;
		}
	}

	ValueType get(string key, ValueType (f)(string)){
		int hash = HashFunctions::basicStringToIntHash(key);
		int start_index = hash % maxSize;
		int increment = 0;
		bool keyNotFound = false;
		while(table[((start_index + increment) % maxSize)].first!=key){
			increment++;
			if(increment >= maxSize){
				keyNotFound = true;
				break;
			}
		}
		if(keyNotFound){
			//vector<string> error = vector<string>();
			//error.push_back("key not found");
			return (f)(key);
		}else{
			int final_index = ((start_index + increment) % maxSize);
			return table[final_index].second;
		}
	}
};



#endif /* SRC_STRINGHASHTABLE_H_ */
