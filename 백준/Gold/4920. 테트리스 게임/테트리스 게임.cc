#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN;
int g_Matrix[100][100] = { 0 };
vector<vector<pair<int, int>>> g_Ts;
long long g_iAns = -100000000;

bool IsIn(int x, int y)
{
	return x >= 0 && x < g_iN && y >= 0 && y < g_iN;
}

long long Go(int x, int y)
{
	long long iMaxSum = -100000000;
	for (int i = 0; i < g_Ts.size(); ++i)
	{
		long long iSum = 0;
		bool bS = false;
		for (int j = 0; j < g_Ts[i].size(); ++j)
		{
			pair<int, int> Pos = g_Ts[i][j];
			int inX = x + Pos.first;
			int inY = y + Pos.second;

			if (!IsIn(inX, inY))
			{
				bS = true;
				break;
			}

			iSum += g_Matrix[inX][inY];

		}

		if (!bS && iMaxSum < iSum)
			iMaxSum = iSum;
	}

	return iMaxSum;
}

void Check()
{
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iN; ++j)
		{
			
			long long iTemp = Go(i, j);
			if (g_iAns < iTemp)
				g_iAns = iTemp;

		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	g_Ts.push_back({ {0, 0}, {0, 1}, {0, 2}, {0, 3} });
	g_Ts.push_back({ {0, 0}, {1, 0}, {2, 0}, {3, 0} });

	g_Ts.push_back({ {0, 1}, {1, 1}, {1, 0}, {2, 0} });
	g_Ts.push_back({ {0, 0}, {0, 1}, {1, 1}, {1, 2} });

	g_Ts.push_back({ {0, 0}, {0, 1}, {1, 0}, {2, 0} });
	g_Ts.push_back({ {0, 0}, {0, 1}, {0, 2}, {1, 2} });
	g_Ts.push_back({ {0, 1}, {1, 1}, {2, 1}, {2, 0} });
	g_Ts.push_back({ {0, 0}, {1, 0}, {1, 1}, {1, 2} });

	g_Ts.push_back({ {0, 0}, {1, 0}, {2, 0}, {1, 1} });
	g_Ts.push_back({ {0, 0}, {0, 1}, {0, 2}, {1, 1} });
	g_Ts.push_back({ {0, 1}, {1, 1}, {2, 1}, {1, 0} });
	g_Ts.push_back({ {0, 1}, {1, 0}, {1, 1}, {1, 2} });

	g_Ts.push_back({ {0, 0}, {1, 0}, {1, 1}, {0, 1} });

	int iCount = 1;
	while (true)
	{
		g_iAns = -100000000;

		cin >> g_iN;
		if (g_iN == 0)
			break;

		for (int i = 0; i < g_iN; ++i)
		{
			for (int j = 0; j < g_iN; ++j)
			{
				cin >> g_Matrix[i][j];
			}
		}

		Check();

		cout << iCount << ". " << g_iAns << '\n';
		++iCount;
	}





	return 0;
}