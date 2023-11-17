#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"
#include <math.h>

using namespace std;

int g_iN;
int g_Matrix[20][20] = { 0 };
bool g_Ts[20] = { false };
int g_iAns = INT_MAX;

void DFS(int iDepth, int iPreIndex)
{
	if (iDepth == g_iN / 2)
	{
		vector<int> L, R;
		for (int i = 0; i < g_iN; ++i)
		{
			if (g_Ts[i])
				L.push_back(i);
			else
				R.push_back(i);

		}

		int iLSum = 0;
		for (int i = 0; i < L.size(); ++i)
		{
			for (int j = i + 1; j < L.size(); ++j)
			{
				iLSum += g_Matrix[L[i]][L[j]];
				iLSum += g_Matrix[L[j]][L[i]];
			}
		}

		int iRSum = 0;
		for (int i = 0; i < R.size(); ++i)
		{
			for (int j = i + 1; j < R.size(); ++j)
			{
				iRSum += g_Matrix[R[i]][R[j]];
				iRSum += g_Matrix[R[j]][R[i]];
			}
		}

		int iDis = abs(iRSum - iLSum);
		if (g_iAns > iDis)
			g_iAns = iDis;

		return;
	}

	for (int i = iPreIndex + 1; i < g_iN; ++i)
	{
		g_Ts[i] = true;
		DFS(iDepth + 1, i);
		g_Ts[i] = false;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			cin >> g_Matrix[i][j];
		}
	}

	DFS(0, -1);

	cout << g_iAns;

	return 0;
}