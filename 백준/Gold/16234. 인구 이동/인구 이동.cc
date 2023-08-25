#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int g_iN, g_iL, g_iR;
int g_Matrix[50][50] = { 0 };
bool g_Visited[50][50] = { false };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };
vector<vector<pair<int, int>>> g_Opens;

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN&& iY >= 0 && iY < g_iN;
}

void Reset()
{
	g_Opens.clear();
	g_Opens.shrink_to_fit();

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			g_Visited[y][x] = false;
		}
	}
}

void BFS(pair<int ,int> StartPos)
{
	g_Opens.push_back(vector<pair<int, int>>());
	g_Opens.back().push_back(StartPos);

	queue<pair<int, int>> Qs;
	Qs.push(StartPos);
	g_Visited[StartPos.second][StartPos.first] = true;

	while (!Qs.empty())
	{
		pair<int, int> CurPos = Qs.front();
		Qs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int inX = CurPos.first + g_DirX[i];
			int inY = CurPos.second + g_DirY[i];

			if (!IsIn(inX, inY) || g_Visited[inY][inX])
				continue;

			int iDis = abs(g_Matrix[inY][inX] - g_Matrix[CurPos.second][CurPos.first]);
			if (iDis >= g_iL && iDis <= g_iR)
			{
				g_Visited[inY][inX] = true;
	
				Qs.push({ inX, inY });
				g_Opens.back().push_back({ inX, inY });
			}

		}

	}


}

bool Iter_BFS()
{
	Reset();

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			if (!g_Visited[y][x])
			{
				BFS({x, y});
			}

		}
	}



	bool bIsChange = false;
	vector<int> iTemp(g_Opens.size(), 0);
	for (int i = 0; i < g_Opens.size(); ++i)
	{
		if (1 == g_Opens[i].size())
			continue;

		bIsChange = true;
		for (int j = 0; j < g_Opens[i].size(); ++j)
		{
			iTemp[i] += g_Matrix[g_Opens[i][j].second][g_Opens[i][j].first];
		}

		iTemp[i] = iTemp[i] / g_Opens[i].size();
	}

	for (int i = 0; i < g_Opens.size(); ++i)
	{
		if (1 == g_Opens[i].size())
			continue;

		for (int j = 0; j < g_Opens[i].size(); ++j)
		{
			g_Matrix[g_Opens[i][j].second][g_Opens[i][j].first] = iTemp[i];
		}

	}

	return bIsChange;
}

int main()
{
	cin >> g_iN >> g_iL >> g_iR;

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	int iAns = 0;
	while(Iter_BFS())
	{
		++iAns;
	}

	cout << iAns;




	return 0;
}