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
	Modem();
	~Modem();
	void MIMO_Modulation();
	void MIMO_Hard_Demodulation(double *yy, int len_yy, double *yy_prob);

};

#endif