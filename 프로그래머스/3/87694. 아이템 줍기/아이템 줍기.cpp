#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

#define MAX 110

using namespace std;

int g_Matrix[MAX][MAX] = { 0 };
int g_Temp[MAX][MAX] = { 0 };

int g_Visited[MAX][MAX] = { false };
int g_DirX[] = { 0, 0, -1, 1,    1,  1, -1, -1 };
int g_DirY[] = { 1, -1, 0, 0,    1, -1,  1, -1 };


void Reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			g_Visited[i][j] = false;
		}
	}
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < MAX && iY >= 0 && iY < MAX;
}

void Fill(pair<int ,int> LD, pair<int ,int> RU)
{

	for (int x = LD.first; x <= RU.first; ++x)
	{
		for (int y = LD.second; y <= RU.second; ++y)
		{
			g_Temp[x][y] = 1;
		}
	}

}

void ReBFS(pair<int, int> StartPos)
{
	queue<pair<int, int>> Qs;
	Qs.push(StartPos);
	g_Visited[StartPos.first][StartPos.second] = true;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.front();
		Qs.pop();

		for (int i = 0; i < 8; ++i)
		{
			int inX = g_DirX[i] + Cur.first;
			int inY = g_DirY[i] + Cur.second;

			if (g_Visited[inX][inY])
				continue;
			if (!IsIn(inX, inY))
				continue;

			if (g_Temp[inX][inY] == 1)
			{
				g_Matrix[inX][inY] = 1;
				continue;
			}

			g_Visited[inX][inY] = true;
			Qs.push({inX, inY});

		}

	}

}

void ReIter_BFS()
{
	for (int i = 0; i < MAX; ++i)
	{
		if (g_Visited[i][0] || g_Temp[i][0] == 1)
			continue;
		ReBFS({i, 0});
	}
	for (int i = 0; i < MAX; ++i)
	{
		if (g_Visited[i][MAX-1] || g_Temp[i][MAX-1] == 1)
			continue;
		ReBFS({ i, MAX-1 });
	}

	for (int i = 0; i < MAX; ++i)
	{
		if (g_Visited[0][i] || g_Temp[0][i] == 1)
			continue;
		ReBFS({ 0, i });
	}
	for (int i = 0; i < MAX; ++i)
	{
		if (g_Visited[MAX-1][i] || g_Temp[MAX-1][i] == 1)
			continue;
		ReBFS({ MAX-1, i });
	}


}




int BFS(pair<int, int> StartPos, pair<int, int> EndPos)
{
	Reset();

	queue<pair<int, int>> Qs;
	Qs.push(StartPos);
	g_Visited[StartPos.first][StartPos.second] = true;

	int iCount = 0;
	while (!Qs.empty())
	{
		int iSize = Qs.size();

		for (int t = 0; t < iSize; ++t)
		{

			pair<int, int> Cur = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int inX = g_DirX[i] + Cur.first;
				int inY = g_DirY[i] + Cur.second;

				if (g_Visited[inX][inY])
					continue;
				if (!IsIn(inX, inY))
					continue;
				if (g_Matrix[inX][inY] == 0)
					continue;


				if (EndPos.first == inX && EndPos.second == inY)
					return iCount + 1;

				g_Visited[inX][inY] = true;
				Qs.push({ inX, inY });

			}


		}

		++iCount;

	}

	return -1;
}




int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	int answer = 0;

    
    int Temp;
    for(int i = 0; i < 1000000; ++i)
    {
        Temp += i;
    }
    
	for (int i = 0; i < rectangle.size(); ++i)
	{
		Fill({ rectangle[i][0] * 2, rectangle[i][1] * 2 }, { rectangle[i][2] * 2, rectangle[i][3] * 2 });
	}

	ReIter_BFS();

	answer = BFS({ characterX * 2, characterY * 2 }, { itemX * 2,itemY * 2 }) / 2;


	return answer;
}

