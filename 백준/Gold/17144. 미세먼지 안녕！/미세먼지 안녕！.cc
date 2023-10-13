#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct AirPos
{
	pair<int, int> Up;
	pair<int, int> Down;
};

int g_iN, g_iM, g_iT;
int g_Matrix[50][50] = { 0 };
int g_TempMatrix[50][50] = { 0 };
AirPos g_AirPos;

bool g_Visited[50][50] = { false };
int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

void BFS()
{
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_Visited[y][x] = false;
			g_TempMatrix[y][x] = g_Matrix[y][x];
		}
	}

	queue<pair<int ,int>> Qs;
	Qs.push({0, 0});
	g_Visited[0][0] = true;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();


		for (int z = 0; z < 4; ++z)
		{
			int inX = g_DirX[z] + Cur.first;
			int inY = g_DirY[z] + Cur.second;

			if (!IsIn(inX, inY) || g_Matrix[inY][inX] == -1)
				continue;

			if (g_Matrix[Cur.second][Cur.first])
			{
				int iSpr = g_Matrix[Cur.second][Cur.first] / 5;
				g_TempMatrix[Cur.second][Cur.first] -= iSpr;
				g_TempMatrix[inY][inX] += iSpr;
			}

		}




		for (int i = 0; i < 4; ++i)
		{
			int inX = g_DirX[i] + Cur.first;
			int inY = g_DirY[i] + Cur.second;

			if (IsIn(inX, inY) && !g_Visited[inY][inX] && g_Matrix[inY][inX] != -1)
			{
				g_Visited[inY][inX] = true;
				Qs.push({ inX, inY });
			}

		}

	}

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_Matrix[y][x] = g_TempMatrix[y][x];
		}
	}

}




void AirDir(pair<int, int>& Start, int iDir, int& iPreNum)
{
	while (true)
	{
		if (!IsIn(Start.first + g_DirX[iDir], Start.second + g_DirY[iDir]))
			break;

		if (g_Matrix[Start.second + g_DirY[iDir]][Start.first + g_DirX[iDir]] == -1)
			break;


		int iTemp = g_Matrix[Start.second + g_DirY[iDir]][Start.first + g_DirX[iDir]];
		g_Matrix[Start.second + g_DirY[iDir]][Start.first + g_DirX[iDir]] = iPreNum;
		iPreNum = iTemp;

		Start.first += g_DirX[iDir];
		Start.second += g_DirY[iDir];
	}

}
void AirClean()
{
	// 위
	int iPreNum = 0;
	pair<int, int> Start = g_AirPos.Up;
	AirDir(Start, 3, iPreNum);
	AirDir(Start, 1, iPreNum);
	AirDir(Start, 2, iPreNum);
	AirDir(Start, 0, iPreNum);
	

	// 아래
	iPreNum = 0;
	Start = g_AirPos.Down;
	AirDir(Start, 3, iPreNum);
	AirDir(Start, 0, iPreNum);
	AirDir(Start, 2, iPreNum);
	AirDir(Start, 1, iPreNum);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM >> g_iT;
	bool bChang = false;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
			if (g_Matrix[y][x] == -1)
			{
				if (!bChang)
				{
					g_AirPos.Up.first = x;
					g_AirPos.Up.second = y;
					bChang = true;
				}
				else
				{
					g_AirPos.Down.first = x;
					g_AirPos.Down.second = y;
				}

			}
		}
	}

	// 확산한다
	//   - BFS   =  n * m
	for (int i = 0; i < g_iT; ++i)
	{
		BFS();
		AirClean();

		int s = 0;
	}

	int iAns = 0;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (g_Matrix[y][x] != -1)
			{
				iAns += g_Matrix[y][x];
			}
		}
	}

	cout << iAns;

	return 0;
}