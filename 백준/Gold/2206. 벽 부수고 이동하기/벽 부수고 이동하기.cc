#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "limits.h"

using namespace std;

struct Vec2D
{
	int iX = 0, iY = 0;
	int iDis = 0;
	Vec2D() {};
	Vec2D(int x, int y, int dis) : iX(x), iY(y), iDis(dis) {};
};

int g_iN, g_iM;
int g_Matrix[1001][1001] = { 0 };
int g_MaxDis[1001][1001] = { INT_MAX };
int g_GoMaxDis[1001][1001] = { INT_MAX };

int g_DirX[4] = { 0, 0, -1, 1 };
int g_DirY[4] = { 1, -1, 0, 0 };

void Input()
{
	for (int y = 0; y < 1001; ++y)
	{
		for (int x = 0; x < 1001; ++x)
		{
			g_MaxDis[y][x] = INT_MAX;
			g_GoMaxDis[y][x] = INT_MAX;
		}
	}

	cin >> g_iN >> g_iM;
	for (int y = 0; y < g_iN; ++y)
	{
		string sTemp;
		cin >> sTemp;
		for (int x = 0; x < g_iM; ++x)
		{
			g_Matrix[y][x] = sTemp[x] - '0';
		}
	}

}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

void BFS()
{
	queue<Vec2D> Qs;
	Qs.push({g_iM - 1, g_iN - 1, 0});
	g_MaxDis[g_iN - 1][g_iM - 1] = 0;

	while (!Qs.empty())
	{
		Vec2D CurNode = Qs.front();
		Qs.pop();

		if (CurNode.iX == 0 && CurNode.iY == 0)
			break;

		if (g_MaxDis[CurNode.iY][CurNode.iX] < CurNode.iDis)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int inX = g_DirX[i] + CurNode.iX;
			int inY = g_DirY[i] + CurNode.iY;
			int inDis = CurNode.iDis + 1;

			if (g_MaxDis[inY][inX] <= inDis || !IsIn(inX, inY))
				continue;

			if (g_Matrix[inY][inX] == 0) // 길
			{
				g_MaxDis[inY][inX] = inDis;

				Qs.push({inX, inY, inDis});
			}
			else  // 벽
			{
				g_MaxDis[inY][inX] = inDis;
			}

		}

	}

}

void GoBFS()
{
	queue<Vec2D> Qs;
	Qs.push({ 0, 0, 0 });
	g_MaxDis[0][0] = 0;

	int iAns = INT_MAX;
	while (!Qs.empty())
	{
		Vec2D CurNode = Qs.front();
		Qs.pop();

		if (CurNode.iX == g_iM - 1 && CurNode.iY == g_iN - 1)
			break;

		if (g_GoMaxDis[CurNode.iY][CurNode.iX] < CurNode.iDis)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int inX = g_DirX[i] + CurNode.iX;
			int inY = g_DirY[i] + CurNode.iY;
			int inDis = CurNode.iDis + 1;

			if (g_GoMaxDis[inY][inX] <= inDis || !IsIn(inX, inY))
				continue;

			if (g_Matrix[inY][inX] == 0) // 길
			{
				g_GoMaxDis[inY][inX] = inDis;

				Qs.push({ inX, inY, inDis });
			}
			else  // 벽
			{
				// 마킹이 되어있다면
				if (g_MaxDis[inY][inX] != INT_MAX)
				{
					int iSum = g_MaxDis[inY][inX] + inDis - 1;
					if (iSum < iAns)
						iAns = iSum;
				}
			}

		}

	}

	if (iAns > g_GoMaxDis[g_iN - 1][g_iM - 1])
	{
		iAns = g_GoMaxDis[g_iN - 1][g_iM - 1];
		cout << iAns + 1;
	}
	else if (iAns != INT_MAX)
		cout << iAns + 2;
	else // 벽 부셔갈 수 없다.
		cout << -1;

}

int main()
{
	Input();

	if (g_iN == 1 && g_iM == 1)
	{
		cout << 1;
		return 0;
	}


	BFS();
	GoBFS();

	return 0;
}