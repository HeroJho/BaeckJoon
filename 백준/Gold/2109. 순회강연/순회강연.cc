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
		return L.second < R.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> Inputs;
	for (int i = 0; i < N; ++i)
	{
		pair<int, int> Temp;
		cin >> Temp.first >> Temp.second;
		Inputs.push_back(Temp);
	}

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	sort(Inputs.begin(), Inputs.end(), Func());

	int Ans = 0;

	int Day = Inputs.back().second;
	priority_queue<int> Qs;

	while (Day > 0)
	{
		while (!Inputs.empty())
		{
			if (Day > Inputs.back().second)
				break;

			Qs.push(Inputs.back().first);
			Inputs.pop_back();
		}
		
		// 확인한다
		if (!Qs.empty())
		{
			Ans += Qs.top();
			Qs.pop();
		}

		--Day;
	}

	cout << Ans;

	return 0;
}
