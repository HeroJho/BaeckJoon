#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Data
{
	int iX = 0;
	int iY = 0;
	int iH = 0;
};

int g_iDirX[6] = { 0, 0, 1, -1, 0, 0 };
int g_iDirY[6] = { 1, -1, 0, 0, 0, 0 };
int g_iDirH[6] = { 0, 0, 0, 0, 1, -1 };

int g_iN, g_iM, g_iH;
int g_iMatrix[100][100][100] = { 0 };
bool g_bVisited[100][100][100] = { false };

list<Data> g_iQs;

bool Check(int iX, int iY, int iH)
{
	return iX >= 0 && iX < g_iN && iY >= 0 && iY < g_iM && iH >= 0 && iH < g_iH;
}

int BFS()
{
	int iCount = 0;

	while (!g_iQs.empty())
	{
		int iSize = g_iQs.size();

		for (int s = 0; s < iSize; ++s)
		{
			Data CurPos = g_iQs.front();
			g_iQs.pop_front();

			for (int i = 0; i < 6; ++i)
			{
				int inX = CurPos.iX + g_iDirX[i];
				int inY = CurPos.iY + g_iDirY[i];
				int inH = CurPos.iH + g_iDirH[i];
				if (Check(inX, inY, inH) && !g_bVisited[inH][inX][inY] && g_iMatrix[inH][inX][inY] == 0)
				{
					g_bVisited[inH][inX][inY] = true;

					Data NextPos;
					NextPos.iX = inX;
					NextPos.iY = inY;
					NextPos.iH = inH;
					g_iQs.push_back(NextPos);
				}
			}
		}

		++iCount;
	}

	return iCount - 1;
}

bool CheckBFS()
{
	for (int h = 0; h < g_iH; ++h)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			for (int y = 0; y < g_iM; ++y)
			{
				if (g_iMatrix[h][x][y] != -1 && !g_bVisited[h][x][y])
				{
					return false;
				}
			}
		}
	}

	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iM >> g_iN >> g_iH;

	for (int h = 0; h < g_iH; ++h)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			for (int y = 0; y < g_iM; ++y)
			{
				cin >> g_iMatrix[h][x][y];
				if (g_iMatrix[h][x][y] == 1)
				{
					g_bVisited[h][x][y] = true;

					Data Pos;
					Pos.iX = x;
					Pos.iY = y;
					Pos.iH = h;
					g_iQs.push_back(Pos);
				}
			}
		}
	}



	int iAns = BFS();
	bool bAll = CheckBFS();

	if (bAll)
		cout << iAns;
	else
		cout << -1;

	return 0;
}