#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_DP[200001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;

	for (int t = 0; t < iT; ++t)
	{

		int iN;
		cin >> iN;

		vector<int> Temps1;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp;
			cin >> iTemp;
			Temps1.push_back(iTemp);
		}
		vector<int> Temps2;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp;
			cin >> iTemp;
			Temps2.push_back(iTemp);
		}

		vector<int> Inputs;
		for (int i = 0; i < iN; ++i)
		{
			Inputs.push_back(Temps1[i]);
			Inputs.push_back(Temps2[i]);
		}

		

		if (iN == 1)
		{
			cout << max(Inputs[0], Inputs[1]) << '\n';
			continue;
		}
		else if(iN == 2)
		{
			g_DP[0] = Inputs[0];
			g_DP[1] = Inputs[1];
			g_DP[2] = g_DP[1] + Inputs[2];
			g_DP[3] = g_DP[0] + Inputs[3];

			cout << max(g_DP[2], g_DP[3]) << '\n';
			continue;
		}



		g_DP[0] = Inputs[0];
		g_DP[1] = Inputs[1];
		g_DP[2] = g_DP[1] + Inputs[2];
		g_DP[3] = g_DP[0] + Inputs[3];

		for (int i = 4; i < iN * 2; ++i)
		{
			if (i % 2 == 0)
				g_DP[i] = max(g_DP[i - 3] + Inputs[i], g_DP[i - 1] + Inputs[i]);
			else
				g_DP[i] = max(g_DP[i - 5] + Inputs[i], g_DP[i - 3] + Inputs[i]);
		}

		int iAns = 0;
		for (int i = 0; i < iN * 2; ++i)
		{
			if (iAns < g_DP[i])
				iAns = g_DP[i];
		}

		cout << iAns << '\n';


	}



	return 0;
}