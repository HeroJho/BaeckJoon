#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Vec2D
{
	int iX, iY;
	Vec2D(int x, int y) :iX(x), iY(y) {}
};

int g_iN, g_iM;
int g_iMatrix[1000][1000] = { 0 };
int g_iAnsMatrix[1000][1000] = { 0 };
bool g_bVisited[1000][1000] = { false };

int g_iDirX[4] = { 0 ,0, -1, 1 };
int g_iDirY[4] = { 1 ,-1, 0, 0 };


bool Check_Range(int iX, int iY)
{
	return iX >= 0 && iX < g_iN&& iY >= 0 && iY < g_iM;
}

void BFS(Vec2D StartPos)
{
	queue<Vec2D> iQs;
	
	iQs.push(StartPos);
	g_iAnsMatrix[StartPos.iY][StartPos.iX] = 0;
	g_bVisited[StartPos.iY][StartPos.iX] = true;

	int iCount = 1;
	while (!iQs.empty())
	{
		int iSize = iQs.size();
	
		for (int i = 0; i < iSize; ++i)
		{
			Vec2D CurPos = iQs.front();
			iQs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int inX = CurPos.iX + g_iDirX[i];
				int inY = CurPos.iY + g_iDirY[i];

				if (Check_Range(inX, inY) && !g_bVisited[inY][inX] && g_iMatrix[inY][inX])
				{
					g_iAnsMatrix[inY][inX] = iCount;
					g_bVisited[inY][inX] = true;
					iQs.emplace(inX, inY);
				}

			}
		}
		
		++iCount;
	}

}

void Check_NoEnd()
{
	for (int y = 0; y < g_iM; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			if (!g_bVisited[y][x] && g_iMatrix[y][x] == 1)
			{
				g_iAnsMatrix[y][x] = -1;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iM >> g_iN;
	Vec2D StartPos(0, 0);
	for (int y = 0; y < g_iM; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cin >> g_iMatrix[y][x];

			if (2 == g_iMatrix[y][x])
			{
				StartPos.iX = x;
				StartPos.iY = y;
			}
		}
	}

	BFS(StartPos);
	Check_NoEnd();

	for (int y = 0; y < g_iM; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cout << g_iAnsMatrix[y][x] << ' ';
		}
		
		cout << '\n';
	}

	return 0;
}