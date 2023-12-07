#include <string>
#include <vector>

using namespace std;

vector<string> g_Board;
int g_TempBoard[3][3] = { 0 };
int g_MaxCount = 0;
bool g_Visited[3][3] = { false };

bool Check_Same()
{
	for (int i = 0; i < g_Board.size(); ++i)
	{
		for (int j = 0; j < g_Board[i].size(); ++j)
		{
			if (g_Board[i][j] == '.')
			{
				if (g_TempBoard[i][j] != 0)
					return false;
			}
			else if (g_Board[i][j] == 'O')
			{
				if (g_TempBoard[i][j] != 1)
					return false;
			}
			else if (g_Board[i][j] == 'X')
			{
				if (g_TempBoard[i][j] != -1)
					return false;
			}

		}
	}

	return true;
}

bool Check_EndGame()
{
	// 가로 체크
	for (int i = 0; i < 3; ++i)
	{
		int iCount = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (g_TempBoard[i][j] == 1)
			{
				++iCount;
			}
			else if (g_TempBoard[i][j] == -1)
			{
				--iCount;
			}

		}

		if (iCount == -3 || iCount == 3)
		{
			return true;
		}

	}
	// 세로 체크
	for (int j = 0; j < 3; ++j)
	{
		int iCount = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (g_TempBoard[i][j] == 1)
			{
				++iCount;
			}
			else if (g_TempBoard[i][j] == -1)
			{
				--iCount;
			}

		}

		if (iCount == -3 || iCount == 3)
		{
			return true;
		}

	}
	// 대각선 체크
	int iCount = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (g_TempBoard[i][i] == 1)
		{
			++iCount;
		}
		else if (g_TempBoard[i][i] == -1)
		{
			--iCount;
		}

	}
	if (iCount == -3 || iCount == 3)
	{
		return true;
	}

	iCount = 0;
	for (int i = 2; i >= 0; --i)
	{
		if (g_TempBoard[i][2-i] == 1)
		{
			++iCount;
		}
		else if (g_TempBoard[i][2-i] == -1)
		{
			--iCount;
		}

	}
	if (iCount == -3 || iCount == 3)
	{
		return true;
	}

	return false;

}

bool DFS(int iDepth, bool IsO)
{
	if (g_MaxCount == iDepth)
	{
		if (Check_Same())
		{
			return true;
		}
		
		return false;
	}

	if (Check_EndGame())
	{
		return false;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (g_TempBoard[i][j] != 0)
				continue;

			if (IsO)
				g_TempBoard[i][j] = 1;
			else
				g_TempBoard[i][j] = -1;


			if (DFS(iDepth + 1, !IsO))
				return true;

			g_TempBoard[i][j] = 0;

		}
	}

	return false;
}


int solution(vector<string> board) {
	int answer = -1;

	g_Board = board;
	g_MaxCount = 0;

	for (int i = 0; i < g_Board.size(); ++i)
	{
		for (int j = 0; j < g_Board[i].size(); ++j)
		{
			if (g_Board[i][j] != '.')
			{
				++g_MaxCount;
			}
		}
	}


	if (DFS(0, true))
		answer = 1;
	else
		answer = 0;

	return answer;
}