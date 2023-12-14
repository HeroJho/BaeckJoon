#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN, g_iM, g_iK;
vector<pair<int, char>> g_Inputs;
int g_Matrix[100][100] = { 0 };
// 상 좌 하 우
int g_DirX[] = { 0, -1, 0, 1 };
int g_DirY[] = { -1, 0, 1, 0 };

int g_DirIndex = 3;
vector<pair<int, int>> g_Tails;

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN && iY >= 0 && iY < g_iN;
}

bool Go()
{
	int inX = g_DirX[g_DirIndex] + g_Tails[0].first;
	int inY = g_DirY[g_DirIndex] + g_Tails[0].second;
	// 벽, 몸통 충돌
	if (!IsIn(inX, inY))
		return false;	
	for (int i = 0; i < g_Tails.size(); ++i)
	{
		if (g_Tails[i].first == inX && g_Tails[i].second == inY)
		{
			return false;
		}

	}

	// 사과 확인
	bool bApple = false;
	if (g_Matrix[inY][inX] == 9)
	{
		bApple = true;
		g_Matrix[inY][inX] = 0;
	}
	// 몸통 갱신

	pair<int, int> PrePos;
	PrePos = g_Tails[0];
	g_Tails[0] = { inX, inY };
	for (int i = 1; i < g_Tails.size(); ++i)
	{
		pair<int, int> Temp = g_Tails[i];
		g_Tails[i] = PrePos;
		PrePos = Temp;
	}

	if (bApple)
		g_Tails.push_back(PrePos);

	// cout << g_Tails[0].first << " " << g_Tails[0].second << endl;

	return true;

}

int Play()
{
	int iTCount = 0;
	g_Tails.push_back({0, 0});

	int iIndex = 0;
	while (true)
	{
		++iTCount;

		if (iIndex >= g_iK)
			iIndex = g_iK - 1;

		pair<int, char> Info = g_Inputs[iIndex];
		int iCount = Info.first;
		char cChange = Info.second;

		if (!Go())
			return iTCount;

		if (iTCount == iCount)
		{
			if (cChange == 'D')
			{
				--g_DirIndex;
				if (g_DirIndex < 0)
					g_DirIndex = 3;
			}
			else if (cChange == 'L')
			{
				++g_DirIndex;
				if (g_DirIndex > 3)
					g_DirIndex = 0;
			}

			++iIndex;
		}

	}


	return iTCount;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		int iX, iY;
		cin >> iY >> iX;
		g_Matrix[iY - 1][iX - 1] = 9;
	}

	cin >> g_iK;
	for (int i = 0; i < g_iK; ++i)
	{
		pair<int, char> Temp;
		cin >> Temp.first >> Temp.second;
		g_Inputs.push_back(Temp);
	}


	cout << Play();

	return 0;
}
