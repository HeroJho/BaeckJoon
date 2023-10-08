#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

#define LL long long

using namespace std;

class Func
{
public:
	bool operator() (pair<int , LL> L, pair<int, LL> R)
	{
		return L.second > R.second;
	}
};

int g_iN, g_iM;
int g_Matrix[1001][1001] = { 0 };
LL g_DP[1001] = { 0 };
vector<int> g_Load[1001];
int g_iStart, g_iEnd;

void Reset()
{
	for (int i = 1; i <= g_iN; ++i)
	{
		g_DP[i] = LLONG_MAX;
	}

	for (int i = 1; i <= g_iN; ++i)
	{
		for (int j = 1; j <= g_iN; ++j)
		{
			g_Matrix[i][j] = INT_MAX;
		}
	}
}

void Dji()
{
	priority_queue<pair<int , LL>, vector<pair<int, LL>>, Func> Qs;
	Qs.push({g_iStart, 0});
	g_DP[g_iStart] = 0;
	g_Load[g_iStart].push_back(g_iStart);

	while (!Qs.empty())
	{
		pair<int , LL> Cur = Qs.top();
		Qs.pop();

		for (int i = 1; i <= g_iN; ++i)
		{
			if (INT_MAX == g_Matrix[Cur.first][i])
				continue;

			LL iNexDis = g_Matrix[Cur.first][i] + Cur.second;
			if (g_DP[i] > iNexDis)
			{
				g_DP[i] = iNexDis;
				
				g_Load[i].clear();
				g_Load[i].shrink_to_fit();
				for (int j = 0; j < g_Load[Cur.first].size(); ++j)
				{
					g_Load[i].push_back(g_Load[Cur.first][j]);
				}
				g_Load[i].push_back(i);

				Qs.push({ i, iNexDis });

			}

		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	Reset();
	for (int i = 0; i < g_iM; ++i)
	{
		int iStart, iEnd, iValue;
		cin >> iStart >> iEnd >> iValue;
		if(g_Matrix[iStart][iEnd] > iValue)
			g_Matrix[iStart][iEnd] = iValue;
	}
	cin >> g_iStart >> g_iEnd;

	Dji();

	cout << g_DP[g_iEnd] << '\n';
	cout << g_Load[g_iEnd].size() << '\n';
	
	for (int i = 0; i < g_Load[g_iEnd].size(); ++i)
	{
		cout << g_Load[g_iEnd][i] << ' ';
	}



	return 0;
}