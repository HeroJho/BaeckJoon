#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second > R.second;
	}
};

int N, M, Dis, Start;
vector<int> Matrix[300001];
int DP[300001] = { 0 };

void Dij()
{
	for (int i = 1; i <= N; ++i)
	{
		DP[i] = INT_MAX;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, Func> Qs;
	Qs.push({Start, 0});
	DP[Start] = 0;

	while (!Qs.empty())
	{
		pair<int, int> Cur = Qs.top();
		Qs.pop();

		for (int i = 0; i < Matrix[Cur.first].size(); ++i)
		{
			int nNode = Matrix[Cur.first][i];
			int nDis = Cur.second + 1;

			if (DP[nNode] <= nDis)
				continue;
			DP[nNode] = nDis;

			Qs.push({nNode, nDis});

		}

	}


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> Dis >> Start;
	for (int i = 0; i < M; ++i)
	{
		int Start, End;
		cin >> Start >> End;
		Matrix[Start].push_back(End);
	}


	Dij();

	vector<int> Anss;
	for(int i = 1; i <= N; ++i)
	{
		if (DP[i] == Dis)
		{
			Anss.push_back(i);
		}
	}

	if (Anss.empty())
		cout << -1;
	else
	{
		for (int i = 0; i < Anss.size(); ++i)
		{
			cout << Anss[i] << '\n';
		}
	}


	return 0;
}
