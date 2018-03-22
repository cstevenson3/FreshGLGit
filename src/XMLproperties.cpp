/*
 * XMLproperties.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: stevosnipes
 */

#include "XMLproperties.h"

XMLproperties::XMLproperties(string filename){
	doc.load_file(filename.c_str());
}


string XMLproperties::getValue(string key){
	return doc.child(key.c_str()).text().get();
}
