#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define MAX 65

using namespace std;

int g_N;
int g_Matrix[MAX][MAX] = { 0 };

int Check(pair<int, int> LT, int Size)
{
	int CheckNum = g_Matrix[LT.second][LT.first];
	for (int y = LT.second; y < LT.second + Size; ++y)
	{
		for (int x = LT.first; x < LT.first + Size; ++x)
		{
			if (CheckNum != g_Matrix[y][x])
				return -1;
		}
	}

	return CheckNum;
}

void DFS(pair<int, int> LT, int Size)
{
	if (Size == 0)
		return;

	int Num = Check(LT, Size);
	if (Num != -1)
	{
		cout << Num;
		return;
	}

	cout << "(";

	// 쪼갠다
	int HSize = Size / 2;

	DFS(LT, HSize);
	DFS({ LT.first + HSize, LT.second }, HSize);
	DFS({ LT.first, LT.second + HSize }, HSize);
	DFS({ LT.first + HSize, LT.second + HSize }, HSize);

	cout << ")";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N;
	for (int i = 0; i < g_N; ++i)
	{
		string Temp;
		cin >> Temp;
		for (int j = 0; j < g_N; ++j)
		{
			g_Matrix[i][j] = Temp[j] - '0';
		}
	}
	
	DFS({0, 0}, g_N);


	return 0;
}
