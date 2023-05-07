
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct tagPos
{
	int m_iX, m_iY;
	tagPos() : m_iX(0), m_iY(0) {};
	tagPos(int iX, int iY) { m_iX = iX; m_iY = iY; }
};

int g_iY, g_iX;

int g_iMatrix[10000][500] = {0};
bool g_bVisited[10000][500] = { false };
			// 오위 오 오아
int g_iDirX[3] = {1, 1, 1};
int g_iDirY[3] = {-1, 0, 1};

bool isIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iX&& iY >= 0 && iY < g_iY;
}

bool DFS(tagPos Pos)
{
	g_bVisited[Pos.m_iY][Pos.m_iX] = true;
	if (Pos.m_iX == g_iX - 1)
		return true;

	for (int j = 0; j < 3; ++j)
	{
		int inX = Pos.m_iX + 1;
		int inY = Pos.m_iY + g_iDirY[j];

		if (isIn(inX, inY) && g_iMatrix[inY][inX] == 0 && g_bVisited[inY][inX] == false)
		{
			if (DFS(tagPos(inX, inY)))
				return true;
		}
	}

	return false;
}


int main()
{
	cin >> g_iY >> g_iX;

	for (int i = 0; i < g_iY; ++i)
	{
		string sTemp = "";
		cin >> sTemp;

		for (int j = 0; j < g_iX; ++j)
		{
			if (sTemp[j] == '.')
				g_iMatrix[i][j] = 0;
			else
				g_iMatrix[i][j] = 1;
		}
	}



	int iCount = 0;

	for (int i = 0; i < g_iY; ++i)
	{
		bool isA = DFS(tagPos(0, i));
		if (isA)
			++iCount;
	}

	cout << iCount;

	return 0;
}
