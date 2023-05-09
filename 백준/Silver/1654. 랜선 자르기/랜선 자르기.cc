#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int iK, iN;
	cin >> iK >> iN;
	vector<int> iNums;
	int iMax = 0;
	for (int i = 0; i < iK; ++i)
	{
		int iTemp = 0; cin >> iTemp;
		iNums.push_back(iTemp);
		iMax = max(iMax, iTemp);
	}

	long long iLeft = 1;
	long long iRight = iMax;
	long long iMid = (iLeft + iRight) / 2;
	long long iAns = 0;
	while (iLeft <= iRight)
	{
		iMid = (iLeft + iRight) / 2;

		long long iLineNum = 0;
		for (int i = 0; i < iNums.size(); ++i)
		{
			iLineNum += iNums[i] / iMid;
		}

		if (iLineNum >= iN)
		{
			iLeft = iMid + 1;
			
			iAns = max(iAns, iMid);
		}
		else if (iLineNum < iN)
		{
			iRight = iMid - 1;
		}
		
	}

	cout << iAns;

	return 0;
}