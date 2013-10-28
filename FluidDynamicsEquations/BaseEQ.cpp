#include <iostream>
#include "BaseEQ.h"

using namespace std;

BaseEQ::BaseEQ(void)
{
}


BaseEQ::~BaseEQ(void)
{
}

float BaseEQ::PressureMinus(float pressureP1,float pressureP2)
{
	return pressureP1 - pressureP2;
}

float BaseEQ::VelocitySquaredMinus(float v1, float v2,int power)
{
	float p1 = pow(v1,power);
	float p2 = pow(v2,power);
	return p1 - p2;
}

/*
Bernoulli Equation to solve the headloss given the following criteria:
Headloss = Elevation 1 - Elevation 2 +	(Position 1 - Position 2)/(density * Acceleration of gravity)			+ Velocity1^2 - Velocity2^2/ (2 * Acceleration of Gravity)												
*/
float BaseEQ::BernoulliHeadLoss(glm::vec2 elevation, glm::vec2 pressure,glm::vec2 velocity,float density,float aOG)
{
	float vsm = VelocitySquaredMinus(velocity.x,velocity.y,2);
	headLoss = elevation.x - elevation.y + ((PressureMinus(pressure.x,pressure.y))/ (density * aOG)) + (vsm)/(2*aOG);

	return headLoss;
}

/*
Bernoulli Equation to solve for an elevation at point 1:
Elevation 1 =  Elevation 2 +	(Position 2 - Position 1)/(density * Acceleration of gravity)			+	Velocity2^2 - Velocity1^2/(2 * Acceleration of Gravity) + Headloss
*/
float BaseEQ::BernoulliElevation(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	float vsm = VelocitySquaredMinus(velocity.y,velocity.x,2);
	float pres = PressureMinus(pressure.y,pressure.x);
	elevation.x = elevation.y + (pres/ density * aOG) + (vsm)/(2 * aOG) + headloss;
	return elevation.x;
}

/*
Bernoulli Equation to solve for pressure at point 1:
Pressure 1 =  Density * Acceleration of gravity  * 	(Position 2 - Position 1  + (Velocity1^2 - Velocity2^2) / (2 * Acceleration of Gravity)	+ headloss)																				
*/
float BaseEQ::BernoulliPressure(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	float vsm = VelocitySquaredMinus(velocity.y,velocity.x,2);
	pressure.x = density * aOG * (elevation.y - elevation.x + ((pressure.y/ density * aOG)) + (vsm)/(2 * aOG) + headloss);
	return pressure.x;
}

/*
Bernoulli Equation to solve for velocity at point 1:
Velocity 1 =  Square Root (2 * Acceleration of gravity * ((Position 2 - Position 1)	+	(Velocity1^2 - Velocity2^2m)/(2 * Acceleration of Gravity) + (Velocity 2 ^2) / (2 * Acceleration of Gravity) + Headloss																												
*/
double BaseEQ::BernoulliVelocity(glm::vec2 elevation, glm::vec2 pressure, glm::vec2 velocity, float density, float aOG,float headloss)
{
	float pres = PressureMinus(pressure.y,pressure.x);
	velocity.x = sqrt(2 * aOG * (elevation.y - elevation .x +  (pres/ density * aOG) + (pow(velocity.y,2)/(2 * aOG)) + headloss));
	return velocity.x;
}
