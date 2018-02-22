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

void Modem :: Initialization(char *Modem_file_name)
{

	FILE *fp;
	if(( fp = fopen(Modem_file_name, "r") ) == NULL)
	{
		printf("The file of %s can not be opened!\n", Modem_file_name);
		exit(1);

	}
	char strTemp[500];
	fscanf(fp, "%s", strTemp);
	fscanf(fp,"%d", &m_Nt);

	fscanf(fp, "%s", strTemp);
	fscanf(fp,"%d", &m_Nr);

	fscanf(fp, "%s", strTemp);
	fscanf(fp,"%d", &m_size_constell);

	fscanf(fp, "%s", strTemp);
	fscanf(fp, "%d", &m_len_per_sym);

	m_Constellation = new double*[m_size_constell];
	for(int i = 0; i < m_size_constell; ++i)
	{
		m_Constellation[i] = new double[m_len_per_sym];
	}

	fscanf(fp, "%s", strTemp);
	for(int i = 0; i < m_size_constell; ++i)
	{
		for(int j = 0; j < m_len_per_sym; ++j)
		{
			fscanf(fp,"%lf", &m_Constellation[i][j]);		
		}
	}
	fclose(fp);
	cout << "Modem input is success!\n";
	int int_temp = 1, count_1 = 0;
	m_num_bit_per_sym = 0;
	while(int_temp < m_size_constell)
	{
		++m_num_bit_per_sym;
		int_temp <<= 1;
		count_1 = int_temp & m_size_constell ? count_1 + 1 : count_1;

	}
	bitVecTemp = new int[m_num_bit_per_sym];

	if(count_1 > 1)
	{
		cout << "\nThe value of m_size_constell (= "<< m_size_constell <<") is NOT right!\n";
		exit(1);
	}
	if(m_len_cc % m_num_bit_per_sym != 0)
	{
		cout << "\nNote that m_len_cc(" << m_len_cc << ") is NOT a multiple of m_num_bit_per_sym("<< m_num_bit_per_sym << ")!!!\n";
		exit(1);

	}
	m_num_sym_per_xx = m_len_cc / m_num_bit_per_sym;
	m_num_sym_per_yy = m_num_sym_per_xx;
	cout << "Modem has been initilized!!\n";
	cout << "m_num_sym_per_xx " << m_num_sym_per_xx << endl;
	return;
}
void Modem :: FreeMemory()
{
	for(int i = 0; i< m_len_per_sym; ++i)
	{
		delete []m_Constellation[i];
	}
	delete []m_Constellation;

	delete []bitVecTemp;
	return;
}

void Modem :: MIMO_Modulation(int *bitVec, double *xx)
{
	int bit_idx = 0, xx_idx = 0, yy_idx = 0, sym_idx = 0;
	for(int i = 0; i < m_num_sym_per_xx; ++i)
	{
		//Determine the symbol index
		for(int t = 0; t < m_num_bit_per_sym; ++t)
		{
			bitVecTemp[t] = bitVec[bit_idx++];
			Bit2Dec(bitVecTemp, m_num_bit_per_sym, sym_idx);
		}

		//Assign the transmited signal vector form the constellation based the symbol index
		for(int j = 0; j < m_len_per_sym; ++j)
		{
			xx_idx = i * m_len_per_sym + j;
			xx[xx_idx] = m_Constellation[sym_idx][j];
		}
	}
	return;
}

void Modem :: MIMO_Hard_Demodulation(int *bitVec, double *yy)
{
	int yy_idx = 0, sym_idx = 0, bit_idx = 0, dist_min_idx = 0;
	double dist_min = DBL_MAX, dist_temp = 0.0;
	for(int i = 0; i < m_num_sym_per_yy; ++i)
	{
		dist_min = DBL_MAX, dist_min_idx = 0;
		for(int j = 0; j < m_size_constell; ++j)
		{
			dist_temp = 0.0;
			for(int k = 0; k < m_len_per_sym; ++k)
			{
				dist_temp += (yy[i * m_len_per_sym + k] - m_Constellation[j][k]) * (yy[i * m_len_per_sym + k] - m_Constellation[j][k]);
			}
			//dist_min_idx = dist_min > dist_temp ? j : dist_temp;
			if(dist_min > dist_temp)
			{
				dist_min_idx = j;
				dist_min = dist_temp;
			}

		}
		Dec2Bit(bitVecTemp, m_num_bit_per_sym, dist_min_idx);
		for(int t = 0; t < m_num_bit_per_sym; ++t)
		{
			bitVec[bit_idx++] = bitVecTemp[t];
		}
	}
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
	int i = 0, j = 1;
	while(i < len_bitVec)
	{
		bitVec[len_bitVec - 1 - i] = dec & (1 << i) ? 1 : 0;
		++i;
	}
	return;
}