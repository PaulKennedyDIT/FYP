#include <iostream>
#include "BaseEQ.h"

using namespace std;

BaseEQ::BaseEQ(void)
{
}


BaseEQ::~BaseEQ(void)
{
}

/*
Bernoulli Equation to solve the headloss given the following criteria:
Elevation of two points,
Pressure at two points,
Velocity at the two points, 
Density,
Acceleration of Gravity.

Abides by the following formula:
Headloss = Elevation 1 - Elevation 2 +	(Position 1 - Position 2)			+ Velocity1^2 - Velocity2^2
									 ________________________________		_______________________
									density * Acceleration of gravity			2 * Acceleration of Gravity
*/
float BaseEQ::BernoulliHeadLoss(glm::vec2 elevation, glm::vec2 pressure,glm::vec2 velocity,float density,float aOG)
{
	headLoss = elevation.x - elevation.y + ((pressure.x - pressure.y)/ (density * aOG)) + (((pow(velocity.x,2)) -(pow(velocity.y,2)))/(2*aOG));

	return headLoss;
}

/*
Bernoulli Equation to solve for ab elevation at point 1:
Elevation of two points,
Pressure at two points,
Velocity at the two points, 
Density,
Acceleration of Gravity.

Abides by the following formula:
Elevation 1 =  Elevation 2 +	(Position 2 - Position 1)			+	Velocity1^2 - Velocity2^2
							 ________________________________			_______________________			+ Headloss
							density * Acceleration of gravity			2 * Acceleration of Gravity
*/
float BaseEQ::BernoulliElevation(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	elevation.x = elevation.y + ((pressure.y - pressure.x)/ density * aOG) + (pow(velocity.y,2) - pow(velocity.x,2)/(2 * aOG)) + headloss;
	return elevation.x;
}

float BaseEQ::BernoulliPressure(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	pressure.x = density * aOG * (elevation.y - elevation.x + ((pressure.y/ density * aOG)) + (pow(velocity.y,2) - pow(velocity.x,2)/(2 * aOG)) + headloss);
	return pressure.x;
}

float BaseEQ::BernoulliVelocity(void)
{
	return 0.0f;
}
