#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second > R.second;
	}
};

int g_iN, g_iM, g_iR;
int g_Matrix[101][101] = { 0 };
int g_ItemCount[101] = { 0 };
int g_DP[101] = { 0 };

void Reset()
{
	for (int i = 1; i <= g_iN; ++i)
	{
		g_DP[i] = INT_MAX;
	}
}

void Dij(int iStart)
{
	priority_queue <pair<int, int>, vector<pair<int ,int>>, Func> Qs;
	Qs.push({ iStart , 0});
	g_DP[iStart] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.top();
		Qs.pop();

		for (int i = 1; i <= g_iN; ++i)
		{
			int CurNode = Cur.first;
			if (!g_Matrix[CurNode][i])
				continue;

			int NexValue = Cur.second + g_Matrix[CurNode][i];
			if (g_DP[i] < NexValue)
				continue;

			g_DP[i] = NexValue;
			Qs.push({ i, NexValue });

		}

	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iR >> g_iM;
	for (int i = 1; i <= g_iN; ++i)
	{
		cin >> g_ItemCount[i];
	}
	
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd, iValue;
		cin >> iStart >> iEnd >> iValue;
		g_Matrix[iStart][iEnd] = iValue;
		g_Matrix[iEnd][iStart] = iValue;
	}


	int iAns = 0;
	for (int i = 1; i <= g_iN; ++i)
	{
		Reset();
		Dij(i);

		int iTemp = 0;
		for (int j = 1; j <= g_iN; ++j)
		{
			if (g_iR >= g_DP[j])
			{
				iTemp += g_ItemCount[j];
			}
		}

		if (iAns < iTemp)
			iAns = iTemp;

	}

	cout << iAns;

	return 0;
}