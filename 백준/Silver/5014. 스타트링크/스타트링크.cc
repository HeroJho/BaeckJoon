#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

int g_F, g_S, g_G, g_U, g_D;
int g_DP[1000001];

void Reset()
{
	for (int i = 0; i < 1000001; ++i)
	{
		g_DP[i] = INT_MAX;
	}
}

void BFS()
{
	queue<pair<int, int>> Qs;
	Qs.push({ g_S, 0 });
	g_DP[g_S] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		if (Cur.first == g_G)
			continue;


		int Up = Cur.first + g_U;
		if (Up >= 1 && Up <= g_F && g_DP[Up] > Cur.second + 1)
		{
			g_DP[Up] = Cur.second + 1;
			Qs.push({ Up, Cur.second + 1 });
		}
			
		int Down = Cur.first - g_D;
		if (Down >= 1 && Down <= g_F && g_DP[Down] > Cur.second + 1)
		{
			g_DP[Down] = Cur.second + 1;
			Qs.push({ Down, Cur.second + 1 });
		}
	
	}

	if (g_DP[g_G] == INT_MAX)
		cout << "use the stairs";
	else
		cout << g_DP[g_G];

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_F >> g_S >> g_G >> g_U >> g_D;

	Reset();
	BFS();

	return 0;
}