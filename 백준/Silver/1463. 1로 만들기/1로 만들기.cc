#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int g_N;
set<int> g_DP;

void BFS()
{
	queue<int> Qs;
	Qs.push(g_N);
	g_DP.insert(g_N);
	
	int Count = 0;
	while (!Qs.empty())
	{
		int Size = Qs.size();

		for (int t = 0; t < Size; ++t)
		{
			int Cur = Qs.front();
			Qs.pop();

			if (Cur == 1)
			{
				cout << Count;
				return;
			}

			if (Cur % 3 == 0)
			{
				int Temp = Cur / 3;
				if (g_DP.find(Temp) == g_DP.end())
				{
					g_DP.insert(Temp);
					Qs.push(Temp);
				}

			}
			if (Cur % 2 == 0)
			{
				int Temp = Cur / 2;
				if (g_DP.find(Temp) == g_DP.end())
				{
					g_DP.insert(Temp);
					Qs.push(Temp);
				}

			}
			if (Cur - 1 >= 1)
			{
				int Temp = Cur - 1;
				if (g_DP.find(Temp) == g_DP.end())
				{
					g_DP.insert(Temp);
					Qs.push(Temp);
				}

			}

		}

		++Count;
				
	}


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N;
	BFS();

	return 0;
}
