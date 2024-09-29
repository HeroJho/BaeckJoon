#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int DP[20][10001] = { 0 };


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
		vector<int> Inputs;
		for (int i = 0; i < N; ++i)
		{
			int Temp;
			cin >> Temp;
			Inputs.push_back(Temp);
		}
		int M;
		cin >> M;

		// Reset
		for (int n = 0; n < N; ++n)
			for (int m = 0; m <= M; ++m)
				DP[n][m] = 0;

	
		for (int m = 0; m <= M; ++m)
		{
			if (m % Inputs[0] == 0)
				DP[0][m] = 1;
		}
		// 0원은 꼭 만들 수 있다
		for (int n = 0; n < N; ++n)
		{
			DP[n][0] = 1;
		}

		for (int n = 1; n < N; ++n)
		{
			for (int m = 0; m <= M; ++m)
			{
				if (m - Inputs[n] >= 0)
					DP[n][m] = DP[n - 1][m] + DP[n][m - Inputs[n]];
				else
					DP[n][m] = DP[n - 1][m];
			}
		}

		cout << DP[N - 1][M] << '\n';
	}



	return 0;
}
