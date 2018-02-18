#ifndef _RESOURCES_H
#define _RESOURCES_H
class Resources
{
public:
	long int* seed;
	
	Resources();
	~Resources();
	void Initialization();
	double uniform_0_1();
	void getBitVec(int len, int* bitVec);
	void getGaussNoiseVec(int len, double* GaussNoiseVec);


private:


	
};
#endif