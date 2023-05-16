#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


int g_iN, g_iM;

// 연결 리스트
vector<list<int>> g_Graph;
bool g_bVisited[100] = { false };
vector<vector<int>> g_Dis;

void Reset()
{
	for (int i = 0; i < 100; ++i)
	{
		g_bVisited[i] = false;
	}
}

// BFS를 돌면서
// 방문하면 +1
int BFS(int iStart)
{
	list<int> iQs;
	
	iQs.push_back(iStart);
	g_bVisited[iStart] = true;

	while (!iQs.empty())
	{
		int iCurNum = iQs.front();
		iQs.pop_front();

		for (auto iNum : g_Graph[iCurNum])
		{
			if (g_bVisited[iNum])
				continue;

			iQs.push_back(iNum);
			g_bVisited[iNum] = true;

			g_Dis[iStart][iNum] = g_Dis[iStart][iCurNum] + 1;
		}

	}

	int iSumCount = 0;
	for (int i = 0; i < g_Dis[iStart].size(); ++i)
	{
		iSumCount += g_Dis[iStart][i];
	}

	return iSumCount;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	g_Graph.resize(g_iN);
	g_Dis.resize(g_iN);
	for (int i = 0; i < g_iN; ++i)
	{
		g_Dis[i].resize(g_iN);
	}

	for (int i = 0; i < g_iM; ++i)
	{
		int iTemp1, iTemp2;
		cin >> iTemp1 >> iTemp2;
		iTemp1 -= 1;
		iTemp2 -= 1;
		g_Graph[iTemp1].push_back(iTemp2);
		g_Graph[iTemp2].push_back(iTemp1);
	}

	int iMinCount = BFS(0);
	int iAns = 0;
	for (int i = 1; i < g_iN; ++i)
	{
		Reset();
		int iCount = BFS(i);
		if (iMinCount > iCount)
		{
			iMinCount = iCount;
			iAns = i;
		}
		else if(iMinCount == iCount)
		{
			if (i < iAns)
				iAns = i;
		}
	}

	cout << ++iAns;

	return 0;
}