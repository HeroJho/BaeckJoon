#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN, g_iM;
vector<int> g_Matrix[2000];
bool g_Visited[2000] = { false };
bool g_bTrue = false;

void Reset()
{
	for (int i = 0; i < g_iN; ++i)
	{
		g_Visited[i] = false;
	}
}

void DFS(int iDepth, int iCurNum)
{
	if (4 <= iDepth)
	{
		g_bTrue = true;
		return;
	}

	for (int i = 0; i < g_Matrix[iCurNum].size(); ++i)
	{
		int inNex = g_Matrix[iCurNum][i];
		if (g_Visited[inNex])
			continue;

		g_Visited[inNex] = true;
		DFS(iDepth + 1, inNex);
		g_Visited[inNex] = false;

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd;
		cin >> iStart >> iEnd;
		g_Matrix[iStart].push_back(iEnd);
		g_Matrix[iEnd].push_back(iStart);
	}


	for (int i = 0; i < g_iN; ++i)
	{
		Reset();

		g_Visited[i] = true;
		DFS(0, i);
		if (g_bTrue)
			break;

	}
	

	cout << g_bTrue;

	return 0;
}