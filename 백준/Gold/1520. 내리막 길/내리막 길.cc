#include <iostream>

#define MAX 500

using namespace std;

int g_iN, g_iM;
int g_Matrix[MAX][MAX] = { 0 };
int g_DP[MAX][MAX] = { 0 };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };

void Reset()
{
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_DP[y][x] = -1;
		}
	}
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM&& iY >= 0 && iY < g_iN;
}

int DFS(int iX, int iY)
{
	if (iX == g_iM - 1 && iY == g_iN - 1)
		return 1;
	else if (g_DP[iY][iX] != -1)
		return g_DP[iY][iX];

	g_DP[iY][iX] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int inX = iX + g_DirX[i];
		int inY = iY + g_DirY[i];

		if (IsIn(inX, inY) && g_Matrix[inY][inX] < g_Matrix[iY][iX])
		{
			g_DP[iY][iX] = g_DP[iY][iX] + DFS(inX, inY);
		}

	}

	return g_DP[iY][iX];
}

int main()
{
	cin >> g_iN >> g_iM;

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	Reset();

	DFS(0, 0);
	cout << g_DP[0][0];

	return 0;
}