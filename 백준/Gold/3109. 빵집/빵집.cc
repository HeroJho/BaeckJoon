#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int g_N, g_M;
char g_Matrix[10000][500] = { 0 };

bool g_Visited[10000][500] = { false };
int g_DirX[3] = { 1, 1, 1 };
int g_DirY[3] = { -1, 0, 1 };

int g_Ans = 0;

bool IsIn(int X, int Y)
{
	return X >= 0 && X < g_M&& Y >= 0 && Y < g_N;
}

bool DFS(pair<int, int> CurPos)
{
	if (CurPos.first == g_M - 1)
	{
		g_Ans++;
		return true;
	}


	for (int i = 0; i < 3; ++i)
	{
		int inX = g_DirX[i] + CurPos.first;
		int inY = g_DirY[i] + CurPos.second;

		if (!IsIn(inX, inY))
			continue;
			
		if (g_Matrix[inY][inX] == 'x')
			continue;

		if (g_Visited[inY][inX])
			continue;
		g_Visited[inY][inX] = true;


		if (DFS({ inX, inY }))
			return true;

	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N >> g_M;
	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_M; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	for (int y = 0; y < g_N; ++y)
	{
		if (g_Matrix[y][0] == 'x')
			continue;
		if (g_Visited[y][0])
			continue;
		g_Visited[y][0] = true;

		DFS({ 0, y });
	}

	cout << g_Ans;

	return 0;
}
