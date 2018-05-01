#pragma once

#include"Header.h"

#include<vector>

class Buffer_Loader
{
public:
	Buffer_Loader();
	~Buffer_Loader();

	unsigned int loadToBuffer(std::vector<float>positions,int numVertices);
	void unbindVBO();
	void unbindVAO();


private:
	void createVAO(unsigned int *vaoID);
	void storeToVBO(std::vector<float>data,int numVertices);
	



};

