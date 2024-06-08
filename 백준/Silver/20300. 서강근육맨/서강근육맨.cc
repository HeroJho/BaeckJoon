#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>

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
		long long Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}

	sort(Inputs.begin(), Inputs.end());


	int Left = 0;
	int Right = Inputs.size() - 1;

	if (Inputs.size() % 2 != 0)
		Right = Inputs.size() - 2;

	long long Max = 0;
	while (Left < Right)
	{
		long long Sum = Inputs[Left] + Inputs[Right];

		if (Max < Sum)
			Max = Sum;

		Left++;
		Right--;
	}

	if (Inputs.size() % 2 != 0)
	{
		if (Max < Inputs.back())
			Max = Inputs.back();
	}

	cout << Max;


	return 0;
}
