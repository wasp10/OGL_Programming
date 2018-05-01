#include "Physics_Body.h"



Physics_Body::Physics_Body(int vaoID,int numVertices,b2Body* physicsBodyRef):Mesh(vaoID,numVertices)
{
	this->physicsBodyRef = physicsBodyRef;
}


Physics_Body::~Physics_Body()
{
}
