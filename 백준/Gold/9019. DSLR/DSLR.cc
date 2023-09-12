#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int g_iN, g_iM;
bool g_Visited[10000] = { false };

void Reset()
{
	for (int i = 0; i < 10000; ++i)
	{
		g_Visited[i] = false;
	}
}

void BFS()
{
	queue<pair<int, string>> Qs;
	Qs.push({ g_iN, ""});
	g_Visited[g_iN] = true;

	while(!Qs.empty())
	{
		pair<int, string> Cur = Qs.front();
		Qs.pop();

		if (g_iM == Cur.first)
		{
			cout << Cur.second << '\n';
			return;
		}


		int iD = (Cur.first * 2) % 10000;
		if (iD <= 9999 && !g_Visited[iD])
		{
			g_Visited[iD] = true;
			Qs.push({ iD, Cur.second + "D" });
		}
	

		int iS = Cur.first - 1 < 0 ? 9999 : Cur.first - 1;
		if (iS <= 9999 && !g_Visited[iS])
		{
			g_Visited[iS] = true;
			Qs.push({ iS, Cur.second + "S" });
		}


		int iL = (Cur.first % 1000) * 10 + (Cur.first / 1000);
		if (iL <= 9999 && !g_Visited[iL])
		{
			g_Visited[iL] = true;
			Qs.push({ iL, Cur.second + "L" });

		}


		int iR = Cur.first / 10 + (Cur.first % 10) * 1000;
		if (iR <= 9999 && !g_Visited[iR])
		{
			g_Visited[iR] = true;
			Qs.push({ iR, Cur.second + "R" });
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;

	for (int i = 0; i < iT; ++i)
	{
		cin >> g_iN >> g_iM;

		Reset();

		BFS();
	}

	return 0;
}