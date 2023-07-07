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

	int iN;
	cin >> iN;
	vector<int> iNums;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iNums.push_back(iTemp);
	}

	sort(iNums.rbegin(), iNums.rend());

	int iMax = iNums[0];
	for (int i = 1; i < iN; ++i)
	{
		int iRopeCount = i + 1;
		int iWeight = iNums[i] * iRopeCount;
		if (iWeight > iMax)
		{
			iMax = iWeight;
		}
	}

	cout << iMax;

	return 0;
}