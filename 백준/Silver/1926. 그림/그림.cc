#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_N, g_M;
int g_Matrix[500][500] = { 0 };
bool g_Visited[500][500] = { false };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };

void Reset()
{
	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_M; ++x)
		{
			g_Visited[y][x] = false;
		}
	}
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_M && iY >= 0 && iY < g_N;
}

int BFS(pair<int ,int> StartPos, int CheckIndex)
{
	queue<pair<int ,int>> Qs;
	Qs.push(StartPos);
	g_Visited[StartPos.second][StartPos.first] = true;

	int iCount = 1;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int inX = g_DirX[i] + Cur.first;
			int inY = g_DirY[i] + Cur.second;
		
			if (!IsIn(inX, inY))
				continue;
			if (g_Visited[inY][inX])
				continue;
			if (g_Matrix[inY][inX] != CheckIndex)
				continue;

			g_Visited[inY][inX] = true;
			Qs.push({inX, inY});
			++iCount;
		}

	}

	return iCount;
}

int Iter_BFS(int DrawIndex)
{
	int iCount = 0;
	int iS = 0;
	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_M; ++x)
		{
			if (g_Visited[y][x] || g_Matrix[y][x] != DrawIndex)
				continue;
			++iS;
			iCount = max(iCount ,BFS({ x, y }, DrawIndex));
		}
	}
	cout << iS << endl;
	return iCount;
}

int Draw(int DrawIndex)
{
	Reset();
	int iCount = 0;

	iCount = Iter_BFS(DrawIndex);

	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_N >> g_M;
	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_M; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	int iAns = 0;
	iAns  = Draw(1);

	cout << iAns;

	return 0;
}