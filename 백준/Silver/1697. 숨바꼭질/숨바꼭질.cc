#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int g_N, g_K;
bool g_Visited[100001] = { false };

int BFS()
{
	queue<int> Qs;
	Qs.push(g_N);
	//g_Visited[g_N] = true;

	int Count = 0;
	while (!Qs.empty())
	{
		int Size = Qs.size();

		int bStop = false;
		for (int t = 0; t < Size; ++t)
		{
			int Cur = Qs.front();
			Qs.pop();

			if (Cur > 100000 || Cur < 0)
				continue;

			if (Cur == g_K)
			{
				bStop = true;
				break;
			}


			if (g_Visited[Cur])
				continue;
			g_Visited[Cur] = true;

			Qs.push(Cur * 2);
			Qs.push(Cur + 1);
			Qs.push(Cur - 1);

		}

		if (bStop)
			break;

		++Count;
		
	}

	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N >> g_K;

	cout << BFS();

	return 0;
}
