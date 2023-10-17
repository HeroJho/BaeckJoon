#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

#define MAX 200001

int g_iN, g_iM;
int g_DP[MAX] = { 0 };
int g_iAns = 0;
int g_Road[MAX] = { 0 };

void Reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		g_DP[i] = INT_MAX;
		g_Road[i] = -1;
	}
}

bool IsIn(int iValue)
{
	return iValue >= 0 && iValue < MAX;
}

void BFS()
{
	queue<pair<int, int>> Qs;
	Qs.push({ g_iN, 0 });
	g_DP[g_iN] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		if (Cur.first == g_iM)
		{
			g_iAns = Cur.second;
			return;
		}


		int iNexTime = Cur.second + 1;

		if (IsIn(Cur.first * 2) && g_DP[Cur.first * 2] > iNexTime)
		{
			g_DP[Cur.first * 2] = iNexTime;
			g_Road[Cur.first * 2] = Cur.first;
			Qs.push({ Cur.first * 2, iNexTime });
		}
		if (IsIn(Cur.first + 1) && g_DP[Cur.first + 1] > iNexTime)
		{
			g_DP[Cur.first + 1] = iNexTime;
			g_Road[Cur.first + 1] = Cur.first;
			Qs.push({ Cur.first + 1, iNexTime });
		}
		if (IsIn(Cur.first - 1) && g_DP[Cur.first - 1] > iNexTime)
		{
			g_DP[Cur.first - 1] = iNexTime;
			g_Road[Cur.first - 1] = Cur.first;
			Qs.push({ Cur.first - 1, iNexTime });
		}


	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;

	Reset();
	BFS();
	cout << g_iAns << '\n';
	int iIndex = g_iM;
	vector<int> Temp;
	while (g_Road[iIndex] != -1)
	{
		Temp.push_back(g_Road[iIndex]);
		iIndex = g_Road[iIndex];
	}


	for (int i = Temp.size() - 1; i >= 0; --i)
		cout << Temp[i] << ' ';
	cout << g_iM << ' ';

	return 0;
}