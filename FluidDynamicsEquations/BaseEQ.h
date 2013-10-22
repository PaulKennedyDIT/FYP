#pragma once
#include <glm\glm.hpp>

class BaseEQ
{
public:
	BaseEQ(void);
	~BaseEQ(void);

	
	float density;							//	Density represented as kilogram/meter^3
	float aOG;								//	Acceleration of Gravity(g) in meters/second^2
	float headLoss;							//	Head Loss

	glm::vec2 velocity;						//	Velocity at 2 points
	glm::vec2 pressure;						//	Measured in pascal
	glm::vec2 elevation;					//	Elevataion at 2 points

	


	float BernoulliHeadLess(glm::vec2 elevation, glm::vec2 pressure,glm::vec2 velocity,float density,float aOG);
	float BernoulliElevation(void);
	float BernoulliPressure(void);
	float BernoulliVelocity(void);
};
