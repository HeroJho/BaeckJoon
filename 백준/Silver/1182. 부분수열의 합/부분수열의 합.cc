#include <iostream>
#include <vector>

using namespace std;

int g_iN, g_iM;
int g_iAns;
vector<int> g_Inputs;
int g_Visited[21] = { 0 };
vector<int> g_AnsTemps;

void DFS(int iV)
{
	if (!g_AnsTemps.empty())
	{
		int iSum = 0;
		for (int i = 0; i < g_AnsTemps.size(); ++i)
		{
			iSum += g_AnsTemps[i];
		}

		if (iSum == g_iM)
			++g_iAns;
	}


	for (int i = 0; i < g_Inputs.size(); ++i)
	{
		if (g_Visited[i])
			continue;

		if (iV >= i)
			continue;

		g_Visited[i] = true;
		g_AnsTemps.push_back(g_Inputs[i]);

		DFS(i);

		g_Visited[i] = false;
		g_AnsTemps.pop_back();
	}

}

int main()
{
	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}


	DFS(-1);

	cout << g_iAns;

	return 0;
}