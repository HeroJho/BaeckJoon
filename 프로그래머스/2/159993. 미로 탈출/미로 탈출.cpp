#include <string>
#include <vector>
#include <queue>
using namespace std;

int g_iN, g_iM;
vector<string> g_Maps;
int g_Visited[200][200] = { false };
int g_DirX[] = { 0, 0, -1, 1 };
int g_DIrY[] = { -1, 1, 0, 0 };
pair<int, int> g_CurPos;

void Reset()
{
	for (int y = 0; y < g_iN; ++y)
		for (int x = 0; x < g_iM; ++x)
			g_Visited[y][x] = false;
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

int BFS(char cDest)
{
	queue<pair<int, int>> Qs;
	Qs.push(g_CurPos);
	g_Visited[g_CurPos.second][g_CurPos.first] = true;

	int iCount = 1;
	while (!Qs.empty())
	{
		int iSize = Qs.size();
		for (int s = 0; s < iSize; ++s)
		{

			pair<int, int> CurPos = Qs.front();
			Qs.pop();

			for (int i = 0; i < 4; ++i)
			{
				int inX = g_DirX[i] + CurPos.first;
				int inY = g_DIrY[i] + CurPos.second;

				if (IsIn(inX, inY) && g_Maps[inY][inX] != 'X' && !g_Visited[inY][inX])
				{
					if (g_Maps[inY][inX] == cDest)
					{
						g_CurPos.first = inX;
						g_CurPos.second = inY;
						return iCount;
					}

					g_Visited[inY][inX] = true;
					Qs.push({ inX, inY });
				}

			}

		}

		++iCount;

	}

	return -1;
}


int solution(vector<string> maps) {
	int answer = 0;

	g_Maps = maps;
	g_iN = g_Maps.size(); 
    g_iM = g_Maps[0].length();
	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			if (g_Maps[y][x] == 'S')
			{
				g_CurPos.first = x;
				g_CurPos.second = y;
				break;
			}
		}
	}

    

	int iTemp = BFS('L');
	if (iTemp == -1)
		return -1;
	answer += iTemp;

    Reset();
    
	iTemp = BFS('E');
	if (iTemp == -1)
		return -1;
	answer += iTemp;


    
	return answer;
}
