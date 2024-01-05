#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

#define MAX 101

using namespace std;

vector<int> g_Inputs;
bool g_Visited[MAX] = { false };
bool g_Save[MAX] = { false };

void Reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		g_Visited[i] = false;
	}
}

int BFS(int iStart)
{
	queue<int> Qs;
	Qs.push(iStart);
	g_Visited[iStart] = true;

	int iCount = 0;
	while (!Qs.empty())
	{
		++iCount;
		int Cur = Qs.front();
		Qs.pop();

		int Nex = g_Inputs[Cur];
		if (iStart == Nex)
		{
			for (int i = 1; i < MAX; ++i) 
			{
				if(g_Visited[i])
					g_Save[i] = g_Visited[i];
			}

			return iCount;
		}
		
		if (g_Visited[Nex])
		{
			break;
		}

		g_Visited[Nex] = true;
		Qs.push(Nex);
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	g_Inputs.push_back(0);
	for (int i = 0; i < N; ++i)
	{
		int iTemp; cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}


	int iCount = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (g_Save[i])
			continue;

		Reset();
		iCount += BFS(i);
	}

	cout << iCount << '\n';
	for (int i = 1; i <= N; ++i)
	{
		if(g_Save[i])
			cout << i << '\n';
	}


	return 0;
}