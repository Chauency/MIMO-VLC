#include "MIMO_VLC.h"
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	MIMO_VLC m_MIMO_VLC;
	m_MIMO_VLC.Initialization();
	int dec1 = 0;
	int bit[4] = {1,1,1,1};
	int len = 4;
	m_MIMO_VLC.m_modem.Bit2Dec(bit, len, dec1);
	cout << dec1 << endl;
	return 0;
}