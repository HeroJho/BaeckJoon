#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
int g_DP[200001] = { 0 };

void Reset()
{
	for (int i = 0; i < 200001; ++i)
	{
		g_DP[i] = INT_MAX;
	}
}

void BFS()
{
	Reset();

	queue<pair<int, int>> Qs;
	Qs.push({ g_iN, 0 });

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		if (Cur.first < 0 || Cur.first > 200000)
			continue;
		if (g_DP[Cur.first] <= Cur.second)
			continue;
		g_DP[Cur.first] = Cur.second;

		//if (Cur.first == g_iM)
		//{
		//	cout << g_DP[Cur.first];
		//}

		Qs.push({ Cur.first - 1, Cur.second + 1 });
		Qs.push({ Cur.first + 1, Cur.second + 1 });
		Qs.push({ Cur.first * 2, Cur.second });

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;

	BFS();

	cout << g_DP[g_iM];

	return 0;
}