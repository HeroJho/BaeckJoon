#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int g_iN, g_iM;
pair<int, int> g_Start;
pair<int, int> g_End;
int g_iK;
// d l r u
int g_DirX[] = { 0, -1, 1, 0 };
int g_DirY[] = { 1, 0, 0, -1 };

string g_sS;
vector<string> g_sSs;



bool IsIn(int iX, int iY)
{
	return iX >= 1 && iX <= g_iM && iY >= 1 && iY <= g_iN;
}

bool DFS(int iDepth, pair<int, int> CurPos)
{
	pair<int, int> Dis;
	Dis.first = g_End.first - CurPos.first;
	Dis.second = g_End.second - CurPos.second;
	int iCount = abs(Dis.first) + abs(Dis.second);
	if (iCount + iDepth > g_iK)
		return false;

	if (iCount % 2 != (g_iK - iDepth) % 2)
		return false;

	if (iDepth > g_iK)
	{
		return false;
	}
	else if (iDepth == g_iK && CurPos == g_End)
	{
		// 도착
		g_sSs.push_back(g_sS);
		return true;
	}


	for (int i = 0; i < 4; ++i)
	{
		int inX = CurPos.first + g_DirX[i];
		int inY = CurPos.second + g_DirY[i];

		if (!IsIn(inX, inY))
			continue;

		// lrud
		char cDir = 0;
		switch (i)
		{
		case 0:
			cDir = 'd';
			break;
		case 1:
			cDir = 'l';
			break;
		case 2:
			cDir = 'r';
			break;
		case 3:
			cDir = 'u';
			break;
		}

		g_sS.push_back(cDir);
		if (DFS(iDepth + 1, { inX, inY }))
			return true;
		g_sS.pop_back();


	}

	return false;

}


string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "";

	g_iN = n;
	g_iM = m;
	g_Start.first = y;
	g_Start.second = x;
	g_End.first = c;
	g_End.second = r;
	g_iK = k;

	DFS(0, g_Start);

	//sort(g_sSs.begin(), g_sSs.end());

	if (!g_sSs.empty())
		answer = g_sSs[0];
	else
		answer = "impossible";

	return answer;
}


