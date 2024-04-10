#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int N;
int Matrix[102][102] = {0};
bool Visited[102] = { false };

void Reset()
{
	for (int i = 0; i < 102; ++i)
	{
		Visited[i] = false;

		for (int j = 0; j < 102; ++j)
		{
			Matrix[i][j] = 0;
		}
	}

}

bool BFS()
{
	queue<int> Qs;
	Qs.push(0);
	Visited[0] = true;

	while (!Qs.empty())
	{
		int Cur = Qs.front();
		Qs.pop();

		if (Cur == N + 1)
		{
			return true;
		}


		for (int i = 0; i < N + 2; ++i)
		{
			if (Matrix[Cur][i] == 0)
				continue;

			if (Visited[i])
				continue;
			Visited[i] = true;

			Qs.push(i);

		}

	}

	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// dis가 1000 이하인 애들만 간선을 연결
	// 시작점에서 시작해서
	// 끝점 도착하는지 확인

	int T;
	cin >> T;

	while (T--)
	{
		Reset();

		cin >> N;
		vector<pair<int, int>> Inputs;
		pair<int, int> Start;
		cin >> Start.first >> Start.second;
		Inputs.push_back(Start);
		for (int i = 0; i < N; ++i)
		{
			pair<int, int> Temp;
			cin >> Temp.first >> Temp.second;
			Inputs.push_back(Temp);
		}
		pair<int, int> End;
		cin >> End.first >> End.second;
		Inputs.push_back(End);

		for (int i = 0; i < N + 2; ++i)
		{
			for (int j = 0; j < N + 2; ++j)
			{
				if (i == j)
					continue;

				int Dis = abs(Inputs[i].first - Inputs[j].first) + abs(Inputs[i].second - Inputs[j].second);
				if (Dis <= 1000)
				{
					Matrix[i][j] = 1;
				}

			}
		}

		if (BFS())
		{
			cout << "happy" << '\n';
		}
		else
		{
			cout << "sad" << '\n';
		}
	}

	return 0;
}
