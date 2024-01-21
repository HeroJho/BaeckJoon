#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int g_N;
vector<pair<int, int>> g_Matrix[100001];
int g_DP[100001] = { INT_MAX };

void Reset()
{
	for (int i = 1; i <= g_N; ++i)
	{
		g_DP[i] = INT_MAX;
	}
}

void BFS(int Start)
{
	queue<pair<int ,int>> Qs;
	Qs.push({Start, 0});
	g_DP[Start] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		for (int i = 0; i < g_Matrix[Cur.first].size(); ++i)
		{
			
			int inPos = g_Matrix[Cur.first][i].first;
			int inDis = Cur.second + g_Matrix[Cur.first][i].second;

			if (g_DP[inPos] < inDis)
				continue;
			g_DP[inPos] = inDis;

			Qs.push({inPos, inDis});

		}

	}

}

void FindMaxDis(int& OUT_Dis, int& OUT_Index)
{
	int Max = 0;
	int MaxIndex = -1;
	for (int i = 1; i <= g_N; ++i)
	{
		if (Max < g_DP[i])
		{
			Max = g_DP[i];
			MaxIndex = i;
		}
	}

	OUT_Dis = Max;
	OUT_Index = MaxIndex;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N;
	for (int i = 0; i < g_N; ++i)
	{
		int Num; cin >> Num;

		while (true)
		{
			int OtherNum, Dis;
			cin >> OtherNum;
			if (OtherNum == -1)
				break;
			cin >> Dis;

			g_Matrix[Num].push_back({ OtherNum, Dis });
		}

	}

	int Dis, Index;
	Reset();
	BFS(1);
	FindMaxDis(Dis, Index);

	Reset();
	BFS(Index);
	FindMaxDis(Dis, Index);
	
	cout << Dis;

	return 0;
}
