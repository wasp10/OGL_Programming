#include"Header.h"
#include "Render.h"



Render::Render()
{
}


Render::~Render()
{
}

void Render::preRender()
{
	
	glClearColor(0.8, 0.2, 0.2, 0.2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Render::draw(int vaoID,int getNumvertices)
{

	glDrawArrays(GL_TRIANGLES, 0, getNumvertices);
}