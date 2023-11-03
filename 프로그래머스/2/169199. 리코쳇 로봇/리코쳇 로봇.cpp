#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

bool g_Visited[200][200] = { false };
int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { -1, 1, 0, 0 };

int g_iN, g_iM;

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM&& iY >= 0 && iY < g_iN;
}

pair<int, int> Go(vector<string>& board, pair<int, int> Pos, int iDir)
{

	while (true)
	{
		int inX = Pos.first + g_DirX[iDir];
		int inY = Pos.second + g_DirY[iDir];

		if (!IsIn(inX, inY) || board[inY][inX] == 'D')
		{
			return Pos;
		}
		else
		{
			Pos.first = inX;
			Pos.second = inY;
		}

	}


}

int BFS(vector<string>& board)
{
	pair<int, int> Start;
	g_iN = board.size();
	g_iM = board[0].length();
	for (int y = 0; y < board.size(); ++y)
	{
		for (int x = 0; x < board[y].length(); ++x)
		{
			if (board[y][x] == 'R')
			{
				Start.first = x;
				Start.second = y;
				break;
			}
		}
	}

	int iCount = 1;

	queue<pair<int, int>> Qs;
	Qs.push(Start);
	g_Visited[Start.second][Start.first] = true;
	while (!Qs.empty())
	{
		int iSize = Qs.size();
		for (int s = 0; s < iSize; ++s)
		{

			pair<int, int> Cur = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int inX = Cur.first + g_DirX[i];
				int inY = Cur.second + g_DirY[i];

				if (!IsIn(inX, inY) || board[inY][inX] == 'D')
					continue;

				pair<int, int> Dest = Go(board, Cur, i);


				if (g_Visited[Dest.second][Dest.first])
					continue;

				if (board[Dest.second][Dest.first] == 'G')
				{
					return iCount;
				}

				g_Visited[Dest.second][Dest.first] = true;
				Qs.push(Dest);

			}

		}

		++iCount;

	}

	return -1;
}


int solution(vector<string> board) {
	int answer = 0;

	answer = BFS(board);

	return answer;
}
