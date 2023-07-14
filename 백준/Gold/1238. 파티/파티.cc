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

vector<pair<int, int>> g_Matrix[1001];
vector<int> g_iDiss;
vector<int> g_iMinDis(1001, 0);

void Dij(int iStart)
{
	g_iDiss.clear();
	g_iDiss.resize(g_iN + 1, INT_MAX);

	priority_queue < pair<int, int>, vector<pair<int, int>>, Fuc> Qs;
	Qs.push({iStart, 0});

	g_iDiss[iStart] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.top();
		Qs.pop();


		for (int i = 0; i < g_Matrix[Cur.first].size(); ++i)
		{
			int iNex = g_Matrix[Cur.first][i].first;
			int iNexDis = Cur.second + g_Matrix[Cur.first][i].second;

			if (iNexDis < g_iDiss[iNex])
			{
				g_iDiss[iNex] = iNexDis;
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
		g_Matrix[iStart].push_back({iEnd, iDis});
	}

	for (int i = 1; i <= g_iN; ++i)
	{
		Dij(i);
		g_iMinDis[i] = g_iDiss[g_iX];
	}

	Dij(g_iX);
	int iMaxDis = 0;
	for (int i = 1; i <= g_iN; ++i)
	{
		iMaxDis = max(g_iMinDis[i] + g_iDiss[i], iMaxDis);
	}

	cout << iMaxDis;

	return 0;
}