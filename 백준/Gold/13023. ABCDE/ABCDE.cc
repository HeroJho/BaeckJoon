#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
vector<int> g_Matrix[2001];
bool g_Visited[2001] = { false };

void Reset()
{
	for (int i = 0; i <= g_iN; ++i)
	{
		g_Visited[i] = false;
	}
}

bool DFS(int iDepth, int iCurIndex)
{
	if (iDepth == 4)
	{
		return true;
	}

	for (int i = 0; i < g_Matrix[iCurIndex].size(); ++i)
	{
		int inIndex = g_Matrix[iCurIndex][i];
		if (g_Visited[inIndex])
			continue;

		g_Visited[inIndex] = true;
		if (DFS(iDepth + 1, inIndex))
			return true;
		g_Visited[inIndex] = false;

	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		int iTemp1, iTemp2;
		cin >> iTemp1 >> iTemp2;
		g_Matrix[iTemp1].push_back(iTemp2);
		g_Matrix[iTemp2].push_back(iTemp1);
	}

	for (int i = 0; i <= g_iN; ++i)
	{
		Reset();
		g_Visited[i] = true;
		if (DFS(0, i))
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}