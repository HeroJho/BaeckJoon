#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int g_iT, g_iN, g_iM;
vector<list<int>> g_Matrix(20001);
bool g_Visited[20001] = { false };
bool g_Mark[20001] = { false };

void Reset_Matrix()
{
	for (int i = 0; i < 20001; ++i)
	{
		g_Matrix[i].clear();
	}
}

void Reset_Visited()
{
	for (int i = 0; i < 20001; ++i)
	{
		g_Visited[i] = false;
	}
}

void Reset_Mark()
{
	for (int i = 0; i < 20001; ++i)
	{
		g_Mark[i] = false;
	}
}


void Mark_BFS(int iStart)
{
	queue<int> Qs;
	Qs.push(iStart);
	g_Visited[iStart] = true;
	
	g_Mark[iStart] = true;

	while (!Qs.empty())
	{
		int iCurNum = Qs.front();
		Qs.pop();

		for (auto iNum : g_Matrix[iCurNum])
		{
			if (!g_Visited[iNum])
			{
				g_Mark[iNum] = !g_Mark[iCurNum];

				g_Visited[iNum] = true;
				Qs.push(iNum);
			}
		}
	}

}

bool BFS(int iStart)
{

	queue<int> Qs;
	Qs.push(iStart);
	g_Visited[iStart] = true;


	while (!Qs.empty())
	{
		int iCurNum = Qs.front();
		Qs.pop();

		for (auto iNum : g_Matrix[iCurNum])
		{
			
			if (g_Mark[iCurNum] == g_Mark[iNum])
				return false;

			if (!g_Visited[iNum])
			{
				g_Visited[iNum] = true;
				Qs.push(iNum);
			}

		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	cin >> g_iT;
	for (int i = 0; i < g_iT; ++i)
	{
		Reset_Matrix();

		cin >> g_iN >> g_iM;
		for (int i = 0; i < g_iM; ++i)
		{
			int iTemp1, iTemp2;
			cin >> iTemp1 >> iTemp2;

			g_Matrix[iTemp1].push_back(iTemp2);
			g_Matrix[iTemp2].push_back(iTemp1);
		}


		Reset_Mark();
		Reset_Visited();
		for (int i = 1; i <= g_iN; ++i)
		{
			if (g_Visited[i])
				continue;

			Mark_BFS(i);
		}

		bool bAns = false;
		Reset_Visited();
		for (int i = 1; i <= g_iN; ++i)
		{
			if (g_Visited[i])
				continue;

			if (!BFS(i))
				bAns = true;
		}

		if (!bAns)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}

	return 0;
}