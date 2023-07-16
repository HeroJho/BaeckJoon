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
	bool operator()(pair<int ,int> L, pair<int, int> R)
	{
		return L.second > R.second;
	}
};

int g_iN, g_iM;
vector<pair<int, int>> g_Matrix[20001];
vector<int> g_iDiss;

void Dij(int iStart)
{
	g_iDiss.clear();
	g_iDiss.resize(g_iN + 1, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, Fuc> Qs;
	Qs.push({ iStart, 0 });
	g_iDiss[iStart] = 0;

	while (!Qs.empty())
	{
		pair<int, int> CurNode = Qs.top();
		Qs.pop();

		if (g_iDiss[CurNode.first] < CurNode.second)
			continue;

		for (int i = 0; i < g_Matrix[CurNode.first].size(); ++i)
		{
			int NextNode = g_Matrix[CurNode.first][i].first;
			int NextDis = CurNode.second + g_Matrix[CurNode.first][i].second;

			if (g_iDiss[NextNode] > NextDis)
			{
				g_iDiss[NextNode] = NextDis;
				Qs.push({ NextNode, NextDis });
			}

		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	int iBegin;
	cin >> iBegin;
	
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd, iDis;
		cin >> iStart >> iEnd >> iDis;
		g_Matrix[iStart].push_back({ iEnd, iDis });
	}
	
	Dij(iBegin);

	for (int i = 1; i <= g_iN; ++i)
	{
		if (g_iDiss[i] == INT_MAX)
		{
			if (i != iBegin)
				cout << "INF" << '\n';
			else
				cout << 0 << '\n';
		}
		else
			cout << g_iDiss[i] << '\n';
	}

	return 0;
}