#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<vector>
#include<iostream>

int main()
{
	int width = 1280, height = 720, numVertices;

	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, "OGL", NULL, NULL);

	glfwMakeContextCurrent(window);

	if (window == NULL)
	{
		std::cout << "sorry your window cannot be created\n";
		glfwTerminate();
		return -1;

	}

	glewInit();

	glewExperimental = GL_TRUE;

	float positions[] = { 0,0.2f,0,
	0,0,0,
	0.2f,0,0 };

	//std::vector<float>positions;
	////first triangle

	//positions.push_back(0); //x1
	//positions.push_back(0.2); //y1
	//positions.push_back(0); //z1

	//positions.push_back(0); //x2
	//positions.push_back(0); //y2
	//positions.push_back(0); //z2

	//positions.push_back(0.2); //x3
	//positions.push_back(0); //y3
	//positions.push_back(0); //z3

	

	unsigned int vaoID, vboID;

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	std::cout << positions;

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.8, 0.2, 0.2, 0.2);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();


	}

	glDisableVertexAttribArray(0);

	glfwTerminate();

	return 0;
}