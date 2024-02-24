#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

struct Data
{
	pair<int, int> Pos;
	int WallCnt = 0;

	Data() {};
	Data(pair<int, int> pos, int wall) : Pos(pos), WallCnt(wall) {};

};

int N, M, K;
int Matrix[1001][1001] = { 0 };
int DP[1001][1001] = { INT_MAX };
int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };


void Reset()
{
	for (int y = 0; y < 1001; ++y)
	{
		for (int x = 0; x < 1001; ++x)
		{
			DP[y][x] = INT_MAX;
		}
	}
}

bool IsIn(int X, int Y)
{
	return X >= 0 && X < M && Y >= 0 && Y < N;
}


int BFS()
{
	queue<Data> Qs;
	Qs.push({ {0,0}, 0 });
	DP[0][0] = 0;

	int Count = 0;
	while (!Qs.empty())
	{
		int Size = Qs.size();
		++Count;
		for (int s = 0; s < Size; ++s)
		{

			Data Cur = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nX = DirX[i] + Cur.Pos.first;
				int nY = DirY[i] + Cur.Pos.second;
				int nWall = Cur.WallCnt;

				if (!IsIn(nX, nY))
					continue;

				// 벽이냐
				if (Matrix[nY][nX] == 1)
				{
					++nWall;
				}

				// 부술수 있는 벽을 넘겼다
				if (nWall > K)
					continue;

				// 가지치기
				// 같은 자리에 이미 누가 찍었다
				// 내 벽이보다 같거나 더 적다 = 그럼 넘긴다
				if (nWall >= DP[nY][nX])
					continue;
				DP[nY][nX] = nWall;

				// 도착했다
				if (nX == M - 1 && nY == N - 1)
					return Count + 1;


				Qs.push({ { nX, nY }, nWall });

			}

		}

	}

	return -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	Reset();

	cin >> N >> M >> K;

	if (N == 1 && M == 1)
	{
		cout << 1;
		return 0;
	}

	for (int y = 0; y < N; ++y)
	{
		string sTemp;
		cin >> sTemp;
		for (int x = 0; x < M; ++x)
		{
			Matrix[y][x] = sTemp[x] - '0';
		}
	}


	cout << BFS();

	return 0;
}
