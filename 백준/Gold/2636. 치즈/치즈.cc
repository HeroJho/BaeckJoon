#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN, g_iM;
int g_Matrix[100][100] = { 0 };
bool g_Visited[100][100] = { false };
int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { -1, 1, 0, 0 };

vector<pair<int, int>> g_DPos;

void Reset()
{
	g_DPos.clear();
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_Visited[y][x] = false;
		}
	}
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM&& iY >= 0 && iY < g_iN;
}

void BFS(pair<int ,int> StartPos)
{

	queue <pair<int, int>> Qs;
	Qs.push(StartPos);

	while (!Qs.empty())
	{
		pair<int, int> Pos = Qs.front();
		Qs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int inX = g_DirX[i] + Pos.first;
			int inY = g_DirY[i] + Pos.second;

			if (!IsIn(inX, inY) || g_Visited[inY][inX])
				continue;

			if (g_Matrix[inY][inX] == 0)
			{
				g_Visited[inY][inX] = true;
				Qs.push({inX, inY});
			}
			else if (g_Matrix[inY][inX] == 1)
			{
				g_DPos.push_back({inX, inY});
			}


		}

	}

}

void Iter_BFS()
{
	int iAns = 0;
	int iPreCount = 0;
	while (true)
	{
		int iCount = 0;
		for (int y = 0; y < g_iN; ++y)
		{
			for (int x = 0; x < g_iM; ++x)
			{
				if (g_Matrix[y][x] == 1)
				{
					++iCount;
				}
			}
		}

		if (iCount == 0)
		{
			cout << iAns << '\n';
			cout << iPreCount;
			break;
		}

		iPreCount = iCount;

		Reset();
		for (int x = 0; x < g_iM; ++x)
		{
			if (!g_Visited[0][x])
				BFS({ x, 0 });
			if (!g_Visited[g_iN - 1][x])
				BFS({ x, g_iN - 1 });
		}

		for (int y = 0; y < g_iN; ++y)
		{
			if (!g_Visited[y][0])
				BFS({ 0, y });
			if (!g_Visited[y][g_iM - 1])
				BFS({ g_iM - 1, y });
		}


		for (int i = 0; i < g_DPos.size(); ++i)
		{
			g_Matrix[g_DPos[i].second][g_DPos[i].first] = 0;
		}


		++iAns;
	}

	

	

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_iN >> g_iM;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}


	Iter_BFS();

	
	return 0;
}