#pragma once
class Mesh
{
public:
	Mesh(int vaoID,int numVertices);
	~Mesh();

	int getvaoID();
	int getNumVertices();

private:

	int vaoID, numVertices;

};

