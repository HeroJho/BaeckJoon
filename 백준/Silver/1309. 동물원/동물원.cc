#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

long long DP[3][100000] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 1에 놓았을 때, 2에 놓았을 때, 둘 다 안 놓았을 때

	// DP[3][N]

	// DP[0][1] = 0의 0, 1, 2 전부 가능 + 1
	// DP[1][1] = 0의 0, 2 가능 + 1
	// DP[2][1] = 0의 0, 1 가능 + 1
	
	int N;
	cin >> N;

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[2][0] = 1;

	for (int i = 1; i < N; ++i)
	{
		DP[0][i] = (DP[0][i - 1] + DP[1][i - 1] + DP[2][i - 1]) % 9901;
		DP[1][i] = (DP[0][i - 1] + DP[2][i - 1]) % 9901;
		DP[2][i] = (DP[0][i - 1] + DP[1][i - 1]) % 9901;
	}

	cout << (DP[0][N - 1] + DP[1][N - 1] + DP[2][N - 1]) % 9901;

	return 0;
}
