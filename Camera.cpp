#include "Camera.h"



Camera::Camera()
{
	initDefaultValues();
	updateMatrices();
}


Camera::~Camera()
{
}

void Camera::initDefaultValues()
{
	nearPlane = 0.01;
	farPlane = 1000;
	Left = -1;
	Right = 1;
	Top = 1;
	Bottom = -1;
	CamPos.x = CamPos.y = 0;
	CamPos.z = 0;
	LookAt.x = LookAt.y = 0;
	LookAt.z = 1;
	Up.x = Up.z = 0;
	Up.y = 1;
}

void Camera::updateMatrices()
{
	View = glm::translate(glm::mat4(1), -CamPos);
	Projection = glm::ortho(Left, Right, Bottom, Top, nearPlane, farPlane);
	combinedMatrix = Projection*View;

}

void Camera::setViewPort(float width, float height)
{
	Left = -(width / 2.0f);
	Right = width / 2.0f;
	Bottom = -(height / 2.0f);
	Top = (height / 2.0f);
	updateMatrices();
}

void Camera::setNearandFarPlane(float nearPlane, float farPlane)
{
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	updateMatrices();
}

