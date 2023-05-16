#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

// DFS, 인접 행렬
// DFS를 모두 순회하며 카운트

struct tagPos
{
	int m_iX = 0;
	int	m_iY = 0;

	tagPos() {};
	tagPos(int iX, int iY) : m_iX(iX), m_iY(iY) {}
};

int m_iDirX[4] = { 0, 0, -1, 1 };
int m_iDirY[4] = { -1, 1, 0, 0 };

int g_iX, g_iY;
int g_iN;

int g_iMatrix[50][50] = { 0 };
bool g_bVisited[50][50] = { false };

bool isIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iX&& iY >= 0 && iY < g_iY;
}

void Reset()
{
	for (int y = 0; y < g_iY; ++y)
	{
		for (int x = 0; x < g_iX; ++x)
		{
			g_iMatrix[y][x] = 0;
			g_bVisited[y][x] = false;
		}
	}
}

void DFS(tagPos Pos)
{
	g_bVisited[Pos.m_iY][Pos.m_iX] = true;

	for (int i = 0; i < 4; ++i)
	{
		int inDirX = Pos.m_iX + m_iDirX[i];
		int inDirY = Pos.m_iY + m_iDirY[i];

		if (isIn(inDirX, inDirY) && g_iMatrix[inDirY][inDirX] && !g_bVisited[inDirY][inDirX])
		{
			DFS(tagPos(inDirX, inDirY));
		}
	}
}

int Iter_DFS()
{
	int iCount = 0;

	for (int y = 0; y < g_iY; ++y)
	{
		for (int x = 0; x < g_iX; ++x)
		{
			if (g_iMatrix[y][x] && !g_bVisited[y][x])
			{
				DFS(tagPos(x, y));
				++iCount;
			}

		}
	}

	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT; cin >> iT;
	vector<int> iAnss;

	for (int t = 0; t < iT; ++t)
	{
		Reset();
		cin >> g_iX >> g_iY >> g_iN;

		for (int i = 0; i < g_iN; ++i)
		{
			int iX, iY;
			cin >> iX >> iY;
			g_iMatrix[iY][iX] = 1;
		}

		int iCount = Iter_DFS();
		iAnss.push_back(iCount);
	}


	for (int i = 0; i < iAnss.size(); ++i)
	{
		cout << iAnss[i] << '\n';
	}


	return 0;
}