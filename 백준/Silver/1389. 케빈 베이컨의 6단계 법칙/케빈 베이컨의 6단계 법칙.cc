#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define N_MAX 101


using namespace std;

int g_N, g_M;
int g_Matrix[N_MAX][N_MAX] = { 0 };

int g_NDis[N_MAX] = { 0 };
int g_Anss[N_MAX] = { 0 };

void Reset()
{
	for (int i = 1; i <= g_N; ++i)
	{
		g_NDis[i] = -1;
	}
}

void BFS(int Start)
{
	queue<int> Qs;
	Qs.push(Start);
	g_NDis[Start] = 0;

	int Count = 1;
	while (!Qs.empty())
	{
		int Size = Qs.size();

		for (int t = 0; t < Size; ++t)
		{
			int Cur = Qs.front();
			Qs.pop();

			for (int i = 1; i <= g_N; ++i)
			{
				if (Cur == i)
					continue;

				if (g_NDis[i] != -1)
					continue;

				if (g_Matrix[Cur][i] == 0)
					continue;

				g_NDis[i] = Count;

				Qs.push(i);

			}

		}

		++Count;

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N >> g_M;
	for (int i = 0; i < g_M; ++i)
	{
		int Temp1, Temp2;
		cin >> Temp1 >> Temp2;
		g_Matrix[Temp1][Temp2] = 1;
		g_Matrix[Temp2][Temp1] = 1;
	}


	for (int i = 1; i <= g_N; ++i)
	{
		Reset();
		BFS(i);

		for (int t = 1; t <= g_N; ++t)
		{
			if(g_NDis[t] != -1)
				g_Anss[i] += g_NDis[t];
		}

	}

	int Min = INT_MAX;
	int MinIndex = 0;
	for (int i = g_N; i > 0; --i)
	{
		if (Min >= g_Anss[i])
		{
			Min = g_Anss[i];
			MinIndex = i;
		}
	}

	cout << MinIndex;

	return 0;
}

