#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

long long DP[101][10] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 9;
		return 0;
	}

	// N번째 줄이 0~9일 때 경우의 수는 1;
	for (int i = 0; i < 10; ++i)
	{
		DP[N][i] = 1;
	}


	for (int i = N-1; i >= 1; --i)
	{
		for (int j = 0; j < 10; ++j)
		{
			// i가 1일 때 j가 0일 경우는 제거

			int PreIndex = j - 1;
			int NexIndex = j + 1;
			if (PreIndex < 0)
			{
				DP[i][j] = DP[i + 1][NexIndex];
			}
			else if(NexIndex > 9)
			{
				DP[i][j] = DP[i + 1][PreIndex];
			}
			else
			{
				DP[i][j] = DP[i + 1][PreIndex] + DP[i + 1][NexIndex];
			}

			DP[i][j] %= 1000000000;
		}
	}

	// 나누고 더하나, 더하고 나누나 같다

	long long Ans = 0;
	for (int i = 1; i < 10; ++i)
		Ans = (Ans + DP[1][i]) % 1000000000;

	cout << Ans;

	return 0;
}
