/*
 * Preloader.h
 *
 *  Created on: Apr 13, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_PRELOADER_H_
#define SRC_PRELOADER_H_

#include <unordered_map>
using namespace std;

template<class KeyType, class ValueType>
class Preloader{
private:
	unordered_map<KeyType, ValueType> map;

	/*Load function is able to return the appropriate value based on the key. I.e. if keys are file directories, then load will return the value based on that file.*/
	ValueType (*load)(KeyType);


public:
	/* initialise preloader without load function */
	Preloader(){
		map = unordered_map<KeyType, ValueType>();
	}
	/* initialise preloader with a load function */
	Preloader(ValueType (*loadFunction)(KeyType)){
		map = unordered_map<KeyType, ValueType>();
		setLoadFunction(loadFunction);
	}

	/* Set the load function */
	void setLoadFunction(ValueType (*loadFunction)(KeyType)){
		load = loadFunction;
	}

	/* return reference to element at key, loading it in first if necessary */
	ValueType& operator[](KeyType key){
		try{
			map.at(key);
		}catch (const exception& e1){
			try{
				map[key] = load(key);
			}catch (const exception& e2){
				map[key] = ValueType();
			}
		}
		return map[key];
	}


};



#endif /* SRC_PRELOADER_H_ */
