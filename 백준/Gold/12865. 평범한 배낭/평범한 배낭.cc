#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int DP[101][100001] = {0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> Inputs;
	for (int i = 0; i < N; ++i)
	{
		pair<int, int> Temp;
		cin >> Temp.first >> Temp.second;
		Inputs.push_back(Temp);
	}

	for (int e = Inputs[0].first; e <= K; ++e)
	{
		DP[0][e] = Inputs[0].second;
	}


	for (int i = 1; i < N; ++i)
	{
		for (int e = 0; e <= K; ++e)
		{
			if (e - Inputs[i].first < 0)
				DP[i][e] = DP[i - 1][e];
			else
				DP[i][e] = max(DP[i - 1][e], DP[i - 1][e - Inputs[i].first] + Inputs[i].second);
		}
	}

	cout << DP[N - 1][K];



	return 0;
}
