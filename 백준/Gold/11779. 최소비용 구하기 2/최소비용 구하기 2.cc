#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define MAX 1001
#define LL long long

using namespace std;

class Func
{
public:
	bool operator()(pair<int, LL> L, pair<int, LL> R)
	{
		return L.second > R.second;
	}
};

int g_N, g_M;
int g_S, g_E;
int g_Matrix[MAX][MAX] = {0};

LL g_DP[MAX] = { -1 };
int g_Par[MAX] = { -1 };

void Reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		g_DP[i] = -1;
		g_Par[i] = -1;
	}

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			g_Matrix[i][j] = INT_MAX;
		}
	}

}

void Dij()
{
	priority_queue<pair<int, LL>, vector<pair<int, LL>>, Func> Qs;
	Qs.push({ g_S,0 });
	g_DP[g_S] = 0;

	while (!Qs.empty())
	{
		pair<int, LL> Cur = Qs.top();
		Qs.pop();

		if (Cur.first == g_E)
			return;

		for (int i = 1; i <= g_N; ++i)
		{
			if (INT_MAX == g_Matrix[Cur.first][i])
				continue;

			int Nex = i;
			LL NexValue = g_Matrix[Cur.first][i] + Cur.second;

			if (g_DP[Nex] != -1 && g_DP[Nex] <= NexValue)
				continue;
			g_DP[Nex] = NexValue;

			g_Par[Nex] = Cur.first;

			Qs.push({ Nex, NexValue });

		}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Reset();

	cin >> g_N >> g_M;
	for (int i = 0; i < g_M; ++i)
	{
		int Start, End, Value;
		cin >> Start >> End >> Value;
		if (g_Matrix[Start][End] > Value)
			g_Matrix[Start][End] = Value;

	}
	cin >> g_S >> g_E;


	Dij();

	int Count = 0;
	int Num = g_E;
	vector<int> Ways;
	while (Num != -1)
	{
		Ways.push_back(Num);
		Num = g_Par[Num];
	}

	cout << g_DP[g_E] << endl;
	cout << Ways.size() << endl;
	for (int i = Ways.size() - 1; i >= 0; --i)
	{
		cout << Ways[i] << ' ';
	}

	return 0;
}

