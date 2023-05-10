#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


struct tagPos
{
	int m_iX = 0;
	int	m_iY = 0;
	tagPos() {};
	tagPos(int iX, int iY) : m_iX(iX), m_iY(iY) {};
};

int g_iDirX[4] = { 0, 0, -1, 1 };
int g_iDirY[4] = { 1, -1, 0, 0 };

int g_iN;
int g_iRGBMatrix[100][100] = { 0 };
int g_iRBMatrix[100][100] = { 0 };
int g_bVisited[100][100] = { 0 };


void Reset_Matrix(int(*iMatrix)[100])
{
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			iMatrix[y][x] = 0;
		}
	}
}

bool isIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN&& iY >= 0 && iY < g_iN;
}

void DFS(tagPos Pos, int (*iMatrix)[100], int iToNum)
{
	g_bVisited[Pos.m_iY][Pos.m_iX] = true;

	for (int i = 0; i < 4; ++i)
	{
		int inX = Pos.m_iX + g_iDirX[i];
		int inY = Pos.m_iY + g_iDirY[i];

		if (isIn(inX, inY) && iMatrix[inY][inX] == iToNum && g_bVisited[inY][inX] == false)
		{
			DFS(tagPos(inX, inY), iMatrix, iToNum);
		}
	}
}

int Count_DFS(int (*iMatrix)[100], int iToNum)
{
	int iCount = 0;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			if (isIn(x, y) && iMatrix[y][x] == iToNum && g_bVisited[y][x] == false)
			{
				DFS(tagPos(x, y), iMatrix, iToNum);
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

	// R G B
	// R R B
	cin >> g_iN;
	for (int y = 0; y < g_iN; ++y)
	{
		string sTemp; cin >> sTemp;
		for (int x = 0; x < g_iN; ++x)
		{
			if ('R' == sTemp[x])
			{
				g_iRGBMatrix[y][x] = 1;
				g_iRBMatrix[y][x] = 1;
			}
			else if ('G' == sTemp[x])
			{
				g_iRGBMatrix[y][x] = 2;
				g_iRBMatrix[y][x] = 1;
			}
			else if ('B' == sTemp[x])
			{
				g_iRGBMatrix[y][x] = 3;
				g_iRBMatrix[y][x] = 3;
			}
		}
	}


	int iRGBCount = Count_DFS(g_iRGBMatrix, 1);
	Reset_Matrix(g_bVisited);
	iRGBCount += Count_DFS(g_iRGBMatrix, 2);
	Reset_Matrix(g_bVisited);
	iRGBCount += Count_DFS(g_iRGBMatrix, 3);
	Reset_Matrix(g_bVisited);

	int iRBCount = Count_DFS(g_iRBMatrix, 1);
	Reset_Matrix(g_bVisited);
	iRBCount += Count_DFS(g_iRBMatrix, 3);

	cout << iRGBCount << " " << iRBCount;

	return 0;
}