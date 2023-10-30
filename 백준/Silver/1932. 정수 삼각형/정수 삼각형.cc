#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN;
vector<int> g_Inputs;
int g_iMax = 0;
int g_DP[300000] = { 0 };

int DFS(int iT, int iIndex, int iSum)
{
	if (iT == g_iN)
	{
		g_DP[iIndex] = g_Inputs[iIndex];
		return g_DP[iIndex];
	}

	if (g_DP[iIndex] != -1)
	{
		return g_DP[iIndex];
	}


	int iL, iR;
	iL = iIndex + iT;
	iR = iL + 1;

	int iLNum, iRNum;
	iLNum = DFS(iT + 1, iL, iSum + g_Inputs[iL]);
	iRNum = DFS(iT + 1, iR, iSum + g_Inputs[iR]);
	g_DP[iIndex] = max(iLNum, iRNum) + g_Inputs[iIndex];

	return g_DP[iIndex];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	for (int i = 0; i < 300000; ++i)
	{
		g_DP[i] = -1;
	}



	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int iTemp; cin >> iTemp;
			g_Inputs.push_back(iTemp);
		}
	}

	

	cout << DFS(1, 0, g_Inputs[0]);

	return 0;
}