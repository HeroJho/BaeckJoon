#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <climits>
#include <cmath>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);



	int T;
	cin >> T;

	while (T--)
	{
		pair<float, float> Start, End;

		cin >> Start.first >> Start.second;
		cin >> End.first >> End.second;

		int N;
		cin >> N;

		vector<pair<int, pair<int, int>>> Inputs;
		for (int i = 0; i < N; ++i)
		{
			pair<float, float> Temp;
			int R;
			cin >> Temp.first >> Temp.second;
			cin >> R;
			Inputs.push_back({ R, Temp });
		}

		int Ans = 0;
		for (int i = 0; i < N; ++i)
		{
			pair<float, float> Temp = Inputs[i].second;
			int R = Inputs[i].first;
			float Dis = sqrt(pow(Start.first - Temp.first, 2) + pow(Start.second - Temp.second, 2));

			bool bL = false;
			if (Dis < R)
			{
				bL = true;
			}

			Temp = Inputs[i].second;
			R = Inputs[i].first;
			Dis = sqrt(pow(End.first - Temp.first, 2) + pow(End.second - Temp.second, 2));

			bool bR = false;
			if (Dis < R)
			{
				bR = true;
			}

			if (bL && bR)
			{
				continue;
			}
			else if (bL || bR)
			{
				Ans++;
			}

		}

		cout << Ans << '\n';

	}





	
	return 0;
}
