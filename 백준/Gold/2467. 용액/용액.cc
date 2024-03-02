#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp; cin >> Temp;
		Inputs.push_back(Temp);
	}


	int Left = 0, Right = N - 1;
	pair<int, int> Ans;
	int PreSum = INT_MAX;
	while (Left < Right) // 같을 땐 그만둔다.
	{
		int Sum = Inputs[Left] + Inputs[Right];
		if (PreSum >= abs(Sum))
		{
			PreSum = abs(Sum);
			Ans.first = Left;
			Ans.second = Right;
		}

		if (0 < Sum) // 크다
		{
			--Right;
		}
		else if(0 > Sum)
		{
			++Left;
		}
		else
		{
			Ans.first = Left;
			Ans.second = Right;
			break;
		}
	}

	cout << Inputs[Ans.first] << " " << Inputs[Ans.second];

	return 0;
}
