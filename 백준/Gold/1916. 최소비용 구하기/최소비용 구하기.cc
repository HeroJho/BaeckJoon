#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
vector<vector<pair<int, int>>> g_Matrix(1001);
vector<int> g_MinDis(1001, INT_MAX);

int Dij(int iStart, int iEnd)
{
	queue<pair<int, int>> Qs;
	Qs.push({ iStart, 0 });

	g_MinDis[iStart] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		if (g_MinDis[Cur.first] < Cur.second)
			continue;

		for (int i = 0; i < g_Matrix[Cur.first].size(); ++i)
		{
			int iNex = g_Matrix[Cur.first][i].first;
			int iNexDis = Cur.second + g_Matrix[Cur.first][i].second;
			if (g_MinDis[iNex] > iNexDis)
			{
				g_MinDis[iNex] = iNexDis;
				Qs.push({iNex, iNexDis});
			}
		}

	}

	return g_MinDis[iEnd];
}

int main()
{
	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd, iDis;
		cin >> iStart >> iEnd >> iDis;

		g_Matrix[iStart].push_back({ iEnd, iDis });
	}

	int iStart, iEnd;
	cin >> iStart >> iEnd;

	cout << Dij(iStart, iEnd);

	return 0;
}