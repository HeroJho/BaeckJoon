#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


int g_iN;
int g_iWCount = 0;
int g_iBCount = 0;
int g_iMatrix[128][128] = { 0 };


void Iter(int iX, int iY, int iSize)
{
	int iPreNum = g_iMatrix[iY][iX];

	for (int y = iY; y < iY + iSize; ++y)
	{
		for (int x = iX; x < iX + iSize; ++x)
		{
			// 다르다 = 더 쪼갠다
			if (iPreNum != g_iMatrix[y][x])
			{
				int iNSize = iSize / 2;
				Iter(iX, iY, iNSize);
				Iter(iX + iNSize, iY, iNSize);
				Iter(iX, iY + iNSize, iNSize);
				Iter(iX + iNSize, iY + iNSize, iNSize);
				return;
			}
		}
	}

	// 다 같다 = 카운팅
	if (iPreNum == 0)
	{
		++g_iWCount;
	}
	else
	{
		++g_iBCount;
	}

	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cin >> g_iMatrix[y][x];
		}
	}

	Iter(0, 0, g_iN);

	cout << g_iWCount << '\n';
	cout << g_iBCount;

	return 0;
}