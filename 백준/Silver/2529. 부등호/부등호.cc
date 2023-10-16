#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN;
vector<char> g_Inputs;
string g_Sums;
bool g_Visited[10] = { false };

long long g_iMin = LLONG_MAX;
long long g_iMax = 0;
string g_sMin, g_sMax;


void DFS(int iDepth)
{
	if (iDepth > g_iN)
	{
		long long iSum = stoll(g_Sums);

		if (g_iMin > iSum)
		{
			g_iMin = iSum;
			g_sMin = g_Sums;
		}
			

		if (g_iMax < iSum)
		{
			g_iMax = iSum;
			g_sMax = g_Sums;
		}
			

		return;
	}


	for (int i = 0; i <= 9; ++i)
	{
		if (g_Visited[i])
			continue;

		if (iDepth > 0)
		{
			int iPreNum = g_Sums[iDepth - 1] - '0';
			switch (g_Inputs[iDepth - 1])
			{
			case '<':
				if (iPreNum >= i)
				{
					continue;
				}
				break;
			case '>':
				if (iPreNum <= i)
				{
					continue;
				}
				break;
			}
		}
			

		g_Visited[i] = true;
		g_Sums.push_back(i + '0');
		
		DFS(iDepth + 1);

		g_Visited[i] = false;
		g_Sums.pop_back();
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;

	for (int i = 0; i < g_iN; ++i)
	{
		char cTemp;
		cin >> cTemp;
		g_Inputs.push_back(cTemp);
	}

	DFS(0);

	cout << g_sMax << '\n';
	cout << g_sMin;

	return 0;
}