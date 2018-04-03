/*
 * XMLproperties.h
 *
 *  Created on: Mar 22, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_XMLPROPERTIES_H_
#define SRC_XMLPROPERTIES_H_

#include "pugixml.hpp"
using namespace pugi;

#include <string>
using namespace std;

class XMLproperties{
private:
	xml_document doc;
public:
	XMLproperties(string filename);
	string getValue(string key);
};



#endif /* SRC_XMLPROPERTIES_H_ */
