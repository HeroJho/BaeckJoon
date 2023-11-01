#include <iostream>
#include <vector>
using namespace std;

int g_DP[100001][4] = { 0 };

int solution(vector<vector<int>> land)
{
    int answer = 0;

	g_DP[0][0] = land[0][0];
	g_DP[0][1] = land[0][1];
	g_DP[0][2] = land[0][2];
	g_DP[0][3] = land[0][3];
	for (int i = 1; i < land.size(); ++i)
	{

		g_DP[i][0] = max(g_DP[i - 1][1], g_DP[i - 1][2]);
		g_DP[i][0] = max(g_DP[i][0], g_DP[i - 1][3]);
		g_DP[i][0] += land[i][0];

		g_DP[i][1] = max(g_DP[i - 1][0], g_DP[i - 1][2]);
		g_DP[i][1] = max(g_DP[i][1], g_DP[i - 1][3]);
		g_DP[i][1] += land[i][1];

		g_DP[i][2] = max(g_DP[i - 1][0], g_DP[i - 1][1]);
		g_DP[i][2] = max(g_DP[i][2], g_DP[i - 1][3]);
		g_DP[i][2] += land[i][2];

		g_DP[i][3] = max(g_DP[i - 1][0], g_DP[i - 1][1]);
		g_DP[i][3] = max(g_DP[i][3], g_DP[i - 1][2]);
		g_DP[i][3] += land[i][3];

	}

	answer = max(g_DP[land.size() - 1][0], g_DP[land.size() - 1][1]);
	answer = max(answer, g_DP[land.size() - 1][2]);
	answer = max(answer, g_DP[land.size() - 1][3]);

    return answer;
}