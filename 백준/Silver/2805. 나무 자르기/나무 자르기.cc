#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN, g_iM;
int g_iMax = 0;
vector<int> g_iWoods;


long long Cut(int iMiddle)
{
	long long iSum = 0;

	for (auto iNum : g_iWoods)
	{
		int iCut = iNum - iMiddle;
		if (0 < iCut)
		{
			iSum += iCut;
		}
	}

	return iSum;
}

int Sol()
{
	int iLeft = 0, iRight = g_iMax;

	int iMiddle = 0;

	while (iLeft <= iRight)
	{
		iMiddle = (iLeft + iRight) / 2;

		long long iCut = Cut(iMiddle);


		if (iCut == g_iM)
		{
			return iMiddle;
		}
		else if (iCut < g_iM)
		{
			iRight = iMiddle - 1;
		}
		else if (iCut > g_iM)
		{
			iLeft = iMiddle + 1;
			g_iMax = iMiddle;
		}

	}

	return g_iMax;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		g_iWoods.push_back(iTemp);
		if (g_iMax < iTemp)
			g_iMax = iTemp;
	}

	int iSol = Sol();

	cout << iSol;

	return 0;
}