#define _USE_MATH_DEFINES

#include "Potential.h"
#include "math.h"


Potential::Potential(double *state){
	m_State = state;
}

Potential::~Potential(void){}

//0 my X position (0-1000)
//1 my Y position (0-1000)
//2 Straight-line distance between me and enemy (0-1000)
//3 difference in hit points between me and enemy (-50 - 50)
//4 enemy is moving/attacking? (0 or 1)
//5 angle of enemy relative to me (pi - pi)
double Potential::getZeroPotential(){
	return 0.0;
}
double Potential::getDistancePotential(){
	// Move towards enemy
	return (1000 - m_State[2]) / 10000.0;
}
double Potential::getHealthPotential(){
	return m_State[3] / 10.0;
}
double Potential::getInverseDistancePotential(){
	// Move away from enemy
	return m_State[2] / 10000.0;
}

double Potential::getAnglePotential(){
	return abs(m_State[4] - M_PI) / 31.4;
}
double Potential::getInverseAnglePotential(){
	return abs(m_State[4]) / 31.4;
}

double Potential::getLinearScalarizedPotential(){
	double distPot = Potential::getInverseDistancePotential();
	double healthPot = Potential::getHealthPotential();
	double anglePot = Potential::getAnglePotential();

	return (0.3 * distPot) + (0.3 * healthPot) + (0.3 * anglePot);

}