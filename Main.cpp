#include"Header.h"
#include"WindowManager.h"
#include"Buffer_Loader.h"
#include"Render.h"
#include"Mesh.h"
#include<vector>


Buffer_Loader* buffer_Loader;
Render* render;

int main()
{
	int width = 1280, height = 720,numVertices,numVertices1;
	WindowManager* windowManager=new WindowManager(width, height, "OGL_WINDOW");
	windowManager->windowInit();

	

	std::vector<float>positions;

	std::vector<float>positions1;

	//first triangle

	positions.push_back(0); //x1
	positions.push_back(0.2); //y1
	positions.push_back(0); //z1

	positions.push_back(0); //x2
	positions.push_back(0); //y2
	positions.push_back(0); //z2

	positions.push_back(0.2); //x3
	positions.push_back(0); //y3
	positions.push_back(0); //z3

	//second triangle

	positions1.push_back(0.4); //x1
	positions1.push_back(0.2); //y1
	positions1.push_back(0); //z1
	
	positions1.push_back(0.4); //x2
	positions1.push_back(0); //y2
	positions1.push_back(0); //z2

	positions1.push_back(0.6); //x3
	positions1.push_back(0); //y3
	positions1.push_back(0); //z3

	numVertices = positions.size() / 3;

	//numVertices1 = positions1.size() / 3;

	int vaoID = buffer_Loader->loadToBuffer(positions, numVertices);

	int vaoID1 = buffer_Loader->loadToBuffer(positions1, numVertices);
	

	Mesh* mesh1 = new Mesh(vaoID, numVertices);
	Mesh* mesh2 = new Mesh(vaoID1, numVertices);

	while (windowManager->iscloseRequested())
	{
		render->preRender();
		render->draw(mesh1->getvaoID(),mesh1->getNumVertices());

		

		render->draw(mesh2->getvaoID(), mesh2->getNumVertices());

		

		windowManager->update();

	}

	buffer_Loader->unbindVAO();

	buffer_Loader->unbindVBO();

	windowManager->terminate();

	return 0;

}