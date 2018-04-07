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

Resources :: Resources() 
{

}

Resources :: ~Resources() 
{

}

//Function: All initialization is written in here, e.g., memory allocation, variables initialzation.
void Resources :: Initialization()
{
	//One question left to be addressed: if assign *m_seed directly will cause the BUS ERROR 10!!
	m_seed = new int[1];
	*m_seed = (int) time(NULL);
	//cout << "Resources has been initialzed!!\n";
	return;

}
void Resources :: FreeMemory()
{
	delete []m_seed;
	return;
}

double Resources :: uniform_0_1()
{
	double val = 0.0;
	*m_seed = 2045 * (*m_seed) + 1;
	*m_seed = *m_seed - (*m_seed / 1048576) * 1048576;
	val = (*m_seed) / 1048576.0;
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

void Resources :: clc()
{
	m_err_bits = 0;
	m_simu_bits = 0;
	m_err_block = 0;
	return;
}

void Resources :: CalculateBER(int *bb, int *bb_hat, int len_bb)
{
	for(int i = 0; i < len_bb; ++i)
	{
		if(bb[i] != bb_hat[i])
		{
			m_err_bits += 1;
		}
		
	}
	m_simu_bits += len_bb;
	m_ber = m_err_bits / m_simu_bits;
	return;
}

void Resources :: PrintResult(char *Modem_file_name)
{
	sprintf(Result_file_name, "Result of %s", Modem_file_name);
	FILE *fp;
	if(( fp = fopen(Result_file_name, "a+") ) == NULL)
	{
		printf("The file of %s can not be opened!\n", Result_file_name);
		exit(1);

	}
	string  time = getTime();
	fprintf(fp, "\n\nThis simulation starts at %s\n", time.c_str());
	fprintf(fp, "This result is related to [%s]\n", Result_file_name);
	fprintf(fp, "SNR      BER\n");
	fclose(fp);
	return;
}

void Resources :: PrintResult(double snr)
{
	FILE *fp;
	if(( fp = fopen(Result_file_name, "a+") ) == NULL)
	{
		printf("The file of %s can not be opened!\n", Result_file_name);
		exit(1);

	}
	fprintf(fp, "%-3.2f   %-1.10f\n", snr, m_ber);
	fclose(fp);		
	return;
}

void Resources :: PrintResult2Terminal(int simu_blocks, double snr)
{
	if(simu_blocks == 1)
	{
		printf("\n");
	}
	printf("snr = %-3.2f  ber = %-1.4e  simu_blocks = %-d  err_bits = %-.0f\n", snr, m_ber, simu_blocks, m_err_bits);
	return;
}

void Resources :: PrintResult2Terminal(char *Modem_file_name)
{
	string  time = getTime();
	printf("\n-------------------****Enjoy Coding****-------------------\n");
	printf("This simulation starts at %s\n", time.c_str());
	printf("This result is related to [%s]\n", Result_file_name);
	return;
}

string Resources :: getTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    return tmp;
}
