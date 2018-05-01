#pragma once

#include"Header.h"

class WindowManager
{
public:
	WindowManager(int width,int height, const char* title);
	~WindowManager();

	int windowInit();
	void update();
	void terminate();
	bool iscloseRequested();

protected: int width, height;
		   const char* title;
		   GLFWwindow* window;

};

