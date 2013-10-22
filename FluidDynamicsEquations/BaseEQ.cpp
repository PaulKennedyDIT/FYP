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
Headloss = Elevation 1 - Elevation 2 +	(Position 1 - Position 2)/(density * Acceleration of gravity)			+ Velocity1^2 - Velocity2^2/ (2 * Acceleration of Gravity)												
*/
float BaseEQ::BernoulliHeadLoss(glm::vec2 elevation, glm::vec2 pressure,glm::vec2 velocity,float density,float aOG)
{
	headLoss = elevation.x - elevation.y + ((pressure.x - pressure.y)/ (density * aOG)) + (((pow(velocity.x,2)) -(pow(velocity.y,2)))/(2*aOG));

	return headLoss;
}

/*
Bernoulli Equation to solve for an elevation at point 1:
Elevation 1 =  Elevation 2 +	(Position 2 - Position 1)/(density * Acceleration of gravity)			+	Velocity1^2 - Velocity2^2/(2 * Acceleration of Gravity) + Headloss
*/
float BaseEQ::BernoulliElevation(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	elevation.x = elevation.y + ((pressure.y - pressure.x)/ density * aOG) + (pow(velocity.y,2) - pow(velocity.x,2)/(2 * aOG)) + headloss;
	return elevation.x;
}

/*
Bernoulli Equation to solve for pressure at point 1:
Pressure 1 =  Density * Acceleration of gravity  * 	(Position 2 - Position 1  + (Velocity1^2 - Velocity2^2) / (2 * Acceleration of Gravity)	+ headloss)																				
*/
float BaseEQ::BernoulliPressure(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	pressure.x = density * aOG * (elevation.y - elevation.x + ((pressure.y/ density * aOG)) + (pow(velocity.y,2) - pow(velocity.x,2)/(2 * aOG)) + headloss);
	return pressure.x;
}

/*
Bernoulli Equation to solve for velocity at point 1:
Velocity 1 =  Square Root (2 * Acceleration of gravity * ((Position 2 - Position 1)	+	(Velocity1^2 - Velocity2^2m)/(2 * Acceleration of Gravity) + (Velocity 2 ^2) / (2 * Acceleration of Gravity) + Headloss																												
*/
double BaseEQ::BernoulliVelocity(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	velocity.x = sqrt(2 * aOG * (elevation.y - elevation .x +  ((pressure.y - pressure.x)/ density * aOG) + (pow(velocity.y,2)/(2 * aOG)) + headloss));
	return velocity.x;
}
