/*************************************************************************
     > The program can only be employed for academic research.
     > File Name: Resources.cpp
     > Author: Chauency
     > Mail: chauencychan.gmail.com
     > Created Time: 2018-02-17
     > Description: This program is used to generated random number. 
************************************************************************/

#ifndef _RESOURCES_H
#define _RESOURCES_H
#include <cstdlib>
#include <ctime>
#include <string>
#include <ctime>
using namespace std;
class Resources
{
public:
	int* m_seed;
	double m_err_bits, m_simu_bits;
	double m_err_block;
	double m_ber;
	char Result_file_name[300];

	Resources();
	~Resources();
	void Initialization();
	void FreeMemory();
	double uniform_0_1();
	void getBitVec(int len, int* bitVec);
	void getGaussNoiseVec(int len, double* GaussNoiseVec);
	string getTime();
	void clc();
	void CalculateBER(int *bb, int *bb_hat, int len_bb);
	void PrintResult(char *Modem_file_name);
	void PrintResult(double snr);
	void PrintResult2Terminal(int simu_blocks, double snr);
	void PrintResult2Terminal(char *Modem_file_name);



private:


	
};
#endif