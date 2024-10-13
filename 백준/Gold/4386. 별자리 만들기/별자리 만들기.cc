#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Func
{
public:
	bool operator()(pair<float, int> L, pair<float, int> R)
	{
		return L.first > R.first;
	}
};


int N;
vector<pair<float, float>> Inputs;
bool Visited[101] = { false };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		float X, Y;
		cin >> X >> Y;
		Inputs.push_back({ X,Y });
	}

	priority_queue<pair<float, int>, vector<pair<float, int>>, Func> Qs;
	Qs.push({ 0.f, 0 });

	// 간선 작은거 꺼낸다
	// 방문 표시한다
	// 해당 노드의 간선 전부 Qs
	float Ans = 0.f;
	while (!Qs.empty())
	{
		pair<float, int> Cur = Qs.top();
		Qs.pop();

		if (Visited[Cur.second])
			continue;
		Visited[Cur.second] = true;

		Ans += Cur.first;

		for (int i = 0; i < N; ++i)
		{
			if (Cur.second == i)
				continue;

			float Dis = sqrt(pow(Inputs[i].first - Inputs[Cur.second].first, 2) +
				pow(Inputs[i].second - Inputs[Cur.second].second, 2));

			Qs.push({ Dis, i });
		}

	}

	cout << Ans;

	return 0;
}
