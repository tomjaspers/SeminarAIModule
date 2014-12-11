class Potential
{
private:
	double *m_State;

public:
	Potential(double *state);
	~Potential(void);

	double getZeroPotential();
	double getDistancePotential(); 
	double getHealthPotential(); // #2
	double getInverseDistancePotential(); // #1 
	double getAnglePotential(); // #3
	double getInverseAnglePotential();

	double getLinearScalarizedPotential();

};