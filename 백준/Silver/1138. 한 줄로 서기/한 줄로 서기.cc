#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int N;
vector<int> Inputs;
int DP[10] = { 0 };

void Reset()
{
	for (int i = 0; i < 10; ++i)
	{
		DP[i] = -1;
	}
}

bool Check()
{
	// i번째에 키가 있다
	// 내 키의 n값 찾고,
	// 내 키
	for (int i = 0; i < N; ++i)
	{
		int Height = DP[i];
		int Ncnt = 0;
		for (int j = i-1; j >= 0; --j)
		{
			// 왼이 더 크다
			if (Height < DP[j])
			{
				Ncnt++;
			}
		}

		if (Inputs[Height] != Ncnt)
			return false;
	}

	return true;
}

bool DFS(int Depth, int Height)
{
	if (Depth >= N)
	{
		if (Check())
			return true;

		return false;
	}

	for (int i = 0; i < N; ++i)
	{
		if (DP[i] != -1)
			continue;

		DP[i] = Height;
		if (DFS(Depth + 1, Height + 1))
			return true;
		DP[i] = -1;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Reset();
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Temp; cin >> Temp;
		Inputs.push_back(Temp);
	}

	DFS(0, 0);

	for (int i = 0; i < N; ++i)
	{
		cout << DP[i] + 1<< ' ';
	}

	return 0;
}
