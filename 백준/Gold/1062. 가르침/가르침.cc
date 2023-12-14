#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN, g_iM;
vector<string> g_Inputs;

vector<char> g_As;
bool g_Checks[26] = {false};
int g_Ans = 0;

int Check()
{
	int iCount = 0;
	for (int k = 0; k < g_Inputs.size(); ++k)
	{
		bool bSkeep = false;
		for (int i = 0; i < g_Inputs[k].length(); ++i)
		{
			if (!g_Checks[g_Inputs[k][i] - 'a'])
			{
				bSkeep = true;
				break;
			}

		}

		if (!bSkeep)
			++iCount;

	}

	return iCount;
}

void DFS(int iDepth, int iStart)
{
	if (iDepth == g_iM)
	{
		int iCount = Check();

		if (iCount > g_Ans)
			g_Ans = iCount;

		return;
	}

	for (int i = iStart + 1; i < 26; ++i)
	{
		if (g_Checks[g_As[i] - 'a'])
			continue;

		g_Checks[g_As[i] - 'a'] = true;
		DFS(iDepth + 1, i);
		g_Checks[g_As[i] - 'a'] = false;

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 26; ++i)
	{
		g_As.push_back('a'+i);
	}

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iN; ++i)
	{
		string s;
		cin >> s;
		g_Inputs.push_back(s);
	}

	if(g_iM < 5)
	{ 
		cout << 0 << endl;
		return 0;
	}



	g_Checks['a' - 'a'] = true;
	g_Checks['n' - 'a'] = true;
	g_Checks['t' - 'a'] = true;
	g_Checks['i' - 'a'] = true;
	g_Checks['c' - 'a'] = true;
	
	g_iM -= 5;

	DFS(0, -1);

	cout << g_Ans;


	return 0;
}

