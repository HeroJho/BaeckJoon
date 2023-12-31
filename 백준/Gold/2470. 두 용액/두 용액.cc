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

	vector<long long> Inputs;
	for (int i = 0; i < N; ++i)
	{
		long long iTemp; cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	sort(Inputs.begin(), Inputs.end());

	int Left = 0, Right = Inputs.size() - 1;
	int vLeft = 0, vRight = 0;
	long long Min = LLONG_MAX;

	while (Left < Right)
	{
		long long M = Inputs[Left] + Inputs[Right];

		if (Min > abs(M))
		{
			vLeft = Left;
			vRight = Right;
			Min = abs(M);
		}

		if (M > 0)
			--Right;
		else if (M < 0)
			++Left;
		else
			break;

	}

	cout << Inputs[vLeft] << " " << Inputs[vRight];

	return 0;
}
