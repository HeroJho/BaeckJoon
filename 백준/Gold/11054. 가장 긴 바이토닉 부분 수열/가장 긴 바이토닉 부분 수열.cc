#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}


	int DP[2][1001] = { 0 };
	DP[0][0] = 1;
	DP[1][N-1] = 1;

	// 우
	for (int i = 1; i < N; ++i)
	{
		int MaxNum = 1;
		for (int z = i - 1; z >= 0; --z)
		{
			if (Inputs[i] > Inputs[z])
			{
				if (DP[0][z] + 1 > MaxNum)
				{
					MaxNum = DP[0][z] + 1;
				}
			}

			DP[0][i] = MaxNum;

		}
	}

	// 좌
	for (int i = N - 2; i >= 0; --i)
	{
		int MaxNum = 1;
		for (int z = i + 1; z < N; ++z)
		{
			if (Inputs[i] > Inputs[z])
			{
				if (DP[1][z] + 1 > MaxNum)
				{
					MaxNum = DP[1][z] + 1;
				}
			}

			DP[1][i] = MaxNum;

		}
	}

	int Ans = 0;
	for (int i = 0; i < N; ++i)
	{
		int Cnt = DP[0][i] + DP[1][i];
		if (Ans < Cnt)
			Ans = Cnt;
	}

	cout << Ans - 1;

	return 0;
}
