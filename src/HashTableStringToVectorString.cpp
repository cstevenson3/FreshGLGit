/*
 * HashTableStringToVectorString.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: stevosnipes
 */

#include "HashTableStringToVectorString.h"
#include "HashFunctions.h"

const int DEFAULT_CAPACITY = 128;
const string AVAILABLE_INDEX = "wwww";
const string ERROR_STRING = "not found";

/*
 * Create table with size _maxSize
 */
HashTableStringToVectorString::HashTableStringToVectorString(int _maxSize){
	maxSize = _maxSize;
	table = vector<pair<string,vector<string> > >(maxSize,pair<string, vector<string> >(AVAILABLE_INDEX,vector<string>()));
	error = vector<string>();
	error.push_back(ERROR_STRING);
}

HashTableStringToVectorString::HashTableStringToVectorString(){
	maxSize = DEFAULT_CAPACITY;
	table = vector<pair<string,vector<string> > >(maxSize,pair<string, vector<string> >(AVAILABLE_INDEX,vector<string>()));
	error = vector<string>();
	error.push_back(ERROR_STRING);
}

/*
 * get the maximum capacity of the hash table
 */
int HashTableStringToVectorString::getMaxSize(){
	return maxSize;
}

/*
 * checks if a key is allowed (i.e. is not the string used to show an index is available)
 */
bool HashTableStringToVectorString::keyIsValid(string key){
	return key!=AVAILABLE_INDEX;
}

/*
 * add key,value pair to hash table. Returns whether addition was successful
 */
bool HashTableStringToVectorString::add(string key, vector<string> value){
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
		table[final_index] = pair<string,vector<string> >(key,value);
		return true;
	}
}

/*
 * get the value at key
 */
vector<string> HashTableStringToVectorString::get(string key){
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
		return error;
	}else{
		int final_index = ((start_index + increment) % maxSize);
		return table[final_index].second;
	}
}

void HashTableStringToVectorString::remove(string key){
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
