#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

class Fuc
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second > R.second;
	}
};

int g_iN, g_iM, g_iX;

vector<pair<int, int>> g_Matrix[1001][2];
vector<int> g_iDiss[2];
vector<int> g_iMinDis(1001, 0);

void Dij(int iInv)
{
	g_iDiss[iInv].clear();
	g_iDiss[iInv].resize(g_iN + 1, INT_MAX);

	priority_queue < pair<int, int>, vector<pair<int, int>>, Fuc> Qs;
	Qs.push({g_iX, 0});

	g_iDiss[iInv][g_iX] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.top();
		Qs.pop();


		for (int i = 0; i < g_Matrix[Cur.first][iInv].size(); ++i)
		{
			int iNex = g_Matrix[Cur.first][iInv][i].first;
			int iNexDis = Cur.second + g_Matrix[Cur.first][iInv][i].second;

			if (iNexDis < g_iDiss[iInv][iNex])
			{
				g_iDiss[iInv][iNex] = iNexDis;
				Qs.push({ iNex, iNexDis });
			}

		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM >> g_iX;
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd, iDis;
		cin >> iStart >> iEnd >> iDis;
		g_Matrix[iStart][0].push_back({ iEnd, iDis });
		g_Matrix[iEnd][1].push_back({iStart, iDis});
	}

	
	Dij(1); // A -> X
	Dij(0); // X -> A

	int iMaxDis = 0;
	for (int i = 1; i <= g_iN; ++i)
	{
		iMaxDis = max(g_iDiss[0][i] + g_iDiss[1][i], iMaxDis);
	}

	cout << iMaxDis;

	return 0;
}