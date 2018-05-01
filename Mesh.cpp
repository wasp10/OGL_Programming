#include "Mesh.h"



Mesh::Mesh(int vaoID,int numVertices):vaoID(vaoID),numVertices(numVertices)
{
}


Mesh::~Mesh()
{
}

int Mesh::getvaoID()
{
	return vaoID;

}

int Mesh::getNumVertices()
{
	return numVertices;

}