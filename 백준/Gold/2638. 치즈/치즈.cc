#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int g_iN, g_iM;
int g_Matrix[100][100] = { 0 };
int g_InMatrix[100][100] = { 0 };
int g_Visited[100][100] = { 0 };

int g_DirX[] = { 0 , 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };

vector<pair<int, int>> g_TempPoss;
bool g_bIsE = false;

int g_iAns = 0;

void Reset_Visited()
{

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_Visited[y][x] = false;
		}
	}

}
void Reset()
{

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_Visited[y][x] = false;
			g_InMatrix[y][x] = 0;
		}
	}

}


bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}


void DFS(int iX, int iY)
{
	g_Visited[iY][iX] = true;
	g_TempPoss.push_back({ iX, iY });

	for (int i = 0; i < 4; ++i)
	{
		int inX = iX + g_DirX[i];
		int inY = iY + g_DirY[i];

		if (!IsIn(inX, inY))
			g_bIsE = true;
		else if (g_Visited[inY][inX] == false && g_Matrix[inY][inX] == 0)
			DFS(inX, inY);
	}
}

void Iter_DFS()
{
	g_bIsE = false;
	g_TempPoss.clear();

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (g_Visited[y][x] == false && g_Matrix[y][x] == 0)
			{
				DFS(x, y);

				if (!g_bIsE)
				{
					for (auto& Pos : g_TempPoss)
						g_InMatrix[Pos.second][Pos.first] = 1;
				}

				g_bIsE = false;
				g_TempPoss.clear();

			}
				
		}
	}

}



bool BFS()
{
	Reset();
	Iter_DFS();
	Reset_Visited();


	vector<pair<int, int>> DisPoss;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (g_Matrix[y][x] != 1)
				continue;

			int iDisCount = 0;
			for (int i = 0; i < 4; ++i)
			{
				int inX = x + g_DirX[i];
				int inY = y + g_DirY[i];

				if (IsIn(inX, inY) && g_Matrix[inY][inX] == 0 && g_InMatrix[inY][inX] == 0)
					++iDisCount;
			}

			if (iDisCount >= 2)
				DisPoss.push_back({x, y});
		}
	}

	if (!DisPoss.empty())
	{
		for (auto& Pos : DisPoss)
		{
			g_Matrix[Pos.second][Pos.first] = 0;
		}

		++g_iAns;
		return true;
	}
	else
		return false;
	
}

int main()
{
	cin >> g_iN >> g_iM;

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	while (true)
	{
		if (!BFS())
			break;
		int iA = 0;
	}

	cout << g_iAns;

	return 0;
}