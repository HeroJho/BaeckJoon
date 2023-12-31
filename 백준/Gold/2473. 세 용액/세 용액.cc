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
		long long iTemp;
		cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	sort(Inputs.begin(), Inputs.end());

	long long One = 0, Two = 0, Three = 0;
	long long Sum = LLONG_MAX;
	for (int i = 0; i < N - 2; ++i)
	{
		long long Left = i + 1, Right = N - 1;

		while (Left < Right)
		{
			long long TempSum = Inputs[i] + Inputs[Left] + Inputs[Right];
			if (Sum > abs(TempSum))
			{
				One = i;
				Two = Left;
				Three = Right;
				Sum = abs(TempSum);
			}

			if (TempSum < 0)
			{
				++Left;
			}
			else if (TempSum > 0)
			{
				--Right;
			}
			else
			{
				One = i;
				Two = Left;
				Three = Right;
				Sum = 0;

				break;
			}

		}

		if (Sum == 0)
			break;

	}

	cout << Inputs[One] << " " << Inputs[Two] << " " << Inputs[Three];


	return 0;
}
