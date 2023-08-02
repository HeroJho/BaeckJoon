#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int g_iN, g_iM, g_iK;
int g_Matrix[101][101] = { 0 };
bool g_Visited[101][101] = { false };

int g_DirX[4] = { 0, 0, -1, 1 };
int g_DirY[4] = { 1, -1, 0, 0 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN && iY >= 0 && iY < g_iM;
}

int BFS(int iStartX, int iStartY)
{
	queue<pair<int ,int>> Qs;

	Qs.push({ iStartX, iStartY });
	g_Visited[iStartY][iStartX] = true;

	int iCount = 1;
	while (!Qs.empty())
	{
		pair<int, int> CurPos = Qs.front();
		Qs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int inX = g_DirX[i] + CurPos.first;
			int inY = g_DirY[i] + CurPos.second;

			if (IsIn(inX, inY) && !g_Matrix[inY][inX] && !g_Visited[inY][inX])
			{
				++iCount;
				g_Visited[inY][inX] = true;
				Qs.push({ inX, inY });
			}

		}

	}

	return iCount;
}

void Iter_BFS()
{
	vector<int> iAnss;
	for (int y = 0; y < g_iM; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			if (!g_Matrix[y][x] && !g_Visited[y][x])
			{
				iAnss.push_back(BFS(x, y));
			}
		}
	}

	sort(iAnss.begin(), iAnss.end());

	cout << iAnss.size() << endl;
	for (auto iAns : iAnss)
		cout << iAns << ' ';

}

int main()
{
	cin >> g_iM >> g_iN >> g_iK;
	for (int i = 0; i < g_iK; ++i)
	{
		int iMinX, iMinY, iMaxX, iMaxY;
		cin >> iMinX >> iMinY >> iMaxX >> iMaxY;

		for (int y = iMinY; y < iMaxY; ++y)
		{
			for (int x = iMinX; x < iMaxX; ++x)
			{
				g_Matrix[y][x] = 1;
			}
		}

	}

	Iter_BFS();

	return 0;
}