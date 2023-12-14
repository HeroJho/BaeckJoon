#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN;
vector<int> g_Inputs;
vector<int> g_Temps;

void DFS(int iDepth, int iStart)
{
	if (iDepth == 6)
	{
		// Check
		for (int i = 0; i < 6; ++i)
		{
			cout << g_Temps[i] << ' ';
		}
		cout << "\n";

		return;
	}

	for (int i = iStart + 1; i < g_iN; ++i)
	{
		g_Temps.push_back(g_Inputs[i]);
		DFS(iDepth + 1, i);
		g_Temps.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	while (true)
	{
		g_Inputs.clear();
		g_Temps.clear();
		cin >> g_iN;

		if (!g_iN)
			break;

		for (int i = 0; i < g_iN; ++i)
		{
			int iTemp;
			cin >> iTemp;
			g_Inputs.push_back(iTemp);
		}

		sort(g_Inputs.begin(), g_Inputs.end());

		DFS(0, -1);

		cout << '\n';

	}


	return 0;
}
