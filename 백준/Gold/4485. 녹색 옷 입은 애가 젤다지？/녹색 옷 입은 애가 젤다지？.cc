#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define MAX 125

using namespace std;

struct Data
{
	pair<int, int> Pos;
	int Dis = 0;

	Data(pair<int, int> pos, int dis) : Pos(pos), Dis(dis) {};

};

class Func
{
public:
	bool operator()(Data L, Data R)
	{
		return L.Dis > R.Dis;
	}
};

int g_N;
int g_Matrix[MAX][MAX] = {0};
int g_DP[MAX][MAX] = { INT_MAX };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { -1, 1, 0, 0 };

void Reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			g_DP[i][j] = INT_MAX;
		}
	}
}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_N&& iY >= 0 && iY < g_N;
}

void Dij()
{
	priority_queue<Data, vector<Data>, Func> Qs;
	Qs.push({ {0,0} , 0});
	g_DP[0][0] = 0;

	while (!Qs.empty())
	{
		Data Cur = Qs.top();
		Qs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int inX = Cur.Pos.first + g_DirX[i];
			int inY = Cur.Pos.second + g_DirY[i];
			int Point = Cur.Dis + g_Matrix[inY][inX];

			if (!IsIn(inX, inY))
				continue;

			if (g_DP[inY][inX] <= Point)
				continue;
			g_DP[inY][inX] = Point;

			if (inY == g_N - 1 && inX == g_N - 1)
				break;

			Qs.push({ { inX, inY }, Point });

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int iCount = 0;

	while (true)
	{
		++iCount;
		cin >> g_N;
		if (g_N == 0)
			break;

		for (int i = 0; i < g_N; ++i)
		{
			for (int j = 0; j < g_N; ++j)
			{
				cin >> g_Matrix[i][j];
			}
		}

		Reset();

		Dij();


		cout << "Problem " << iCount << ": " << g_DP[g_N - 1][g_N - 1] + g_Matrix[0][0] << "\n";

	}
	

	return 0;
}
