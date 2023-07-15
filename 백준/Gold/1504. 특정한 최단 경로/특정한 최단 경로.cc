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
	bool operator()(pair<int, long long> L, pair<int, long long> R)
	{
		return L.second > R.second;
	}
};

int g_iN, g_iM, g_iU, g_iV;
vector<pair<int, long long>> g_Matrix[801];
vector<long long> g_Dis;


void Dji(int iStart)
{
	g_Dis.clear();
	g_Dis.resize(g_iN + 1, LLONG_MAX);

	priority_queue<pair<int, long long>, vector<pair<int, long long>>, Fuc> Qs;

	Qs.push({ iStart, 0 });

	while (!Qs.empty())
	{
		pair<int, long long> CurNode = Qs.top();
		Qs.pop();

		if (g_Dis[CurNode.first] < CurNode.second)
			continue;

		for (int i = 0; i < g_Matrix[CurNode.first].size(); ++i)
		{
			int iNextNode = g_Matrix[CurNode.first][i].first;
			long long iNextDis = CurNode.second + g_Matrix[CurNode.first][i].second;

			if (g_Dis[iNextNode] > iNextDis)
			{
				g_Dis[iNextNode] = iNextDis;
				Qs.push({ iNextNode, iNextDis });
			}

		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		long long iStart, iEnd, iDis;
		cin >> iStart >> iEnd >> iDis;
		g_Matrix[iStart].push_back({ iEnd, iDis });
		g_Matrix[iEnd].push_back({ iStart, iDis });
	}
	cin >> g_iU >> g_iV;

	long long iLDis = 0, iMDis = 0, iRDis = 0, iMin = 0;

	if (g_iU == 1 && g_iV == g_iN)
	{
		Dji(g_iV);
		iMDis = g_Dis[g_iU];

		if (iMDis == LLONG_MAX)
			cout << -1;
		else
			cout << iMDis;

		return 0;
	}

	Dji(g_iU);
	iLDis = g_Dis[1];
	iMDis = g_Dis[g_iV];
	Dji(g_iV);
	iRDis = g_Dis[g_iN];
	iMin = iLDis + iMDis + iRDis;
	if (iLDis == LLONG_MAX || iMDis == LLONG_MAX || iRDis == LLONG_MAX)
		iMin = LLONG_MAX;

	Dji(g_iV);
	iLDis = g_Dis[1];
	iMDis = g_Dis[g_iU];
	Dji(g_iU);
	iRDis = g_Dis[g_iN];
	iMin = min(iMin, iLDis + iMDis + iRDis);

	if (iLDis == LLONG_MAX || iMDis == LLONG_MAX || iRDis == LLONG_MAX)
		cout << -1;
	else
		cout << iMin;

	return 0;
}