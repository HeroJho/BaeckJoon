#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

vector<vector<int>> g_Dungeons;
bool g_Visited[8] = { false };
int g_Ans = 0;

void DFS(int Depth, int CurP)
{
	if (CurP <= 0)
		return;
	if (Depth > 8)
		return;
	
	if (Depth > g_Ans)
		g_Ans = Depth;

	for (int i = 0; i < g_Dungeons.size(); ++i)
	{
		if (g_Visited[i])
			continue;

		if (g_Dungeons[i][0] > CurP)
			continue;

		g_Visited[i] = true;
		DFS(Depth + 1, CurP - g_Dungeons[i][1]);
		g_Visited[i] = false;

	}

}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	g_Dungeons = dungeons;
	DFS(0, k);

	return g_Ans;
}
