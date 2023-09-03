#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Data
{
	pair<int, int> Pos = {0, 0};
	bool IsD = false;
};

int g_N, g_M;
char g_Matrix[50][50] = { 0 };

int g_DirX[4] = { 0, 0, -1, 1 };
int g_DirY[4] = { 1, -1, 0, 0 };

int g_Ans = 0;

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_M && iY >= 0 && iY < g_N;
}

void BFS(vector<pair<int ,int>> Start_Ds, pair<int, int> Start_S)
{
	queue<Data> Qs;
	Data temp;
	
	temp.Pos = Start_S;
	temp.IsD = false;
	Qs.push(temp);

	for (int i = 0; i < Start_Ds.size(); ++i)
	{
		temp.Pos = Start_Ds[i];
		temp.IsD = true;
		Qs.push(temp);
	}


	int iAns = 0;

	while (!Qs.empty())
	{
		int iSize = Qs.size();
		++iAns;
		for (int t = 0; t < iSize; ++t)
		{
			Data Cur = Qs.front();
			Qs.pop();

			// 먹혔다
			if (!Cur.IsD && g_Matrix[Cur.Pos.second][Cur.Pos.first] == '*')
				continue;

			for (int i = 0; i < 4; ++i)
			{
				int inX = g_DirX[i] + Cur.Pos.first;
				int inY = g_DirY[i] + Cur.Pos.second;

				if (!IsIn(inX, inY))
					continue;
				if (g_Matrix[inY][inX] == 'X')
					continue;

				// 물이면
				if (Cur.IsD)
				{
					if (g_Matrix[inY][inX] == '*')
						continue;
					if (g_Matrix[inY][inX] == 'D')
						continue;

					g_Matrix[inY][inX] = '*';

					Data Temp;
					Temp.IsD = true;
					Temp.Pos.first = inX;
					Temp.Pos.second = inY;
					Qs.push(Temp);
				}
				// 두더지면
				else
				{
					if (g_Matrix[inY][inX] == '*')
						continue;
					if (g_Matrix[inY][inX] == 'S')
						continue;

					if (g_Matrix[inY][inX] == 'D')
					{
						cout << iAns;
						return;
					}

					g_Matrix[inY][inX] = 'S';

					Data Temp;
					Temp.IsD = false;
					Temp.Pos.first = inX;
					Temp.Pos.second = inY;
					Qs.push(Temp);
				}


			}

		}


	}

	cout << "KAKTUS";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_N >> g_M;
	pair<int, int> S, D;
	vector<pair<int, int>> Ds;
	for (int y = 0; y < g_N; ++y)
	{
		for (int x = 0; x < g_M; ++x)
		{
			cin >> g_Matrix[y][x];
			if (g_Matrix[y][x] == '*')
			{
				D.first = x;
				D.second = y;
				Ds.push_back(D);
			}
			else if (g_Matrix[y][x] == 'S')
			{
				S.first = x;
				S.second = y;
			}
		}
	}

	BFS(Ds , S);

	return 0;
}