/*************************************************************************
     > The program can only be employed for academic research.
     > File Name: Modem.cpp
     > Author: Chauency
     > Mail: chauencychan.gmail.com
     > Created Time: 2018-02-17
     > Description: This program is the implementation of Modem.h  
************************************************************************/

#include "Modem.h"
Modem :: Modem()
{

}

Modem :: ~Modem()
{

}

void Modem :: MIMO_Modulation(int *bitVec, int len_bit_vec, double *xx)
{
	return;
}

void Modem :: Bit2Dec(int *bitVec, int len_bitVec, int &dec)
{
	dec = 0;
	int pow = 0;
	while(len_bitVec--)
	{
		dec += bitVec[len_bitVec] * (1 << (pow++));
	}
	return;
}

void Modem :: Dec2Bit(int *bitVec, int len_bitVec, int &dec)
{
	return;
}