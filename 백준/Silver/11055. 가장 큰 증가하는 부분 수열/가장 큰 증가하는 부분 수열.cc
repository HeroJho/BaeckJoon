#include <iostream>
#include <vector>
#include <queue>


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
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}

	
	vector<int> DP(N);


	DP[N - 1] = Inputs[N - 1];
	for (int i = N - 2; i >= 0; --i)
	{
		int Max = 0;
		for (int z = i + 1; z < N; ++z)
		{
			if (Inputs[i] < Inputs[z])
			{
				if (Max < DP[z])
				{
					Max = DP[z];
				}
			}
		}

		DP[i] = Inputs[i] + Max;

	}

	int Max = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Max < DP[i])
		{
			Max = DP[i];
		}
	}

	cout << Max;

	return 0;
}
