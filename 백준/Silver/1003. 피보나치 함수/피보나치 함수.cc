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

	// 1 0
	// 0 1
	// 1 1
	// 1 2
	// 2 3
	// 3 5
	// 5 8
	// 8 13
	// 13 21

	int iT; cin >> iT;
	vector<int> iZeroAnss;
	vector<int> iOneAnss;
	for (int t = 0; t < iT; ++t)
	{
		int iTemp;
		cin >> iTemp;

		int iZero = 1;
		int iOne = 0;
		for (int i = 0; i < iTemp; ++i)
		{
			int iTemp = iOne;
			iOne += iZero;
			iZero = iTemp;
		}

		iZeroAnss.push_back(iZero);
		iOneAnss.push_back(iOne);
	}

	for (int i = 0; i < iZeroAnss.size(); ++i)
	{
		cout << iZeroAnss[i] << ' ' << iOneAnss[i] << '\n';
	}



	return 0;
}