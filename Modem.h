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

class Modem
{
public:
	//Pointer type members
	double **m_constellation;

	//Built-in type members
	int m_size_constell;//The numebr of elements in the constellation
	int m_len_per_symbol;//The length of per symbol
	int m_Nt;//The number of transmitted antennas
	int m_Nr;//The number of received antennas
	int m_num_sym_per_yy;//The number of symbol in a received signal

	Modem();
	~Modem();
	void MIMO_Modulation(int *bitVec, int len_bit_vec, double *xx);
	void MIMO_Hard_Demodulation(double *yy, int len_yy, double *yy_hat);
	void Bit2Dec(int *bitVec, int len_bitVec, int &dec);
	void Dec2Bit(int *bitVec, int len_bitVec, int &dec);

};

#endif