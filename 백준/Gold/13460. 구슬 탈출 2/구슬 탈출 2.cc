#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
char g_Matrix[10][10] = { 0 };
pair<int, int> g_RedPos, g_BluePos, g_DestPos;


int g_DirX[4] = { 0, 0, -1, 1 };
int g_DirY[4] = { -1, 1, 0, 0 };


bool g_IsInRed = false;
bool g_IsInBlue = false;
int g_iAns = INT_MAX;


int InvDir(int iDir)
{
	switch (iDir)
	{
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}

	return -1;
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

bool MoveRed(int iDirIndex)
{
	bool bIsMove = false;
	while (true)
	{
		int inX = g_DirX[iDirIndex] + g_RedPos.first;
		int inY = g_DirY[iDirIndex] + g_RedPos.second;

		if (!IsIn(inX, inY))
			break;
		if (g_Matrix[inY][inX] == '#' || (!g_IsInBlue && g_Matrix[inY][inX] == 'B'))
			break;

		if (g_DestPos.first == inX && g_DestPos.second == inY)
			g_IsInRed = true;

		g_Matrix[g_RedPos.second][g_RedPos.first] = '.';
		g_Matrix[inY][inX] = 'R';
		g_RedPos.first = inX;
		g_RedPos.second = inY;

		bIsMove = true;
	}

	return bIsMove;
}
bool MoveBlue(int iDirIndex)
{
	bool bIsMove = false;
	while (true)
	{
		int inX = g_DirX[iDirIndex] + g_BluePos.first;
		int inY = g_DirY[iDirIndex] + g_BluePos.second;

		if (!IsIn(inX, inY))
			break;
		if (g_Matrix[inY][inX] == '#' || (!g_IsInRed && g_Matrix[inY][inX] == 'R'))
			break;

		if (g_DestPos.first == inX && g_DestPos.second == inY)
			g_IsInBlue = true;
			

		g_Matrix[g_BluePos.second][g_BluePos.first] = '.';
		g_Matrix[inY][inX] = 'B';
		g_BluePos.first = inX;
		g_BluePos.second = inY;

		bIsMove = true;
	}

	return bIsMove;
}

bool Move(int iDirIndex)
{
	// 진행 방향으로 가까운 구슬먼저 이동한다.
	bool bIsRed = false;
	switch (iDirIndex)
	{
	case 0:
		if (g_RedPos.second < g_BluePos.second)
			bIsRed = true;
		break;
	case 1:
		if (g_RedPos.second > g_BluePos.second)
			bIsRed = true;
		break;
	case 2:
		if (g_RedPos.first < g_BluePos.first)
			bIsRed = true;
		break;
	case 3:
		if (g_RedPos.first > g_BluePos.first)
			bIsRed = true;
		break;
	}
	
	bool bIsMove = false;
	if (bIsRed)
	{
		bIsMove = MoveRed(iDirIndex);
		bIsMove += MoveBlue(iDirIndex);
	}
	else
	{
		bIsMove = MoveBlue(iDirIndex);
		bIsMove += MoveRed(iDirIndex);
	}

	return bIsMove;
}


void DFS(int iDirIndex, int iDepth)
{
	if (10 < iDepth)
		return;

	// Blue가 먼저 빠졌다면 
	//		컨티뉴
	if (g_IsInBlue)
	{
		g_IsInBlue = false;
		g_IsInRed = false;
		return;
	}
	// Red가 먼저 빠졌다면 
	//		최단 기록 컨티뉴 
	else if(g_IsInRed)
	{
		g_IsInBlue = false;
		g_IsInRed = false;

		if (g_iAns > iDepth)
			g_iAns = iDepth;

		return;
	}
		

	for (int i = 0; i < 4; ++i)
	{
		// 돌아가는 방향은 안 간다
		if (i == iDirIndex || InvDir(i) == iDirIndex)
			continue;

		pair<int, int> SaveRedPos = g_RedPos;
		pair<int, int> SaveBluePos = g_BluePos;

		// 말을 움직인다
		if (!Move(i))
			continue;

		DFS(i, iDepth + 1);
		


		g_IsInBlue = false;
		g_IsInRed = false;

		g_Matrix[g_RedPos.second][g_RedPos.first] = '.';
		g_Matrix[SaveRedPos.second][SaveRedPos.first] = 'R';
		g_RedPos = SaveRedPos;

		g_Matrix[g_BluePos.second][g_BluePos.first] = '.';
		g_Matrix[SaveBluePos.second][SaveBluePos.first] = 'B';
		g_BluePos = SaveBluePos;

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
			if (g_Matrix[y][x] == 'B')
			{
				g_BluePos.first = x;
				g_BluePos.second = y;
			}
			else if(g_Matrix[y][x] == 'R')
			{
				g_RedPos.first = x;
				g_RedPos.second = y;
			}
			else if (g_Matrix[y][x] == 'O')
			{
				g_DestPos.first = x;
				g_DestPos.second = y;
			}

		}
	}


	DFS(-1, 0);

	if (g_iAns != INT_MAX)
		cout << g_iAns;
	else
		cout << -1;

	return 0;
}