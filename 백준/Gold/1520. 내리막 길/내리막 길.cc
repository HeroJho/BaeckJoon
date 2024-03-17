#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int N, M;
int Matrix[500][500] = { 0 };
int DP[500][500] = { -1 };
int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

void Reset()
{
	for (int i = 0; i < 500; ++i)
	{
		for (int j = 0; j < 500; ++j)
		{
			DP[i][j] = -1;
		}
	}
}

bool IsIn(int X, int Y)
{
	return X >= 0 && X < M && Y >= 0 && Y < N;
}

int DFS(pair<int ,int> CurPos)
{
	// 도착했다면
	if (CurPos.first == M - 1 && CurPos.second == N - 1)
	{
		return 1;
	}

	// 도착 길이 있다
	if (DP[CurPos.second][CurPos.first] != -1)
	{
		return DP[CurPos.second][CurPos.first];
	}
	DP[CurPos.second][CurPos.first] = 0;


	for (int i = 0; i < 4; ++i)
	{
		int nX = DirX[i] + CurPos.first;
		int nY = DirY[i] + CurPos.second;

		if (!IsIn(nX, nY))
			continue;

		// 오르막이라면 넘긴다
		if (Matrix[nY][nX] >= Matrix[CurPos.second][CurPos.first])
			continue;

		
		DP[CurPos.second][CurPos.first] += DFS({ nX, nY });

	}

	
	return DP[CurPos.second][CurPos.first];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Reset();

	cin >> N >> M;

	if (N == 1 && M == 1)
	{
		cout << 1;
		return 0;
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> Matrix[y][x];
		}
	}

	DFS({0, 0});

	cout << DP[0][0];

	return 0;
}
