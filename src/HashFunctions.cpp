/*
 * HashFunctions.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: stevosnipes
 */

#include "HashFunctions.h"

int HashFunctions::basicStringToIntHash(string key){
	int sum = 0;
	for(unsigned int i = 0; i < key.length(); i++){
		sum += (int)bitset<8>(key[i]).to_ulong();
	}
	return sum;
}
