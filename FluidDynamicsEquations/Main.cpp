#include <iostream>
#include <glm\glm.hpp>
#include "BaseEQ.h"

using namespace std;

void main(void)
{
	BaseEQ Bernoulli;
	glm::vec2 elv;
	elv.x = 2.0;
	elv.y = 4.0;

	glm::vec2 pres;
	pres.x = 92.1;
	pres.y = 82.3;

	glm::vec2 vel;
	vel.x = 2.3;
	vel.y = 3.4;

	float den = 9.2;
	float aog = 3.2;


	cout << Bernoulli.BernoulliHeadLess(elv,pres,vel,den,aog) << endl;
}