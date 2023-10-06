#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int g_iN, g_iM;
int g_Matrix[50][50] = { 0 };
bool g_Visited[50][50] = { false };

int g_DP[50][50] = { 0 };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };

int g_iAns = 0;

void Reset_Visited()
{
	for (int y = 0; y < g_iN; ++y)
		for (int x = 0; x < g_iM; ++x)
			g_Visited[y][x] = false;

}
void Reset_DP()
{
	for (int y = 0; y < g_iN; ++y)
		for (int x = 0; x < g_iM; ++x)
			g_DP[y][x] = 0;

}


bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

void BFS(pair<int ,int> iStart)
{
	queue<pair<int, int>> Qs;
	Qs.push(iStart);
	g_Visited[iStart.second][iStart.first] = true;
	g_DP[iStart.second][iStart.first] = 0;

	int iDis = 0;
	while (!Qs.empty())
	{
		int iSize = Qs.size();
		++iDis;

		for (int s = 0; s < iSize; ++s)
		{
			pair<int, int> Cur = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int inX = Cur.first + g_DirX[i];
				int inY = Cur.second + g_DirY[i];

				if (!IsIn(inX, inY))
					continue;

				if (g_Matrix[inY][inX] && !g_Visited[inY][inX])
				{
					g_DP[inY][inX] = iDis;

					g_Visited[inY][inX] = true;
					Qs.push({ inX, inY });
				}

			}
		}

	}

}

pair<int, int> Find_MaxDisPos()
{
	int iMax = 0;
	pair<int, int> Pos;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (iMax < g_DP[y][x])
			{
				Pos = { x, y };
				iMax = g_DP[y][x];
			}
				
		}
	}

	return Pos;
}

void Iter_BFS()
{

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (g_Matrix[y][x])
			{
				Reset_Visited();
				Reset_DP();

				BFS({ x, y });
				pair<int, int> Pos = Find_MaxDisPos();

				if (g_iAns < g_DP[Pos.second][Pos.first])
					g_iAns = g_DP[Pos.second][Pos.first];

			}

		}
	}

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
			if (cTemp == 'W')
				g_Matrix[y][x] = 0;
			else
				g_Matrix[y][x] = 1;
		}
	}

	Iter_BFS();

	cout << g_iAns;

	return 0;
}