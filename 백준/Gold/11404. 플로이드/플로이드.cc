#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
int g_Matrix[101][101] = { 0 };
int g_DP[101] = { 0 };

int g_Ans[101][101] = { 0 };


void Reset()
{
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			g_Matrix[i][j] = INT_MAX;
		}
	}
}
void Reset_DP()
{
	for (int j = 0; j < 101; ++j)
	{
		g_DP[j] = INT_MAX;
	}
}


void Dij(int iStart)
{
	priority_queue<pair<int, int>> Qs;
	Qs.push({ 0, iStart });
	g_DP[iStart] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.top();
		Qs.pop();

		for (int i = 1; i <= g_iN; ++i)
		{
			if (INT_MAX == g_Matrix[Cur.second][i])
				continue;

			int inGold = g_Matrix[Cur.second][i] + Cur.first;
			if (inGold < g_DP[i])
			{
				g_DP[i] = inGold;
				Qs.push({ inGold, i });
			}

		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Reset();
	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd, iGold;
		cin >> iStart >> iEnd >> iGold;
		if (g_Matrix[iStart][iEnd] > iGold)
			g_Matrix[iStart][iEnd] = iGold;

	}


	for (int i = 1; i <= g_iN; ++i)
	{
		Reset_DP();
		Dij(i);

		for (int j = 1; j <= g_iN; ++j)
		{
			if(g_DP[j] == INT_MAX)
				g_Ans[i][j] = 0;
			else
				g_Ans[i][j] = g_DP[j];
		}

	}

	for (int i = 1; i <= g_iN; ++i)
	{
		for (int j = 1; j <= g_iN; ++j)
		{
			cout << g_Ans[i][j] << " ";
		}

		cout << '\n';
	}


	return 0;
}