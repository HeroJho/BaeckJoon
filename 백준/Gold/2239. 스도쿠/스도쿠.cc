#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int Matrix[9][9] = { 0 };
vector<pair<int ,int>> Zeros;
int ZeroCnt = 0;

bool Check(pair<int, int> Pos, int Num)
{
	int StartX = (Pos.first / 3) * 3;
	int StartY = (Pos.second / 3) * 3;
	// 네모 확인
	for (int y = StartY; y < StartY + 3; ++y)
	{
		for (int x = StartX; x < StartX + 3; ++x)
		{
			if (Matrix[y][x] == Num)
			{
				return false;
			}
		}
	}

	// 가로 확인
	for (int j = 0; j < 9; ++j)
	{
		if (Matrix[Pos.second][j] == Num)
		{
			return false;
		}
	}

	// 세로 확인
	for (int j = 0; j < 9; ++j)
	{
		if (Matrix[j][Pos.first] == Num)
		{
			return false;
		}
	}

	return true;
}

bool DFS(int Depth)
{
	// 다 채웠다, 끝내기
	if (ZeroCnt == Depth)
	{
		return true;
	}

	for (int i = 1; i < 10; ++i)
	{
		pair<int, int>& CurPos = Zeros[Depth];
		// 조건 되냐
		if (Check(CurPos, i))
		{
			Matrix[CurPos.second][CurPos.first] = i;
			if (DFS(Depth + 1))
				return true;
			Matrix[CurPos.second][CurPos.first] = 0;
		}

	}

	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; ++i)
	{
		string Temp;
		cin >> Temp;

		for (int j = 0; j < 9; ++j)
		{
			Matrix[i][j] = Temp[j] - '0';
			if (Matrix[i][j] == 0)
			{
				Zeros.push_back({j, i});
			}
		}
	}

	ZeroCnt = Zeros.size();
	DFS(0);

	for (int i = 0; i < 9; ++i)
	{
		for (int z = 0; z < 9; ++z)
		{
			cout << Matrix[i][z];
		}
		cout << endl;
	}

	return 0;
}
