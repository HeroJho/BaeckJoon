#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;


bool BinCheck(const vector<int>& Inputs, int CheckIndex)
{
	int CheckSum = Inputs[CheckIndex];

	int Left = 0, Right = Inputs.size() - 1;

	while (true)
	{
		if (Right == CheckIndex)
		{
			--Right;
		}
		else if (Left == CheckIndex)
		{
			++Left;
		}

		if (Left >= Right)
			break;

		int Sum = Inputs[Left] + Inputs[Right];

		if (CheckSum < Sum)
		{
			--Right;
		}
		else if (CheckSum > Sum)
		{
			++Left;
		}
		else
		{
			return true;
		}

	}

	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp; cin >> Temp;
		Inputs.push_back(Temp);
	}

	sort(Inputs.begin(), Inputs.end());

	int Ans = 0;
	for (int i = 0; i < N; ++i)
	{
		Ans += BinCheck(Inputs, i);
	}

	cout << Ans;

	return 0;
}
