#include "MIMO_VLC.h"
extern double powerEleRe;

MIMO_VLC :: MIMO_VLC()
{

}

MIMO_VLC :: ~MIMO_VLC()
{

}

void MIMO_VLC :: Initialization()
{


	FILE *fp;
	char Setup_file_name[500] =  "Setup_of_MIMO_VLC.txt";
	char strTemp[500];
	if(( fp = fopen(Setup_file_name, "r") ) == NULL)
	{
		printf("%s can not be opened!\n", Setup_file_name);
		exit(1);

	}

	fscanf(fp, "%s", strTemp);
	fscanf(fp,"%lf", &m_minsnr);

	fscanf(fp, "%s", strTemp);
	fscanf(fp,"%lf", &m_maxsnr);

	fscanf(fp, "%s", strTemp);
	fscanf(fp,"%lf", &m_arcsnr);

	fscanf(fp, "%s", strTemp);
	fscanf(fp, "%d", &m_max_block);

	fscanf(fp, "%s", strTemp);
	fscanf(fp, "%d", &m_len_bb);

	fscanf(fp, "%s", strTemp);
	fscanf(fp, "%s", m_Modem_file_name);

	fclose(fp);
	m_len_cc = m_len_bb;//This is valid in uncoded scheme
	m_modem.m_len_cc = m_len_cc;//Pass m_len_cc to Modem module

	m_modem.Initialization(m_Modem_file_name);

	m_len_xx = m_modem.m_len_per_sym * m_modem.m_num_sym_per_xx;
	m_len_yy = m_len_xx;
	m_bb = new int[m_len_bb];
	m_cc = new int[m_len_cc];
	m_xx = new double[m_len_xx];
	m_yy = new double[m_len_yy];
	m_nn = new double[m_len_yy];
	m_cc_hat = new int[m_len_cc];
	m_bb_hat = new int[m_len_bb];
	

	m_source.Initialization();
	//cout << "MIMO-VLC has been initialzed!!\n";

	m_source.PrintResult(m_Modem_file_name);
	m_source.PrintResult2Terminal(m_Modem_file_name);



	return;
}

void MIMO_VLC :: Simulation()
{
	Initialization();
	for(double snr = m_minsnr; snr <= m_maxsnr; snr += m_arcsnr)
	{
		//m_var = pow(10, -0.1 * snr);
		m_var = pow(10, -0.1 * snr) * powerEleRe * powerEleRe;
		m_sigma = sqrt(m_var);
		m_source.clc();
		for(int simu_blocks = 1; simu_blocks <= m_max_block; ++simu_blocks)
		{
			m_source.getBitVec(m_len_bb, m_bb);
#if DEG			
			for(int i = 0; i < m_len_bb; ++i)
			{
				cout << m_bb[i] << " ";
			}
			cout << endl;
#endif

			//channel coding
			for(int i = 0; i < m_len_bb; ++i)
			{
				m_cc[i] = m_bb[i];
			}

			//modulation
			m_modem.MIMO_Modulation(m_cc, m_xx);
#if DEG
			for(int i = 0; i < m_len_xx; i++)
			{
				cout << m_xx[i] << " ";
			}
			cout << endl;
#endif

			//AWGN
			m_source.getGaussNoiseVec(m_len_yy, m_nn);
			for(int i = 0; i < m_len_yy; ++i)
			{
				m_yy[i] = m_xx[i] + m_nn[i] * m_sigma;
				//m_yy[i] = m_xx[i];
			}
#if DEG

			for(int i = 0; i < m_len_xx; i++)
			{
				cout << m_yy[i] << " ";
			}
			cout << endl;
#endif

			//demodulation
			m_modem.MIMO_Hard_Demodulation(m_bb_hat, m_yy);
#if DEG
			for(int i = 0; i < m_len_bb; ++i)
			{
				cout << m_bb_hat[i] << " ";
			}
			cout << endl;
#endif

			m_source.CalculateBER(m_bb, m_bb_hat, m_len_bb);
			if(simu_blocks == 1 || simu_blocks == m_max_block || simu_blocks % 100 == 0)
			{
				m_source.PrintResult2Terminal(simu_blocks, snr);
			}

		}
		m_source.PrintResult(snr);
	}

	FreeMemory();
	return;
}

void MIMO_VLC :: FreeMemory()
{
	delete []m_bb;
	delete []m_cc;
	delete []m_xx;
	delete []m_yy;
	delete []m_nn;
	delete []m_cc_hat;
	delete []m_bb_hat;
	m_source.FreeMemory();
	m_modem.FreeMemory();
	return;
}
