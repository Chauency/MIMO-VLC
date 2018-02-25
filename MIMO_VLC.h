/*************************************************************************
     > The program can only be employed for academic research.
     > File Name: MIMO_VLC.h
     > Author: Chauency
     > Mail: chauencychan.gmail.com
     > Created Time: 2018-02-17
     > Description: The main file of this project, where the results in [1] are reproduced.
     > Reference:
     [1] T. Fath and H. Haas, "Performance Comparison of MIMO Techniques for Optical Wireless Communications in Indoor Environments," in IEEE Transactions on Communications, vol. 61, no. 2, pp. 733-742, February 2013.
************************************************************************/
#ifndef MIMO_VLC_H
#define MIMO_VLC_H
#include <iostream>
#include "Resources.h"
#include "Modem.h"
#include <cmath>
#define DEG 0
using namespace std;
class MIMO_VLC
{
public:

	//Pointer type members
	int *m_bb;//Information bit vector
	int *m_cc;//Encoded bit vector
	double *m_xx;//Modulated signal vector
	double *m_yy;//Received signal vector
	double *m_nn;//Noise vector
	double *m_yy_prob;//Demodulated symbol probability
	int *m_cc_hat;//Decoded bit vector
	int *m_bb_hat;//Decoded information bit vector

	//Built-in type members
	int m_len_bb;
	int m_len_cc;
	int m_len_xx;
	int m_len_yy;
	int m_len_yy_prob;

	double m_minsnr, m_maxsnr, m_arcsnr;
	char m_Modem_file_name[100];

	int m_max_block;
	double m_var, m_sigma;

	//Type of class member
	Resources m_source;
	Modem m_modem;

	MIMO_VLC();
	~MIMO_VLC();
	void Initialization();
	void Simulation();
	void FreeMemory();
};


#endif
