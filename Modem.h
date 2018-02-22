/*************************************************************************
     > The program can only be employed for academic research.
     > File Name: Modem.h
     > Author: Chauency
     > Mail: chauencychan.gmail.com
     > Created Time: 2018-02-17
     > Description: This program is the modulation and demodulation module.
************************************************************************/
#ifndef MODEM_H
#define MODEM_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <float.h>
using namespace std;
class Modem
{
public:
	//Pointer type members
	double **m_Constellation;
	int *bitVecTemp;

	//Built-in type members
	int m_len_cc;
	int m_size_constell;//The numebr of elements in the constellation
	int m_len_per_sym;//The length of per symbol
	int m_num_bit_per_sym;//The number of bits mapped into one symbol
	int m_Nt;//The number of transmitted antennas
	int m_Nr;//The number of received antennas
	int m_num_sym_per_xx;//The number of symbol in a transmited singal vector
	int m_num_sym_per_yy;//The number of symbol in a received signal vector

	Modem();
	~Modem();
	void Initialization(char *Modem_file_name);
	void FreeMemory();

	void MIMO_Modulation(int *bitVec, double *xx);
	void MIMO_Hard_Demodulation(int *bitVec, double *yy);

	void Bit2Dec(int *bitVec, int len_bitVec, int &dec);
	void Dec2Bit(int *bitVec, int len_bitVec, int &dec);

};

#endif