#include <iostream>
#include <string>
#include <vector>

using namespace std;

int g_DP[2000][2000] = { 0 };


int solution(vector<vector<int>> triangle) {
    int answer = 0;

	for (int i = triangle.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			g_DP[i][j] = triangle[i][j] + max(g_DP[i + 1][j], g_DP[i + 1][j + 1]);
		}
	}

    return g_DP[0][0];
}
