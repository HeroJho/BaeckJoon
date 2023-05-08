#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;

	vector<int> iNums;
	int iMax = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp = 0; cin >> iTemp;
		iNums.push_back(iTemp);
		iMax = max(iTemp, iMax);
	}


	unsigned int iLeft = 1;
	unsigned int iRight = iMax;
	int iMaxLength = 0;
	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) / 2;

		unsigned int iCount = 0;
		for (int i = 0; i < iN; ++i)
		{
			iCount += iNums[i] / iMid;
		}

		if (iCount >= iM)
		{ // 자를 길이를 늘린다
			iLeft = iMid + 1;

			iMaxLength = max(iMaxLength, iMid);
		}
		else if (iCount < iM)
		{ // 자를 길이를 줄인다
			iRight = iMid - 1;
		}
	}

	cout << iMaxLength;


	return 0;
}