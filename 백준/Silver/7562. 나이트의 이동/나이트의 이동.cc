#include <iostream>
#include <vector>
#include <queue>
#include "limits.h"

using namespace std;

int g_DirX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int g_DirY[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int g_DP[301][301] = { INT_MAX };

struct Vec2D
{
	int iX, iY, iCurDis;
	Vec2D() : iX(0), iY(0), iCurDis(0) {};
	Vec2D(int x, int y, int dis) : iX(x), iY(y), iCurDis(dis) {};
};

void Reset()
{
	for (int i = 0; i < 301; ++i)
	{
		for (int j = 0; j < 301; ++j)
		{
			g_DP[i][j] = INT_MAX;
		}
	}
}

bool IsIn(int iX, int iY, int iN)
{
	return iX >= 0 && iX < iN&& iY >= 0 && iY < iN;
}

int BFS(int iN, Vec2D Start, Vec2D End)
{
	Reset();

	queue<Vec2D> Qs;
	Qs.push(Start);
	g_DP[Start.iY][Start.iX] = 0;

	while (!Qs.empty())
	{
		Vec2D CurPos = Qs.front();
		Qs.pop();

		if (g_DP[CurPos.iY][CurPos.iX] < CurPos.iCurDis)
			continue;

		if (End.iX == CurPos.iX && End.iY == CurPos.iY)
			return g_DP[End.iY][End.iX];

		for (int i = 0; i < 8; ++i)
		{
			int inX = CurPos.iX + g_DirX[i];
			int inY = CurPos.iY + g_DirY[i];
			int iCount = CurPos.iCurDis + 1;

			if (IsIn(inX, inY, iN) && g_DP[inY][inX] > iCount)
			{
				g_DP[inY][inX] = iCount;
				Qs.push({ inX, inY, iCount });
			}

		}
	}

	return -1;
}

int main()
{
	int iT;
	cin >> iT;


	for (int i = 0; i < iT; ++i)
	{
		int iN;
		cin >> iN;
		Vec2D Start, End;
		cin >> Start.iX >> Start.iY;
		cin >> End.iX >> End.iY;
		cout << BFS(iN, Start, End) << endl;
	}
		


	return 0;
}