#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	int iN, iM;
	vector<int> iNums;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iNums.push_back(iTemp);
	}


	vector<int> iAccs;
	int iSum = 0;
	iAccs.push_back(0);
	for (int i = 0; i < iN; ++i)
	{
		iSum += iNums[i];
		iAccs.push_back(iSum);
	}

	vector<int> iAnss;
	++iM;
	while (--iM)
	{
		int iStart, iEnd;
		cin >> iStart >> iEnd;

		int iAns = iAccs[iEnd] - iAccs[iStart - 1];
		iAnss.push_back(iAns);
	}

	for (auto iAns : iAnss)
	{
		cout << iAns << '\n';
	}

	return 0;
}