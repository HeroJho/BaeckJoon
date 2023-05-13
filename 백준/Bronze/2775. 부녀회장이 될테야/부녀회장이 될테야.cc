#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT; cin >> iT;
	vector<int> iAnss;
	for (int t = 0; t < iT; ++t)
	{
		int iFloor, iHo;
		cin >> iFloor >> iHo;
		// 1  4  10 20 35 56
		// 1  3  6  10 15 21
		// 1  2  3  4  5  6

		vector<int> iTemps;
		for (int i = 1; i <= iHo; ++i)
		{
			iTemps.push_back(i);
		}

		int iAns = 0;
		for (int i = 0; i < iFloor; ++i)
		{
			vector<int> iPreTemps = iTemps;
			iAns = 0;
			for (int j = 0; j < iHo; ++j)
			{
				iAns += iPreTemps[j];
				iTemps[j] = iAns;
			}
		}

		iAnss.push_back(iTemps[iHo - 1]);
	}


	for (auto& iAns : iAnss)
	{
		cout << iAns << '\n';
	}


	return 0;
}