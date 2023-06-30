#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int Sum(const string& sL, const string& sR)
{
	int iCount = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (sL[i] != sR[i])
		{
			++iCount;
		}
	}

	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;

	vector<int> iAnss;
	while (iT--)
	{
		int iN;
		cin >> iN;

		vector<string> sMBTI;
		for (int i = 0; i < iN; ++i)
		{
			string sTemp;
			cin >> sTemp;
			sMBTI.push_back(sTemp);
		}

		if (32 < iN)
		{
			iAnss.push_back(0);
			continue;
		}

		int iMin = INT_MAX;
		int iSum = 0;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = i + 1; j < iN; ++j)
			{
				for (int k = j + 1; k < iN; ++k)
				{
					iSum = 0;
					iSum += Sum(sMBTI[i], sMBTI[j]);
					iSum += Sum(sMBTI[i], sMBTI[k]);
					iSum += Sum(sMBTI[j], sMBTI[k]);

					iMin = min(iMin, iSum);
				}
			}
		}

		iAnss.push_back(iMin);
	}

	for (auto iAns : iAnss)
		cout << iAns << '\n';

	return 0;
}