#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_DP[1000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	vector<int> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp; cin >> iTemp;
		Inputs.push_back(iTemp);
	}


	g_DP[0] = 1;
	for (int i = 1; i < iN; ++i)
	{
		int iMax = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			if (Inputs[i] > Inputs[j] && iMax < g_DP[j])
			{
				iMax = g_DP[j];
				g_DP[i] = g_DP[j] + 1;
			}
		}

		if (g_DP[i] == 0)
			g_DP[i] = 1;

	}

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (iAns < g_DP[i])
			iAns = g_DP[i];
	}

	cout << iAns;

	return 0;
}