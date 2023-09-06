#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Data
{
	int iX = 0, iY = 0;
	int iIndex = 0;
};

int g_iN;
int g_Matrix[16][16] = { 0 };

//               하  대 좌
int g_DirX[3] = { 0, 1, 1 };
int g_DirY[3] = { 1, 1, 0 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN && iY >= 0 && iY < g_iN;
}

void BFS()
{
	queue<Data> Qs;
	Data Temp;
	Temp.iX = 1;
	Temp.iY = 0;
	Temp.iIndex = 2;
	Qs.push(Temp);

	int iCount = 0;
	while (!Qs.empty())
	{
		Data CurNode = Qs.front();
		Qs.pop();

		if (CurNode.iX == g_iN - 1 && CurNode.iY == g_iN - 1)
		{
			++iCount;
			continue;
		}

		for (int i = 0; i < 3; ++i)
		{
			if (CurNode.iIndex == 0)
			{
				if (i == 2)
					continue;
			}
			else if (CurNode.iIndex == 2)
			{
				if (i == 0)
					continue;
			}

			int inX = CurNode.iX + g_DirX[i];
			int inY = CurNode.iY + g_DirY[i];
			
			if (!IsIn(inX, inY))
				continue;

			if (i == 1)
			{
				if (!g_Matrix[inY][inX] && !g_Matrix[inY][inX - 1] && !g_Matrix[inY - 1][inX])
				{
					Data Temp;
					Temp.iX = inX;
					Temp.iY = inY;
					Temp.iIndex = i;
					Qs.push(Temp);

				}

			}
			else
			{
				if (!g_Matrix[inY][inX])
				{
					Data Temp;
					Temp.iX = inX;
					Temp.iY = inY;
					Temp.iIndex = i;
					Qs.push(Temp);

				}

			}

		}
	}

	cout << iCount;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	BFS();

	return 0;
}