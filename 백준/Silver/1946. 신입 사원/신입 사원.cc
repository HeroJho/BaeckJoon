#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;

	vector<int> iAnss;
	while (iT)
	{
		--iT;

		int iN;
		cin >> iN;
		map<int, int> iNums;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp1, iTemp2;
			cin >> iTemp1 >> iTemp2;
			iNums.emplace(iTemp1, iTemp2);
		}

		int iCount = 1;
		int iMin = iNums[1];
		for (int i = 2; i <= iN; ++i)
		{
			if (iMin < iNums[i])
			{
				continue;
			}

			iMin = iNums[i];
			++iCount;
		}

		iAnss.push_back(iCount);
	}

	for (auto iAns : iAnss)
	{
		cout << iAns << '\n';
	}

	return 0;
}