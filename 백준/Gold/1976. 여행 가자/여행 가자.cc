#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
int g_Matrix[201][201] = { 0 };
bool g_Visited[201] = { false };
vector<int> g_Inputs;

void Reset()
{
	for (int i = 0; i < 201; ++i)
	{
		g_Visited[i] = false;
	}
}

bool BFS(int iStart, int iDest)
{
	Reset();

	queue<int> Qs;
	Qs.push(iStart);
	g_Visited[iStart] = true;

	if (iStart == iDest)
		return true;

	while (!Qs.empty())
	{
		int Cur = Qs.front();
		Qs.pop();

		for (int i = 1; i <= g_iN; ++i)
		{
			if (!g_Visited[i] && g_Matrix[Cur][i])
			{
				if (i == iDest)
					return true;

				g_Visited[i] = true;
				Qs.push(i);
			}
		}

	}

	return false;
}

bool Iter_BFS()
{
	for (int i = 0; i < g_Inputs.size() - 1; ++i)
	{
		if (!BFS(g_Inputs[i], g_Inputs[i + 1]))
			return false;
		
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int y = 1; y <= g_iN; ++y)
	{
		for (int x = 1; x <= g_iN; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}
	for (int i = 0; i < g_iM; ++i)
	{
		int iTemp; cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}

	if (Iter_BFS())
		cout << "YES";
	else
		cout << "NO";

	return 0;
}