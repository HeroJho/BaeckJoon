#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int N;
int Matrix[101][101] = { 0 };
int MarkMatrix[101][101] = { 0 };
int Visited[101][101] = { 0 };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { 1, -1, 0, 0 };

bool IsIn(int InX, int InY)
{
	return InX >= 0 && InX < N&& InY >= 0 && InY < N;
}

void BFS(pair<int ,int> Start, int Mark)
{
	queue<pair<int ,int>> Qs;
	Qs.push(Start);
	Visited[Start.second][Start.first] = true;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		MarkMatrix[Cur.second][Cur.first] = Mark;

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

			Qs.push({nX, nY});

		}


	}


}

void Mark()
{
	int Mark = 1;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (Visited[y][x])
				continue;

			if (Matrix[y][x] == 0)
				continue;
			
			BFS({x, y}, Mark);

			++Mark;
		}
	}

}


void ResetVisited()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			Visited[y][x] = false;
		}
	}
}


int GoBFS(pair<int ,int> Start)
{
	queue<pair<int, int>> Qs;
	Qs.push(Start);
	//Visited[Start.second][Start.first] = true;

	int FirstMark = MarkMatrix[Start.second][Start.first];

	int Cnt = 0;
	while (!Qs.empty())
	{
		int Size = Qs.size();

		for (int s = 0; s < Size; ++s)
		{
			pair<int, int> Cur = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nX = DirX[i] + Cur.first;
				int nY = DirY[i] + Cur.second;

				if (!IsIn(nX, nY))
					continue;

				if (MarkMatrix[nY][nX] == 0)
				{
					if (Visited[nY][nX])
						continue;
					Visited[nY][nX] = true;

					Qs.push({ nX, nY });
				}
				else if (MarkMatrix[nY][nX] != FirstMark)
				{ // 0이 아니고, 처음 마크랑 다르다 = 다른 대륙
					return Cnt;
				}

			}

		}

		++Cnt;
		
	}

	return INT_MAX;
}

void Go()
{
	int Ans = INT_MAX;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (MarkMatrix[y][x] == 0)
				continue;

			ResetVisited();
			int Cnt = GoBFS({ x, y });

			if (Cnt < Ans)
				Ans = Cnt;

		}

	}

	cout << Ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> Matrix[y][x];
		}
	}

	Mark();
	Go();

	return 0;
}
