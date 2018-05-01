#include "WindowManager.h"



WindowManager::WindowManager(int width, int height, const char* title):width(width),height(height),title(title)
{

}


WindowManager::~WindowManager()
{
}



int WindowManager::windowInit()
{
	glfwInit();
	
	
	window = glfwCreateWindow(width, height, title, NULL, NULL);

	glfwMakeContextCurrent(window);

	if (window == NULL)
	{
		std::cout << "sorry your window cannot be created\n";
		glfwTerminate();
		return -1;

	}

	glewInit();

	glewExperimental = GL_TRUE;

	return 0;

}

void WindowManager::update()
{

		glfwSwapBuffers(window);
		glfwPollEvents();
	
}

void WindowManager::terminate()
{
	glfwTerminate();

}

bool WindowManager::iscloseRequested()
{
	return !glfwWindowShouldClose(window);
}