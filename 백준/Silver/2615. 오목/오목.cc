#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define MAX 19

using namespace std;

int g_Matrix[MAX][MAX] = { 0 };
//				하 / 우 / 우대각 / 좌대각
int g_DirX[4] = { 0, 1, 1, 1 };
int g_DirY[4] = { 1, 0, 1, -1 };
bool g_Visited[MAX][MAX] = { false };
int g_Count;

void Reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			g_Visited[i][j] = false;
		}
	}

}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < MAX&& iY >= 0 && iY < MAX;
}

int DFS(int iDir, int iCheck, int iCount, int iX, int iY)
{
	int inX = iX + g_DirX[iDir];
	int inY = iY + g_DirY[iDir];

	if (g_Visited[inY][inX])
		return iCount;

	if (!IsIn(inX, inY))
		return iCount;

	if (g_Matrix[inY][inX] != iCheck)
		return iCount;

	g_Visited[inY][inX] = true;
	
	return DFS(iDir, iCheck, iCount + 1, inX, inY);

}

bool Iter_Check(int iDir, int iCheck, pair<int, int>& OUT_Pos)
{
	Reset();

	int iCount = 0;
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (g_Visited[i][j])
				continue;
			if (g_Matrix[i][j] != iCheck)
				continue;


			iCount = DFS(iDir, iCheck, 1, j, i);
			if (iCount == 5)
			{
				OUT_Pos.first = i + 1;
				OUT_Pos.second = j + 1;
				return true;
			}

		}

	}

	return false;
}
bool Iter_Check1(int iCheck, pair<int, int>& OUT_Pos)
{
	Reset();

	int iCount = 0;
	for (int i = 18; i >= 0; --i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (g_Visited[i][j])
				continue;
			if (g_Matrix[i][j] != iCheck)
				continue;

			iCount = DFS(3, iCheck, 1, j, i);
			if (iCount == 5)
			{
				OUT_Pos.first = i + 1;
				OUT_Pos.second = j + 1;
				return true;
			}

		}

	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			cin >> g_Matrix[i][j];
		}
	}

	pair<int, int> StartPos;
	if (Iter_Check(0, 1, StartPos))
	{
		cout << 1 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}
	if (Iter_Check(1, 1, StartPos))
	{
		cout << 1 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}
	if (Iter_Check(2, 1, StartPos))
	{
		cout << 1 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}
	if (Iter_Check1(1, StartPos))
	{
		cout << 1 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}


	if (Iter_Check(0, 2, StartPos))
	{
		cout << 2 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}
	if (Iter_Check(1, 2, StartPos))
	{
		cout << 2 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}
	if (Iter_Check(2, 2, StartPos))
	{
		cout << 2 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}
	if (Iter_Check1(2, StartPos))
	{
		cout << 2 << '\n';
		cout << StartPos.first << " " << StartPos.second;
		return 0;
	}

	cout << 0;

	return 0;
}