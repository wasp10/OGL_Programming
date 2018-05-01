#pragma once
class Render
{
public:
	Render();
	~Render();

	void preRender();
	void draw(int vaoID,int getNumVertices);
	/*void draw();*/

private:
	int vaoID;
	int getNumVertices;

};

