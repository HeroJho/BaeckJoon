#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN;
vector<int> g_Temps;
bool g_Visited[9] = { false };

void DFS(int iDepth)
{
	if (iDepth >= g_iN)
	{
		for (int i = 0; i < g_Temps.size(); ++i)
		{
			cout << g_Temps[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= g_iN; ++i)
	{
		if (g_Visited[i])
			continue;
		
		g_Temps.push_back(i);
		g_Visited[i] = true;
		DFS(iDepth + 1);
		g_Temps.pop_back();
		g_Visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;

	DFS(0);

	return 0;
}