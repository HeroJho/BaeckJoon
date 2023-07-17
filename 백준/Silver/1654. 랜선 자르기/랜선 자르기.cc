#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

long long Check(int iIndex, vector<int>& iNums)
{
	long long iCount = 0;
	for (int i = 0; i < iNums.size(); ++i)
	{
		iCount += (iNums[i] / iIndex);
	}

	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	vector<int> iNums;
	int iMax = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iNums.push_back(iTemp);
		if (iMax < iTemp)
			iMax = iTemp;
	}

	long long iLeft = 1, iRight = iMax, iMiddle;
	int iAns = 0;
	while (iLeft <= iRight)
	{
		iMiddle = (iLeft + iRight) / 2;

		long long iCount = Check(iMiddle, iNums);

		if (iCount >= iM)
		{
			iLeft = iMiddle + 1;

			iAns = iMiddle;
		}
		else
		{
			iRight = iMiddle - 1;
		}

	}

	cout << iAns;

	return 0;
}