#include <iostream>
#include <queue>
#include <string>
#include "limits.h"

using namespace std;

struct Node
{
	int iX = 0, iY = 0;
	int iWallCount = 0;

	Node() {}
	Node(int _iX, int _iY, int _iCount) : iX(_iX), iY(_iY), iWallCount(_iCount) {};

};

class Func
{
public:
	bool operator()(Node L, Node R)
	{
		return L.iWallCount > R.iWallCount;
	}
};

int g_iN, g_iM;
int g_Matrix[100][100] = { 0 };
int g_DP[100][100] = { 0 };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { -1, 1, 0, 0 };

bool IsIn(int _iX, int _iY)
{
	return _iX >= 0 && _iX < g_iN && _iY >= 0 && _iY < g_iM;
}

void Dij()
{
	priority_queue<Node, vector<Node>, Func> Qs;
	Qs.push({0, 0, 0});
	g_DP[0][0] = 0;

	while (!Qs.empty())
	{
		Node iCurNode = Qs.top();
		Qs.pop();


		for (int i = 0; i < 4; ++i)
		{
			int inX = iCurNode.iX + g_DirX[i];
			int inY = iCurNode.iY + g_DirY[i];

			int iWallCount = iCurNode.iWallCount;
			if (IsIn(inX, inY))
			{
				if (g_Matrix[inY][inX])
					++iWallCount;

				if (g_DP[inY][inX] <= iWallCount)
					continue;

				g_DP[inY][inX] = iWallCount;
				Qs.push({inX, inY, iWallCount});
			}

		}
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;

	for (int y = 0; y < g_iM; ++y)
	{
		string sTemp;
		cin >> sTemp;
		for (int x = 0; x < g_iN; ++x)
		{
			if(sTemp[x] == '1')
				g_Matrix[y][x] = 1;
		}
	}

	for (int y = 0; y < g_iM; ++y)
		for (int x = 0; x < g_iN; ++x)
			g_DP[y][x] = INT_MAX;

	Dij();

	cout << g_DP[g_iM - 1][g_iN - 1];

	return 0;
}