#include <iostream>
#include <cmath>

using namespace std;

int g_iN, g_iX, g_iY;
int g_iAns;

void Z(int iX, int iY, int iSize)
{
	if (g_iX == iX && g_iY == iY)
	{
		cout << g_iAns;
		return;
	}
	else if (iSize == 1)
	{
		++g_iAns;
		return;
	}

	if (iX <= g_iX && iX + iSize >= g_iX && iY <= g_iY && iY + iSize >= g_iY)
	{
		int iHSize = iSize / 2;
		Z(iX, iY, iHSize);
		Z(iX + iHSize, iY, iHSize);
		Z(iX, iY + iHSize, iHSize);
		Z(iX + iHSize, iY + iHSize, iHSize);
	}
	else
	{
		g_iAns += iSize * iSize;
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> g_iN >> g_iY >> g_iX;

	int iPow = pow(2, g_iN);
	Z(0, 0, iPow);

	return 0;
}