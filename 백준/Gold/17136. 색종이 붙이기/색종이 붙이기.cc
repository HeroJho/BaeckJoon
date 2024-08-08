#include <iostream>
#include "limits.h"

using namespace std;

int g_Matrix[10][10] = { 0 };
int g_Count[6] = { 0 };
int g_Ans = INT_MAX;


void Reset()
{
	for (int i = 1; i <= 5; ++i)
		g_Count[i] = 5;
}

bool IsIn(int X, int Y)
{
	return X >= 0 && X < 10 && Y >= 0 && Y < 10;
}

bool Check(pair<int ,int> Pos, int Dis)
{
	if (!IsIn(Pos.first + Dis - 1, Pos.second + Dis - 1))
		return false;

	for (int i = Pos.first; i < Pos.first + Dis; ++i)
	{
		for (int j = Pos.second; j < Pos.second + Dis; ++j)
		{
			if (g_Matrix[i][j] == 0)
				return false;
		}
	}

	return true;
}

void Fill(pair<int ,int> Pos, int Dis, int FillNum)
{
	for (int i = Pos.first; i < Pos.first + Dis; ++i)
		for (int j = Pos.second; j < Pos.second + Dis; ++j)
			g_Matrix[i][j] = FillNum;
}

bool CheckEnd()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (g_Matrix[i][j] == 1)
				return false;
		}
	}

	return true;
}


void DFS(int Depth)
{
	// 기존거 보다 더 붙여야 한다면
	if (g_Ans <= Depth)
		return;

	if (CheckEnd())
	{
		g_Ans = Depth;
		return;
	}


	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (g_Matrix[i][j] == 0)
				continue;

			// m 번째 종이
			for (int m = 5; m >= 1; --m)
			{
				if (g_Count[m] <= 0)
					continue;

				if (!Check({ i, j }, m))
					continue;

				--g_Count[m];
				Fill({ i, j }, m, 0);

				DFS(Depth + 1);

				++g_Count[m];
				Fill({ i, j }, m, 1);

			}

            // 가장 좌상단의 좌표에서 5종류의 색종이를 채워봤다면 이후의 좌표는 확인할 필요없다
			return;

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Reset();

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> g_Matrix[i][j];


	DFS(0);

	if (g_Ans == INT_MAX)
		cout << -1;
	else
		cout << g_Ans;

	return 0;
}
