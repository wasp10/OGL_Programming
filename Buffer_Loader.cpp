#include"Header.h"
#include"Mesh.h"
#include "Buffer_Loader.h"



Mesh* mesh;

Buffer_Loader::Buffer_Loader()
{
}


Buffer_Loader::~Buffer_Loader()
{
}


unsigned int Buffer_Loader::loadToBuffer(std::vector<float>positions,int numVertices)
{
	unsigned int vaoID;
	createVAO(&vaoID);
	storeToVBO(positions,numVertices);
	//unbindVBO();
	//unbindVAO();

	
	return vaoID;
}

void Buffer_Loader::createVAO(unsigned int *vaoID)
{
	glGenVertexArrays(1, vaoID);
	glBindVertexArray(*vaoID);
}

void Buffer_Loader::storeToVBO(std::vector<float>data,int numVertices)
{

	float* floatBfrPtr = new float[data.size()];
	int i=0;
	for (auto f : data)
		floatBfrPtr[i++] = f;


	unsigned int vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), floatBfrPtr, GL_STATIC_DRAW);
	std::cout << data.size()*sizeof(float);
	std::cout << floatBfrPtr<<"\n";
	std::cout << numVertices;
	glVertexAttribPointer(0, numVertices, GL_FLOAT, GL_FALSE, numVertices*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	

}


void Buffer_Loader::unbindVBO()
{
	glDisableVertexAttribArray(0);
}

void Buffer_Loader::unbindVAO()
{
	glBindVertexArray(0);
}