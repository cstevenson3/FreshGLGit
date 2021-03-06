/*
 * Main.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: stevosnipes
 */

#include <iostream>
#include <bitset>
#include <unordered_map>

#include "XMLproperties.h"
#include "FileBasics.h"
#include "HashTableStringToVectorString.h"
#include "FilePreloader.h"
#include "Graphics.h"
#include "Vector2f.h"
#include "ShaderProgram.h"
#include "StringHashTable.h"
#include "ShaderPreloader.h"
#include "LoadShader.h"
#include "Preloader.h"

using namespace std;

void testFilePrinting(){
	FileBasics::printFile("text/test.txt");
}

void testFileToVector(){
	vector<string> file = FileBasics::getFileAsVectorOfLines("text/test.txt");
	for(unsigned int i=0;i<file.size();i++){
		cout << file[i] << endl;
	}
}

/*
 * string to int non-unique hash
 */
int hash(string key, int max){
	int sum = 0;
	for(unsigned int i = 0; i < key.length(); i++){
		sum += (int)bitset<8>(key[i]).to_ulong();
	}
	return sum % max;
}

void testBasicHashTable(){
	HashTableStringToVectorString tab(128);

	vector<string> test = vector<string>();
	test.push_back("yeet");

	vector<string> test2 = vector<string>();
	test2.push_back("yeet2");

	tab.add("test",test);
	tab.add("test2",test2);

	vector<string> returned = tab.get("test");
	cout << returned[0] << endl;

	vector<string> returned2 = tab.get("test2");
	cout << returned2[0] << endl;
}

void testFilePreloader(){
	FilePreloader testFPL(128);
	testFPL.preloadFile("text/test.txt");

	vector<string> returned = testFPL.getFile("text/test.txt");
	for(unsigned int i = 0; i < returned.size(); i++){
		cout << returned[i] << endl;
	}
	//cout << returned[0] << endl;

	//vector<string> returned2 = testFPL.getFile("text/test2.txt");
	//cout << returned2[0] << endl;
}

void testStringHashTable(){
	StringHashTable<vector<string> > tab(128);

	vector<string> test = vector<string>();
	test.push_back("yeet");

	vector<string> test2 = vector<string>();
	test2.push_back("yeet2");

	tab.add("test",test);
	tab.add("test2",test2);

	vector<string> returned = tab.get("test");
	cout << returned[0] << endl;

	vector<string> returned2 = tab.get("test2");
	cout << returned2[0] << endl;
}

void runGraphics(){
	Graphics::createWindow(200,100,"FreshGL",false,nullptr,3,3,true,false);
	int v1 = ShaderProgram::loadShaderReturnID("text/modelVertexShader.txt",GL_VERTEX_SHADER);
	int f1 = ShaderProgram::loadShaderReturnID("text/modelFragmentShader.txt",GL_FRAGMENT_SHADER);
	int s1 = ShaderProgram::linkProgramReturnID(v1,f1);
	//ShaderProgram::printAllAttributes(s1);

	vector<ShaderProgram::Attribute> allAtts = ShaderProgram::getAttributes(s1);
	for(unsigned int i = 0; i < allAtts.size(); i++){
		cout << allAtts[i].location << " " << allAtts[i].name << " " << allAtts[i].type << endl;
	}
	cout << endl;
	vector<ShaderProgram::Uniform> allUnis = ShaderProgram::getUniforms(s1);
	for(unsigned int i = 0; i < allUnis.size(); i++){
		cout << allUnis[i].location << " " << allUnis[i].name << " " << allUnis[i].type << endl;
	}
	while(!Graphics::windowCloseRequested()){
		Graphics::refresh();
	}
	Graphics::closeWindow();
}

void testXML(){
	/*
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("text/testXML.xml");

	cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").text().get() << endl;
	*/
	XMLproperties props = XMLproperties("text/ExampleShader.txt");
	cout << props.getValue("vertex") << endl;
}

void testShaderPreloader(){
	Graphics::createWindow(200,100,"FreshGL",false,nullptr,3,3,true,false);

	/*
	ShaderPreloader tests = ShaderPreloader(128);
	//tests.preloadShader("text/ExampleShader.txt");
	Shader shader = tests.getShader("text/ExampleShader.txt");
	shader.printShader();
	*/

	Preloader<string, Shader> tests = Preloader<string, Shader>(loadShader);
	//Shader shader = tests["text/ExampleShader.txt"];
	tests["text/ExampleShader.txt"].id = 9999;
	cout << tests["text/ExampleShader.txt"].id << endl;
	tests["text/ExampleShader.txt"].printShader();

	while(!Graphics::windowCloseRequested()){
		Graphics::refresh();
	}
	Graphics::closeWindow();
}

void testUnorderedMap(){
	unordered_map<string, int> map = unordered_map<string, int>();
	map["yeet"] = 3;
	cout << map["yo"] << endl;
	try{
		cout << map.at("crahs this sobobo") << endl;
	}catch (const exception& e){
		cout << e.what() << endl;
	}

}

int main(){
	//testUnorderedMap();
	testShaderPreloader();
	//testXML();
	//testFilePreloader();
	//testStringHashTable();
	//runGraphics();
	return 0;
}
