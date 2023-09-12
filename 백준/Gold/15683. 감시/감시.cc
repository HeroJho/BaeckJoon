#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
int g_Matrix[8][8] = { 0 };
int g_CheckMatrix[8][8] = { 0 };
bool g_Visited[8][8] = { false };
int g_RotInfo[8][8] = { 0 };
vector<pair<int, int>> g_Cams;

int g_DirX[] = { 0, 1, 0, -1 };
int g_DirY[] = { 1, 0, -1, 0 };

int g_iAns = INT_MAX;

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

void UpdateEye(pair<int, int> Pos, int iDir)
{
	while (true)
	{
		int inX = Pos.first + g_DirX[iDir];
		int inY = Pos.second + g_DirY[iDir];
		if (!IsIn(inX, inY))
			break;
		if (g_Matrix[inY][inX] == 6)
			break;

		g_CheckMatrix[inY][inX] = 7;

		Pos.first = inX;
		Pos.second = inY;
	}
}
void Update(pair<int ,int> Pos)
{
	int iRot = g_RotInfo[Pos.second][Pos.first];
	int iDir = g_Matrix[Pos.second][Pos.first];

	switch (iDir)
	{
	case 1:
	{
		int iNextDir = (1 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
	}
		break;
	case 2:
	{
		int iNextDir = (1 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (3 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
	}
		break;
	case 3:
	{
		int iNextDir = (1 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (0 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
	}
		break;
	case 4:
	{
		int iNextDir = (1 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (3 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (0 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
	}
		break;
	case 5:
	{
		int iNextDir = (0 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (1 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (2 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
		iNextDir = (3 + iRot) % 4;
		UpdateEye(Pos, iNextDir);
	}
		break;
	}

}

void Iter()
{
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			g_CheckMatrix[y][x] = 0;
		}
	}


	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (g_Matrix[y][x] != 0 && g_Matrix[y][x] != 6)
			{
				Update({x, y});
			}
		}
	}
}

void DFS(int iDepth)
{
	if (iDepth >= g_Cams.size())
	{
		Iter();

		int iAns = 0;
		for (int y = 0; y < g_iN; ++y)
		{
			for (int x = 0; x < g_iM; ++x)
			{
				if (g_CheckMatrix[y][x] == 0 && g_Matrix[y][x] < 1)
				{
					++iAns;
				}
			}
		}

		if (iAns < g_iAns)
			g_iAns = iAns;

		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		g_RotInfo[g_Cams[iDepth].second][g_Cams[iDepth].first] = i;
		DFS(iDepth + 1);
		g_RotInfo[g_Cams[iDepth].second][g_Cams[iDepth].first] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int y = 0; y < g_iN; ++y)
	{
		for(int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
			if (0 < g_Matrix[y][x] && 6 > g_Matrix[y][x])
			{
				g_Cams.push_back({x, y});
			}
		}
	}

	DFS(0);

	cout << g_iAns;

	return 0;
}