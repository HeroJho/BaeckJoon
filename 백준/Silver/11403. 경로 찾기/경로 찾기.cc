#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int g_iN = 0;
int g_Matrix[100][100] = { 0 };
bool g_Visited[100] = { false };

int g_Ans[100][100] = { 0 };

void Reset()
{
	for (int i = 0; i < g_iN; ++i)
	{
		g_Visited[i] = false;
	}
}

bool DFS(int iCur, int iDest)
{
	g_Visited[iCur] = true;

	for (int i = 0; i < g_iN; ++i)
	{
		if (!g_Matrix[iCur][i])
		{
			continue;
		}

		if (i == iDest)
		{
			return true;
		}
		else if (!g_Visited[i])
		{
			if (DFS(i, iDest))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			cin >> g_Matrix[i][j];
		}
	}

	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			Reset();
			if (DFS(i, j))
			{
				g_Ans[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			cout << g_Ans[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}