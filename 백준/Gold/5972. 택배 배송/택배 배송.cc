#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_N, g_M;
vector<pair<int, int>> g_Maxtrix[50001];
int g_Visited[50001] = { 0 };

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second > R.second;
	}
};

void Reset()
{
	for (int i = 0; i < 50001; ++i)
	{
		g_Visited[i] = INT_MAX;
	}

}

void Dij()
{
	priority_queue<pair<int ,int>, vector<pair<int ,int>>, Func> Qs;
	Qs.push({ 1, 0 });
	g_Visited[1] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.top();
		Qs.pop();

		for (auto Pair : g_Maxtrix[Cur.first])
		{
			int Nex = Pair.first;
			int NexValue = Cur.second + Pair.second;

			if (g_Visited[Nex] <= NexValue)
				continue;

			g_Visited[Nex] = NexValue;
			Qs.push({Nex, NexValue});
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_N >> g_M;
	for (int i = 0; i < g_M; ++i)
	{
		int Start, End, Value;
		cin >> Start >> End >> Value;

		g_Maxtrix[Start].push_back({End, Value});
		g_Maxtrix[End].push_back({ Start,Value });
	}
	
	Reset();

	Dij();

	cout << g_Visited[g_N];

	return 0;
}