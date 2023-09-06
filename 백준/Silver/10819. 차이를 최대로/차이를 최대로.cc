#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN;
vector<int> g_Inputs;
bool g_Visited[8] = { false };
vector<int> g_Temps;
int g_iAns = 0;

void DFS(int iDepth)
{
	if (iDepth == g_iN)
	{
		int iAns = 0;
		for (int i = 1; i < g_iN; ++i)
		{
			iAns += abs(g_Temps[i-1] - g_Temps[i]);
		}
		
		if (g_iAns < iAns)
			g_iAns = iAns;

		return;
	}

	for (int i = 0; i < g_iN; ++i)
	{
		if (g_Visited[i])
			continue;
		
		g_Visited[i] = true;
		g_Temps.push_back(g_Inputs[i]);
		DFS(iDepth + 1);
		g_Visited[i] = false;
		g_Temps.pop_back();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;

	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}

	DFS(0);

	cout << g_iAns;

	return 0;
}