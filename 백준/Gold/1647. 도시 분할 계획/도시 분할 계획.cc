#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.first > R.first;
	}
};

int N, M;

vector<pair<int, int>> Matrix[100001];
int DP[100001] = { INT_MAX };

void Reset()
{
	for (int i = 0; i < 100001; ++i)
	{
		DP[i] = INT_MAX;
	}
}


void Dij()
{
	vector<int> Lines;
	Reset();

	priority_queue<pair<int, int>, vector<pair<int, int>>, Func> Qs;
	Qs.push({ 0,1 });

	while (!Qs.empty())
	{
		int CurIndex = Qs.top().second;
		int CurValue = Qs.top().first;
		Qs.pop();

		
		if (DP[CurIndex] != INT_MAX)
			continue;
		DP[CurIndex] = 0;

		Lines.push_back(CurValue);


		for (int i = 0; i < Matrix[CurIndex].size(); ++i)
		{
			int NexIndex = Matrix[CurIndex][i].second;
			int NexValue = Matrix[CurIndex][i].first;

			Qs.push({ NexValue, NexIndex });
		}

	}

	sort(Lines.rbegin(), Lines.rend());

	int Ans = 0;
	for (int i = 1; i < Lines.size(); ++i)
	{
		Ans += Lines[i];
	}

	cout << Ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int Start, End, Value;
		cin >> Start >> End >> Value;
		Matrix[Start].push_back({ Value, End });
		Matrix[End].push_back({ Value, Start });
	}

	Dij();

	return 0;
}
