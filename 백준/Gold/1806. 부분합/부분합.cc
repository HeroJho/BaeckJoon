#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int iN, iM;
	cin >> iN >> iM;
	vector<int> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	long long iSum = 0;
	int iLeft = 0;
	int iAns = INT_MAX;
	for (int i = 0; i < Inputs.size(); ++i)
	{
		long long iTemp = iSum + Inputs[i];
	
		while (iM <= iTemp)
		{
			if (iAns > i - iLeft)
				iAns = i - iLeft;

			iTemp -= Inputs[iLeft];
			++iLeft;
		}

		iSum = iTemp;



	}

	if (iAns != INT_MAX)
		cout << iAns + 1;
	else
		cout << 0;

	return 0;
}
	