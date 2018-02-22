/*************************************************************************
     > The program can only be employed for academic research.
     > File Name: Resources.cpp
     > Author: Chauency
     > Mail: chauencychan.gmail.com
     > Created Time: 2018-02-17
     > Description: This program is the implementation of Resources.h  
************************************************************************/


#include "Resources.h"
#include <iostream>

using namespace std;
Resources :: Resources() 
{

}

Resources :: ~Resources() 
{

}

//Function: All initialization is written in here, e.g., memory allocation, variables initialzation.
void Resources :: Initialization()
{
	//One question left to be addressed: if assign *seed directly will cause the BUS ERROR 10!!
	seed = new int[1];
	*seed = (int) time(NULL);
	cout << "Resources has been initialzed!!\n";
	return;

}
void Resources :: FreeMemory()
{
	delete []seed;
	return;
}

double Resources :: uniform_0_1()
{
	double val = 0.0;
	*seed = 2045 * (*seed) + 1;
	*seed = *seed - (*seed / 1048576) * 1048576;
	val = (*seed) / 1048576.0;
	return val;
}

void Resources :: getBitVec(const int len, int* bitVec)
{
	for(int i = 0; i < len; ++i)
	{
		bitVec[i] = uniform_0_1() > 0.5 ? 1 : 0;
	}
	return;

}

void Resources :: getGaussNoiseVec(const int len, double* GaussNoiseVec)
{
	for(int i = 0; i < len; ++i)
	{
		GaussNoiseVec[i] = 0;
		for(int j = 0; j < 12; ++j)
		{
			GaussNoiseVec[i] += uniform_0_1();
		}
		GaussNoiseVec[i] -= 6.0;
	}
	return;
}




