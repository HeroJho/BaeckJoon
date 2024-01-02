#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"
#include <map>

using namespace std;

int g_M[3][3] = { 0 };
map<string, string> g_Check;
int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { 1, -1, 0, 0 };
int g_Ans = 0;

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < 3 && iY >= 0 && iY < 3;
}

void MtoS(string& sS)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			sS.push_back(g_M[i][j] + '0');
		}
	}
}
pair<int ,int> StoM(const string& sS)
{
	pair<int, int> ZPos;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			g_M[i][j] = sS[3*i + j] - '0';
			if (g_M[i][j] == 0)
				ZPos = { i, j };
		}
	}

	return ZPos;
}

bool Same(const string& sS)
{
	if (g_Check.find(sS) == g_Check.end())
	{
		g_Check.emplace(sS, sS);
		return false;
	}

	return true;
}


int BFS()
{
	string sS;
	MtoS(sS);
	queue<string> Qs;
	Qs.push(sS);
	g_Check.emplace(sS, sS);

	int iCount = 1;
	while (!Qs.empty())
	{
		int iSize = Qs.size();

		for (int t = 0; t < iSize; ++t)
		{

			string sCur = Qs.front();
			Qs.pop();

			pair<int, int> ZPos = StoM(sCur);

			for (int i = 0; i < 4; ++i)
			{
				int inX = ZPos.first + g_DirX[i];
				int inY = ZPos.second + g_DirY[i];

				if (!IsIn(inX, inY))
					continue;

				g_M[ZPos.first][ZPos.second] = g_M[inX][inY];
				g_M[inX][inY] = 0;

				string sTemp;
				MtoS(sTemp);

				if (Same(sTemp))
				{
					g_M[inX][inY] = g_M[ZPos.first][ZPos.second];
					g_M[ZPos.first][ZPos.second] = 0;
					continue;
				}
				if (sTemp == "123456780")
					return iCount;


				Qs.push(sTemp);

				g_M[inX][inY] = g_M[ZPos.first][ZPos.second];
				g_M[ZPos.first][ZPos.second] = 0;

			}

		}

		++iCount;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> g_M[i][j];
		}
	}

	string sS;
	MtoS(sS);
	if (sS == "123456780")
	{
		cout << 0;
		return 0;
	}

	g_Ans = BFS();
	cout << g_Ans;

	return 0;
}