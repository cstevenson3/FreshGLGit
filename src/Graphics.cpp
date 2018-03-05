/*
 * Graphics.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: stevosnipes
 */

#include "Graphics.h"



#include <iostream>
using namespace std;

#include <cstdlib>

GLFWwindow* Graphics::windowID = nullptr;
int Graphics::windowWidth = 0;
int Graphics::windowHeight = 0;
string Graphics::windowTitle = "";
bool Graphics::windowFullscreen = false;
GLFWwindow* Graphics::windowShare = nullptr;
int Graphics::glfwVersionMajor = 0;
int Graphics::glfwVersionMinor = 0;
bool Graphics::coreProfile = false;
bool Graphics::forwardCompat = false;

void Graphics::testWindow(){
	int glfwInitResult = glfwInit();
	if(glfwInitResult==GL_FALSE){
		cout << "Graphics: glfwInit returned GL_FALSE" << endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_VISIBLE,GL_FALSE);

	GLFWwindow* windowID = glfwCreateWindow(800,600,"Succ it",nullptr,nullptr);
	if(windowID==NULL){
		cout << "Graphics: glfwCreateWindow returned null" << endl;
		glfwTerminate();
	}

	int bufferWidth;
	int bufferHeight;
	glfwGetFramebufferSize(windowID,&bufferWidth,&bufferHeight);

	glfwMakeContextCurrent(windowID); //
	//vsync
	//glfwSwapInterval(1);
	//glew
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Graphics: glewInit is not GLEW_OK" << endl;
		glfwTerminate();
	}
	//show the window
	glClearColor(.4,.35,.05,1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glEnable(GL_MULTISAMPLE); //sample count above with window hints
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwShowWindow(windowID);
	glfwSetWindowPos(windowID, 100, 100);
	//set viewport
	glViewport(0,0,800,600);
	glfwSwapInterval(1);
	while(!glfwWindowShouldClose(windowID)){
		glfwPollEvents();
		glClearColor(.4,.35,.05,1);
		glfwSwapBuffers(windowID);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	}
}

/*
 * create a window with these parameters
 */
bool Graphics::createWindow(int _windowWidth, int _windowHeight, string _windowTitle, bool _windowFullscreen, GLFWwindow* _windowShare, int glfwVersionMajorOpt, int glfwVersionMinorOpt, bool useCoreProfile, bool useForwardCompat){
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	windowTitle = _windowTitle;
	windowFullscreen = _windowFullscreen;
	windowShare = _windowShare;
	glfwVersionMajor = glfwVersionMajorOpt;
	glfwVersionMinor = glfwVersionMinorOpt;
	coreProfile = useCoreProfile;
	forwardCompat = useForwardCompat;

	int glfwInitResult = glfwInit();
	if(glfwInitResult == GL_FALSE){
		cout << "Graphics: glfwInit returned GL_FALSE" << endl;
		return false;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfwVersionMajorOpt);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfwVersionMinorOpt);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if(coreProfile)glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if(forwardCompat)glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_VISIBLE,GL_FALSE);

	windowID = glfwCreateWindow(_windowWidth, _windowHeight, _windowTitle.c_str(), _windowFullscreen? glfwGetPrimaryMonitor(): nullptr, nullptr);
	if(windowID==NULL){
		cout << "Graphics: glfwCreateWindow returned null" << endl;
		glfwTerminate();
		return false;
	}

	//check window attributes are equal to those requested
	if((glfwGetWindowAttrib(windowID,GLFW_CONTEXT_VERSION_MAJOR)!=glfwVersionMajor)||(glfwGetWindowAttrib(windowID,GLFW_CONTEXT_VERSION_MINOR)!=glfwVersionMinor)||(glfwGetWindowAttrib(windowID,GLFW_OPENGL_PROFILE)!=GLFW_OPENGL_CORE_PROFILE)){
		cout << "Graphics: GLFW version not equal to requested version, or core profile not used" << endl;
	}

	int glfwWidth;
	int glfwHeight;
	glfwGetWindowSize(windowID,&glfwWidth,&glfwHeight);
	if((glfwWidth!=windowWidth)||(glfwHeight!=windowHeight)){
		cout << "Graphics: window dimensions not equal to requested dimensions" << endl;
		cout << "cont -> Actual width = ";
		cout << glfwWidth << endl;
		cout << "cont -> Actual height = ";
		cout << glfwHeight << endl;
		cout << "cout -> Framebuffer size check should sort this out" << endl;
	}

	int bufferWidth;
	int bufferHeight;
	glfwGetFramebufferSize(windowID,&bufferWidth,&bufferHeight);
	if((bufferWidth!=windowWidth)||(bufferHeight!=windowHeight)){
		cout << "Graphics: recorded window dimensions (screen) not equal to framebuffer (pixels)" << endl;
		cout << "cont -> Actual width (pixels) = ";
		cout << bufferWidth << endl;
		cout << "cont -> Actual height (pixels) = ";
		cout << bufferHeight << endl;
		windowWidth=bufferWidth;
		windowHeight=bufferHeight;
		cout << "cont -> recorded actual pixel dimensions" << endl;
	}


	glfwMakeContextCurrent(windowID);
	//vsync
	//glfwSwapInterval(1);
	//glew
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Graphics: glewInit is not GLEW_OK" << endl;
		glfwTerminate();
	}
	//show the window
	glClearColor(.4,.35,.05,1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glEnable(GL_MULTISAMPLE); //sample count above with window hints
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwShowWindow(windowID);
	glfwSetWindowPos(windowID, 100, 100);
	//set viewport
	glViewport(0,0,windowWidth,windowHeight);
	//glfwSwapInterval(1);
	/*
	while(!glfwWindowShouldClose(windowID)){
		glfwPollEvents();
		glClearColor(.4,.35,.05,1);
		glfwSwapBuffers(windowID);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	}
	*/
	return true;
}

void Graphics::refresh(){
	glfwPollEvents();
	//glClearColor(.4,.35,.05,1);
	glfwSwapBuffers(windowID);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

bool Graphics::windowCloseRequested(){
	return glfwWindowShouldClose(windowID);
}

void Graphics::closeWindow(){
	glfwTerminate();
}
