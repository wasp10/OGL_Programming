#include "Cam.h"



Cam::Cam()
{
	initDefaultValues();
	updateMatrices();
}


Cam::~Cam()
{
}

void Cam::initDefaultValues()
{
	nearPlane = 0.01;
	farPlane = 10;
	Left = -1;
	Right = 1;
	Top = 1;
	Bottom = -1;
	CamPos.x = CamPos.y = CamPos.z = 0;
	LookAt.x = LookAt.y = 0;
	LookAt.z = 1;
	Up.x = Up.z = 0;
	Up.y = 1;
}

void Cam::updateMatrices()
{
	View = glm::translate(glm::mat4(1), -CamPos);
	Projection = glm::ortho(Left, Right, Bottom, Top, nearPlane, farPlane);
	combinedMatrix = Projection * View;

}

void Cam::setViewPort(float width, float height)
{
	Left = -(width / 2.0f);
	Right = width / 2.0f;
	Bottom = -(height / 2.0f);
	Top = (height / 2.0f);
	updateMatrices();
}

void Cam::setNearandFarPlane(float nearPlane, float farPlane)
{
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	updateMatrices();
}


