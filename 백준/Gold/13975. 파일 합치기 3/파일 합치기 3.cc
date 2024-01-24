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
	bool operator()(long long L, long long R)
	{
		return L > R;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		priority_queue<long long, vector<long long>, Func> Qs;
		for (int i = 0; i < N; ++i)
		{
			long long Temp;
			cin >> Temp;
			Qs.push(Temp);
		}

		long long Ans = 0;
		while (Qs.size() > 1)
		{
			// 두 개를 꺼낸다
			// 합친다
			// Qs에 넣는다
			long long Num1 = Qs.top();
			Qs.pop();
			long long Num2 = Qs.top();
			Qs.pop();

			long long Sum = Num1 + Num2;
			Ans += Sum;
			Qs.push(Sum);
		}

		cout << Ans << '\n';
	}


	return 0;
}
