#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN, g_iM;
bool g_Check[9] = { false };
vector<int> g_Inputs;
vector<int> g_Anss;

void DFS(int iDepth, int iNum)
{
	if (iDepth == g_iM)
	{
		for (int i = 0; i < g_Anss.size(); ++i)
		{
			cout << g_Anss[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < g_iN; ++i)
	{
		//if (g_Check[i])
		//	continue;

		//if (iNum > g_Inputs[i])
		//	continue;

		g_Check[i] = true;
		g_Anss.push_back(g_Inputs[i]);

		DFS(iDepth + 1, g_Inputs[i]);
		
		g_Check[i] = false;
		g_Anss.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp; cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}

	sort(g_Inputs.begin(), g_Inputs.end());

	DFS(0, 0);


	return 0;
}