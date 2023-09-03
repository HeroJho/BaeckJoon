#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN, g_iM;
vector<int> g_Inputs;

int g_iAns;

void DFS(int iDepth, int iStart, int iSum)
{
	if (g_iM < iSum)
		return;

	if (g_iN < iDepth)
		return;

	if (g_iM == iSum)
	{
		++g_iAns;
		return;
	}

	if (g_iN <= iStart)
		return;

	DFS(iDepth + 1, iStart + 1, iSum + g_Inputs[iStart]);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}

	for (int i = 0; i < g_iN; ++i)
	{
		DFS(i, i, 0);
	}
	

	cout << g_iAns;

	return 0;
}