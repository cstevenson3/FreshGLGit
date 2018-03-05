/*
 * Graphics.h
 *
 *  Created on: Feb 28, 2018
 *      Author: stevosnipes
 */

#ifndef SRC_GRAPHICS_H_
#define SRC_GRAPHICS_H_

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <string>
using namespace std;
/*
 * currently a single window solution
 */
class Graphics{
private:
	static GLFWwindow* windowID;

	static int windowWidth;
	static int windowHeight;

	static string windowTitle;

	static bool windowFullscreen;
	static GLFWwindow* windowShare;

	static int glfwVersionMajor;
	static int glfwVersionMinor;
	static bool coreProfile;
	static bool forwardCompat;

public:
	static void testWindow();
	static bool createWindow(int _windowWidth, int _windowHeight, string _windowTitle, bool _windowFullscreen, GLFWwindow* _windowShare, int glfwVersionMajorOpt, int glfwVersionMinorOpt, bool useCoreProfile, bool useForwardCompat);
	static void refresh();
	static bool windowCloseRequested();
	static void closeWindow();
};



#endif /* SRC_GRAPHICS_H_ */
