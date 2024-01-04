#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_N, g_M, g_T;
vector<vector<int>> g_Inputs;

void Roll(int x, int d, int k)
{
	// g_x의 배수 원판을 g_d 방향으로 g_k 칸 돌린다
	int iIndex = x;
	for (; iIndex <= g_N; iIndex += x)
	{
		for (int j = 0; j < k; ++j)
		{

			if (d != 0) // 시계
			{
				int iTemp = g_Inputs[iIndex][0];
				for (int i = 0; i < g_M-1; ++i)
					g_Inputs[iIndex][i] = g_Inputs[iIndex][i+1];

				g_Inputs[iIndex][g_M - 1] = iTemp;
			}
			else
			{
				int iTemp = g_Inputs[iIndex][g_M - 1];
				for (int i = g_M - 1; i >= 1; --i)
					g_Inputs[iIndex][i] = g_Inputs[iIndex][i-1];

				g_Inputs[iIndex][0] = iTemp;
			}

		}


	}

}
void Check()
{
	// 인접한 것들 체크
	vector<pair<int, int>> Temps;
	for (int i = 0; i < g_M; ++i)
	{
		int PreNum = -1;
		for (int j = 1; j <= g_N; ++j)
		{
			if (g_Inputs[j][i] == -1)
			{
				PreNum = -1;
				continue;
			}

			// j번째 판의 i번 번호
			if (PreNum == g_Inputs[j][i])
			{
				Temps.push_back({ j, i });
				Temps.push_back({ j - 1, i });
			}
			else
			{
				PreNum = g_Inputs[j][i];
			}

		}
	}


	// 좌우
	for (int i = 1; i <= g_N; ++i)
	{
		for (int j = 0; j < g_M-1; ++j)
		{
			if (g_Inputs[i][j] == -1)
				continue;

			if (g_Inputs[i][j] == g_Inputs[i][j + 1])
			{
				Temps.push_back({ i, j });
				Temps.push_back({ i, j + 1 });
			}
		}

		if (g_Inputs[i][0] == -1)
			continue;

		if (g_Inputs[i][0] == g_Inputs[i][g_M-1])
		{
			Temps.push_back({ i, 0 });
			Temps.push_back({ i, g_M - 1 });
		}
	}




	// 인접한 것들 있다 -> -1로 지우기
	// 인접한 것들 없다 -> 판 평균 구해서 평균보다 작은 값은 높이고 낮은 값은 낮추기
	if (Temps.size() == 0)
	{
		double iTotal = 0;
		int iCount = 0;
		for (int i = 1; i <= g_N; ++i)
		{
			for (int j = 0; j < g_M; ++j)
			{
				if (g_Inputs[i][j] == -1)
					continue;
				iTotal += g_Inputs[i][j];
				iCount++;
			}
		}

		iTotal /= iCount;
		for (int i = 1; i <= g_N; ++i)
		{
			for (int j = 0; j < g_M; ++j)
			{
				if (iTotal < g_Inputs[i][j])
				{
					if (g_Inputs[i][j] == -1)
						continue;

					--g_Inputs[i][j];
					if (g_Inputs[i][j] < 0)  // 예외 체크
						g_Inputs[i][j] = 0;
				}
				else if(iTotal > g_Inputs[i][j])
				{
					if (g_Inputs[i][j] == -1)
						continue;
					++g_Inputs[i][j];
				}
			}
		}

	}
	else
	{
		for (int i = 0; i < Temps.size(); ++i)
		{
			g_Inputs[Temps[i].first][Temps[i].second] = -1;
		}
	}
	


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_N >> g_M >> g_T;

	g_Inputs.push_back(vector<int>());
	for (int i = 1; i <= g_N; ++i)
	{
		g_Inputs.push_back(vector<int>());
		for (int j = 0; j < g_M; ++j)
		{
			int iTemp;
			cin >> iTemp;
			g_Inputs[i].push_back(iTemp);
		}
	}

	vector<vector<int>> Inputs2;
	for (int i = 0; i < g_T; ++i)
	{
		int x, d, k;
		cin >> x >> d >> k;
		Inputs2.push_back({x, d, k});
	}
	

	// 총 T번 한다
	for (int i = 0; i < g_T; ++i)
	{
		Roll(Inputs2[i][0], Inputs2[i][1], Inputs2[i][2]);
		Check();
	}

	int iTotal = 0;
	for (int i = 1; i <= g_N; ++i)
	{
		for (int j = 0; j < g_M; ++j)
		{
			if (g_Inputs[i][j] == -1)
				continue;
			iTotal += g_Inputs[i][j];
		}
	}

	cout << iTotal;

	return 0;
}