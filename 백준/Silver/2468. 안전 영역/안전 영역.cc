#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int g_N = 0;
int g_Matrix[100][100] = { 0 };
bool g_Visited[100][100] = { false };

int g_DirX[4] = { 0, 0, -1, 1 };
int g_DirY[4] = { -1, 1, 0, 0 };
int g_iAns = 0;

void Reset()
{
	for (int y = 0; y < 100; ++y)
	{
		for (int x = 0; x < 100; ++x)
		{
			g_Visited[y][x] = false;
		}
	}
}

bool isIn(int iX, int iY)
{
	return iX >= 0 && iX < g_N && iY >= 0 && iY < g_N;
}

void BFS(int iStartX, int iStartY )
{

	queue<pair<int, int>> Qs;
	Qs.push({ iStartX, iStartY });
	g_Visited[iStartY][iStartX] = true;

	while (!Qs.empty())
	{
		pair<int, int> CurPos = Qs.front();
		Qs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int inX = CurPos.first + g_DirX[i];
			int inY = CurPos.second + g_DirY[i];

			if (isIn(inX, inY) && !g_Visited[inY][inX])
			{
				g_Visited[inY][inX] = true;
				Qs.push({inX, inY});
			}

		}

	}

}

void Iter_BFS()
{
	int iCount = 0;
	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_N; ++x)
		{
			if (!g_Visited[y][x])
			{
				BFS(x, y);
				++iCount;
			}
		}
	}

	if (g_iAns < iCount)
		g_iAns = iCount;
}

void MakeGrid(int Height)
{
	Reset();

	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_N; ++x)
		{
			if (Height >= g_Matrix[y][x])
				g_Visited[y][x] = true;
		}
	}
}

int main()
{
	cin >> g_N;

	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_N; ++x)
		{
			int iTemp;
			cin >> iTemp;
			g_Matrix[y][x] = iTemp;
		}
	}


	for (int i = 0; i <= 100; ++i)
	{
		MakeGrid(i);
		Iter_BFS();
	 }

	cout << g_iAns;

	return 0;
}