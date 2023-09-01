#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN;
vector<int> g_Inputs;
int g_Cul[4] = { 0 };
long long g_iMaxAns = LLONG_MIN;
long long g_iMinAns = LLONG_MAX;

void DFS(int iDepth, long long iNum)
{
	if (iDepth == g_iN)
	{
		if (g_iMaxAns < iNum)
		{
			g_iMaxAns = iNum;
		}
		if (g_iMinAns > iNum)
		{
			g_iMinAns = iNum;
		}

		return;
	}

	for (int i = 0; i < g_Cul[0]; ++i)
	{
		--g_Cul[0];
		DFS(iDepth + 1, iNum + g_Inputs[iDepth]);
		++g_Cul[0];
	}
	for (int i = 0; i < g_Cul[1]; ++i)
	{
		--g_Cul[1];
		DFS(iDepth + 1, iNum - g_Inputs[iDepth]);
		++g_Cul[1];
	}
	for (int i = 0; i < g_Cul[2]; ++i)
	{
		--g_Cul[2];
		DFS(iDepth + 1, iNum * g_Inputs[iDepth]);
		++g_Cul[2];
	}
	for (int i = 0; i < g_Cul[3]; ++i)
	{
		--g_Cul[3];
		DFS(iDepth + 1, iNum / g_Inputs[iDepth]);
		++g_Cul[3];
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
	for (int i = 0; i < 4; ++i)
	{
		cin >> g_Cul[i];
	}

	DFS(1, g_Inputs[0]);

	cout << g_iMaxAns << '\n';
	cout << g_iMinAns;

	return 0;
}