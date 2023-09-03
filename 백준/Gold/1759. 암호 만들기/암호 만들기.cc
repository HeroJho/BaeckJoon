#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN, g_iM;
vector<char> g_Inputs;
vector<char> g_Temps;
vector<char> g_C = { 'a', 'e', 'i', 'o', 'u' };

bool IsC(char cC)
{
	for (int i = 0; i < 5; ++i)
	{
		if (g_C[i] == cC)
			return true;
	}

	return false;
}

void DFS(int iDepth, int iStep)
{
	if (iDepth >= g_iN)
	{
		int iC = 0, iG = 0;
		for (int i = 0; i < g_Temps.size(); ++i)
		{
			if (IsC(g_Temps[i]))
				++iC;
			else
				++iG;
		}

		if (1 <= iC && 2 <= iG)
		{
			for (int i = 0; i < g_Temps.size(); ++i)
			{
				cout << g_Temps[i];
			}
			cout << '\n';
		}

		return;
	}

	for (int i = iStep; i < g_iM; ++i)
	{
		g_Temps.push_back(g_Inputs[i]);
		DFS(iDepth + 1, i + 1);
		g_Temps.pop_back();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		char cTemp;
		cin >> cTemp;
		g_Inputs.push_back(cTemp);
	}

	sort(g_Inputs.begin(), g_Inputs.end());

	DFS(0, 0);

	return 0;
}