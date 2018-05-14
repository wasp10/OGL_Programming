#include<vector>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma once
class Camera
{
public:
	Camera();
	~Camera();

	void setViewPort(float width, float height);
	void setNearandFarPlane(float nearPlane, float farPlane);

private:
	void initDefaultValues();
	void updateMatrices();
	const glm::mat4& getCombinedMatrix() const { return combinedMatrix; };


private:
	
	/*std::vector<float>Pos;
	std::vector<float>LookAt;
	std::vector<float>Up;*/

	float Left,
		Right,
		Top,
		Bottom,
		nearPlane,
		farPlane;

    glm::vec3 CamPos, LookAt, Up;
	glm::mat4 View, Projection, combinedMatrix;




};

