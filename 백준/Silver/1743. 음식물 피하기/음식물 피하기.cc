#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int N, M, K;
int Matrix[101][101] = { 0 };
bool Visited[101][101] = { false };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { 1, -1, 0, 0 };

bool IsIn(int InX, int InY)
{
	return InX >= 0 && InX <= M && InY >= 0 && InY <= N;
}

int BFS(pair<int ,int> Start)
{
	queue < pair<int, int>> Qs;
	Qs.push(Start);
	Visited[Start.second][Start.first] = true;

	int Cnt = 0;
	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		Cnt++;

		for (int i = 0; i < 4; ++i)
		{
			int nX = DirX[i] + Cur.first;
			int nY = DirY[i] + Cur.second;

			if (!IsIn(nX, nY))
				continue;

			if (Matrix[nY][nX] == 0)
				continue;

			if (Visited[nY][nX])
				continue;
			Visited[nY][nX] = true;

			Qs.push({ nX, nY });

		}

	}

	return Cnt;
}


void Go()
{
	int Cnt = 0;

	for (int y = 0; y <= N; ++y)
	{
		for (int x = 0; x <= M; ++x)
		{
			if (Matrix[y][x] == 0)
				continue;

			if (Visited[y][x])
				continue;

			int TempCnt = BFS({x, y});
			if (Cnt < TempCnt)
				Cnt = TempCnt;
		}
	}

	cout << Cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int X, Y;
		cin >> Y >> X;
		Matrix[Y][X] = 1;
	}

	Go();

	return 0;
}
