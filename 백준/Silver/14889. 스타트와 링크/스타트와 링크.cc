#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN;
int g_Matrix[20][20] = { 0 };
bool g_Visited[20] = { false };
vector<int> g_Teams[2];

int g_iAns = INT_MAX;


void Cul()
{
	int iOneSum = 0;
	int iTwoSum = 0;
	for (int i = 0; i < g_Teams[0].size(); ++i)
	{
		for (int j = 0; j < g_Teams[0].size(); ++j)
		{
			if (i == j)
				continue;
			iOneSum += g_Matrix[g_Teams[0][i]][g_Teams[0][j]];
			iTwoSum += g_Matrix[g_Teams[1][i]][g_Teams[1][j]];
		}
	}
	
	int iDis = abs(iOneSum - iTwoSum);
	if (g_iAns > iDis)
		g_iAns = iDis;

	//for (int i = 0; i < g_Teams[0].size(); ++i)
	//{
	//	cout << g_Teams[0][i] << ' ';
	//}
	//cout << endl;
	//for (int i = 0; i < g_Teams[1].size(); ++i)
	//{
	//	cout << g_Teams[1][i] << ' ';
	//}
	//cout << endl;
	//cout << endl;

}

void DFS(int iLNum, int iRNum, int iDepth)
{
	if (iDepth == g_iN)
	{
		Cul();
		return;
	}

	int iStart = 0;
	if (iDepth < g_iN / 2)
		iStart = iLNum;
	else
		iStart = iRNum;

	for (int i = iStart; i < g_iN; ++i)
	{

		if (g_Visited[i])
			continue;

		if (iDepth < g_iN / 2)
		{
			if (iDepth == 0)
			{
				if(i != 0)
					continue;
			}
			

			g_Teams[0].push_back(i);
			g_Visited[i] = true;
			DFS(i, 0, iDepth + 1);
			g_Teams[0].pop_back();
			g_Visited[i] = false;
		}
		else
		{


			g_Teams[1].push_back(i);
			g_Visited[i] = true;
			DFS(0, i, iDepth + 1);
			g_Teams[1].pop_back();
			g_Visited[i] = false;
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	DFS(0, 0, 0);

 	cout << g_iAns;

	return 0;
}