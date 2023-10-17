#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN, g_iM, g_iH;
int g_Matrix[400][11][11] = { 0 };
int g_TempMatrix[400][11][11] = { 0 };
int g_iAns = INT_MAX;

bool IsIn(int iX)
{
	return iX >= 0 && iX < 11;
}

bool Play()
{
	for (int iStartX = 1; iStartX <= g_iN; ++iStartX)
	{
		int iCurX = iStartX;
		int iCurY = 1;

		while (true)
		{
			int inX = iCurX + 1;
			if (IsIn(inX) && (g_Matrix[iCurY][inX][iCurX] || g_TempMatrix[iCurY][inX][iCurX]))
			{
				++iCurX;
			}
			else
			{
				inX = iCurX - 1;
				if (IsIn(inX) && (g_Matrix[iCurY][inX][iCurX] || g_TempMatrix[iCurY][inX][iCurX]))
				{
					--iCurX;
				}
			}

			++iCurY;
			if (iCurY >= g_iH + 1)
			{
				if (iStartX == iCurX)
				{
					break;
				}

				return false;
			}
		}


	}
	

	return true;
}

bool DFS(int iStickCount, int iX, int iY)
{
	if (iStickCount > 3)
	{
		return false;
	}

	if (Play())
	{
		if (g_iAns > iStickCount)
		{
			g_iAns = iStickCount;
			return true;
		}
	}


	for (int y = iY; y <= g_iH; ++y)
	{
		for (int x = 1; x < g_iN; ++x)
		{
			if (y == iY && x <= iX)
				continue;

			int inX = x + 1;
			if (IsIn(inX) && (g_Matrix[y][inX][x] || g_TempMatrix[y][inX][x]))
			{
				continue;
			}
			else
			{
				inX = x - 1;
				if (IsIn(inX) && (g_Matrix[y][inX][x] || g_TempMatrix[y][inX][x]))
				{
					continue;
				}
			}

			g_TempMatrix[y][x][x + 1] = 1;
			g_TempMatrix[y][x + 1][x] = 1;
			if (DFS(iStickCount + 1, x, y))
			{
				g_TempMatrix[y][x][x + 1] = 0;
				g_TempMatrix[y][x + 1][x] = 0;
				return false;
			}
			g_TempMatrix[y][x][x + 1] = 0;
			g_TempMatrix[y][x + 1][x] = 0;

		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM >> g_iH;
	for (int i = 0; i < g_iM; ++i)
	{
		int iTemp, iTemp2;
		cin >> iTemp >> iTemp2;
		g_Matrix[iTemp][iTemp2][iTemp2 + 1] = 1;
		g_Matrix[iTemp][iTemp2 + 1][iTemp2] = 1;
	}

	DFS(0, 0, 0);

	if (g_iAns == INT_MAX)
		cout << -1;
	else
		cout << g_iAns;

	return 0;
}