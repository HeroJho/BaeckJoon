#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <climits>
#include <cmath>

using namespace std;

int N;
vector<int> Matrix[11];
int Value[11] = { 0 };
bool RedBlue[11] = { false };

bool Visited[11] = { false };

int Ans = INT_MAX;

void Reset()
{
	for (int i = 0; i < 11; ++i)
		Visited[i] = false;
}

void BFS(int Start)
{
	queue<int> Qs;
	Qs.push(Start);
	Visited[Start] = true;

	bool StartColor = RedBlue[Start];
	while (!Qs.empty())
	{
		int Cur = Qs.front();
		Qs.pop();

		for (int i = 0; i < Matrix[Cur].size(); ++i)
		{
			int Nex = Matrix[Cur][i];

			if (StartColor != RedBlue[Nex])
				continue;

			if (Visited[Nex])
				continue;
			Visited[Nex] = true;

			Qs.push(Nex);

		}

	}


}

int IterBFS()
{
	Reset();

	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Visited[i])
			continue;

		BFS(i);
		Cnt++;
	}

	return Cnt;
}

pair<int ,int> Check()
{
	pair<int, int> Cnt;

	for (int i = 1; i <= N; ++i)
	{
		if (RedBlue[i])
			Cnt.first += Value[i];
		else
			Cnt.second += Value[i];

	}

	return Cnt;
}

void DFS(int Cur)
{
	if (Cur > N)
	{
		int Cnt = IterBFS();
		if (Cnt == 2)
		{
			pair<int, int> RedBlueCnt = Check();
			int Dis = abs(RedBlueCnt.first - RedBlueCnt.second);
			if (Ans > Dis)
				Ans = Dis;
		}

		return;
	}

	RedBlue[Cur] = true;
	DFS(Cur + 1);
	RedBlue[Cur] = false;
	DFS(Cur + 1);

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Value[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		int Temp;
		cin >> Temp;
		for (int z = 0; z < Temp; ++z)
		{
			int Temp2;
			cin >> Temp2;
			Matrix[i].push_back(Temp2);
		}
	}

	DFS(1);

	if (Ans == INT_MAX)
		cout << -1;
	else
		cout << Ans;

	return 0;
}
