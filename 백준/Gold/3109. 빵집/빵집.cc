#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN, g_iM;
int g_Matirx[10001][501] = { 0 };
bool g_Visited[10001][501] = { false };
int g_DirX[] = { 1, 1, 1 };
int g_DirY[] = { -1, 0, 1 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

bool DFS(int iX, int iY)
{
	if (g_iM - 1 == iX)
	{
		return true;
	}


	for (int i = 0; i < 3; ++i)
	{
		int inX = iX + g_DirX[i];
		int inY = iY + g_DirY[i];

		if (IsIn(inX, inY) && !g_Visited[inY][inX] && g_Matirx[inY][inX] != 1)
		{
			g_Visited[inY][inX] = true;
			if (DFS(inX, inY))
				return true;
		}

	}

	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			char cTemp; cin >> cTemp;
			if (cTemp == 'x')
			{
				g_Matirx[y][x] = 1;
			}


		}
	}


	int iAns = 0;
	for (int y = 0; y < g_iN; ++y)
	{
		g_Visited[y][0] = true;
		if (DFS(0, y))
		{
			++iAns;
		}

	}

	cout << iAns;

	return 0;
}