#include <iostream>
#include <glm\glm.hpp>
#include "BaseEQ.h"

using namespace std;

void main(void)
{
	BaseEQ Bernoulli;
	Bernoulli.elevation.x = 2.0;
	Bernoulli.elevation.y = 4.0;

	Bernoulli.pressure.x = 92.1;
	Bernoulli.pressure.y = 82.3;

	
	Bernoulli.velocity.x = 2.3;
	Bernoulli.velocity.y = 3.4;

	Bernoulli.density = 9.2;
	Bernoulli.aOG = 3.2;


	Bernoulli.headLoss = Bernoulli.BernoulliHeadLoss(Bernoulli.elevation,Bernoulli.pressure,Bernoulli.velocity,Bernoulli.density,Bernoulli.aOG);
	cout << Bernoulli.headLoss << endl;

	Bernoulli.elevation.x = Bernoulli.BernoulliElevation(Bernoulli.elevation,Bernoulli.pressure,Bernoulli.velocity,Bernoulli.density,Bernoulli.aOG,Bernoulli.headLoss);
	cout << Bernoulli.elevation.x << endl;

	Bernoulli.pressure.x = Bernoulli.BernoulliPressure(Bernoulli.elevation,Bernoulli.pressure,Bernoulli.velocity,Bernoulli.density,Bernoulli.aOG,Bernoulli.headLoss);
	cout << Bernoulli.pressure.x << endl;


}