#pragma once
#include"Header.h"
#include"Mesh.h"

class Physics_Body: public Mesh
{
public:
	Physics_Body(int vaoID,int numVertices,b2Body* physicsBodyRef);
	~Physics_Body();

private:
	b2Body* physicsBodyRef;
};

