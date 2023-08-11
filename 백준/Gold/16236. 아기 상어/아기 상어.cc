#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

struct Vec2D
{
	int iX = 0, iY = 0, iCount = 0;

	Vec2D() {};
	Vec2D(int x, int y, int count) : iX(x), iY(y), iCount(count) {};

};

int g_iN;
int g_iMatrix[20][20] = { 0 };
bool g_Visited[20][20] = { false };

int g_iStartPosX, g_iStartPosY, g_iWeight = 2, g_iEatNum = 0;
int g_iDirX[4] = { 0, 0, -1, 1 };
int g_iDirY[4] = { -1, 1, 0, 0 };

void Reset()
{
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			g_Visited[y][x] = false;
		}
	}
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN&& iY >= 0 && iY < g_iN;
}

int BFS()
{
	Reset();

	queue<Vec2D> Qs;
	Qs.push({g_iStartPosX, g_iStartPosY, 1});
	g_Visited[g_iStartPosY][g_iStartPosX] = true;

	while (!Qs.empty())
	{
		int iSize = Qs.size();
		vector<Vec2D> Temps;
		for (int t = 0; t < iSize; ++t)
		{

			Vec2D CurVec = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int inX = CurVec.iX + g_iDirX[i];
				int inY = CurVec.iY + g_iDirY[i];

				if (IsIn(inX, inY) && g_Visited[inY][inX] == false)
				{
					int iPosNum = g_iMatrix[inY][inX];
					g_Visited[inY][inX] = true;

					// 지나갈 수 있다
					if (iPosNum == g_iWeight || iPosNum == 0)
					{
						Qs.push({ inX, inY, CurVec.iCount + 1 });
					}
					// 먹는다
					else if (iPosNum < g_iWeight)
					{
						Temps.push_back({inX, inY, CurVec.iCount});
					}

				}

			}


		}

		// 먹을게 있다면
		if (!Temps.empty())
		{

			Vec2D MaxPos;
			MaxPos.iY = INT_MAX;
			for (int i = 0; i < Temps.size(); ++i)
			{
				Vec2D Pos = Temps[i];
				if (MaxPos.iY > Pos.iY)
				{
					MaxPos = Pos;
				}
			}

			for (int i = 0; i < Temps.size(); ++i)
			{
				Vec2D Pos = Temps[i];
				if (MaxPos.iY == Pos.iY && MaxPos.iX > Pos.iX)
				{
					MaxPos = Pos;
				}
			}


			++g_iEatNum;
			if (g_iWeight <= g_iEatNum)
			{
				g_iEatNum = 0;
				++g_iWeight;
			}

			g_iMatrix[MaxPos.iY][MaxPos.iX] = 0;
			g_iStartPosX = MaxPos.iX;
			g_iStartPosY = MaxPos.iY;

			return MaxPos.iCount;

		}

	}

	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			int iTemp;
			cin >> iTemp;

			if (iTemp == 9)
			{
				g_iStartPosX = x;
				g_iStartPosY = y;
				iTemp = 0;
			}

			g_iMatrix[y][x] = iTemp;
		}
	}

	int iAns = 0;
	while (true)
	{
		int iSec = BFS();
		if (iSec == -1)
			break;

		iAns += iSec;

	}


	cout << iAns;

	return 0;
}