#include "MIMO_VLC.h"

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

	m_source.Initialization();
	return;
}

void MIMO_VLC :: Simulation()
{
	return;
}

void MIMO_VLC :: FreeMemory()
{
	return;
}
