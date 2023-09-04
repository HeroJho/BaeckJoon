#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iAns = 0;
	vector<int> Boxs(iM + 1, 0);

	bool bTurn = true;
	for (int i = 1; i <= iM; ++i)
	{
		if (iN - i < 0)
		{
			bTurn = false;
			break;
		}

		Boxs[i] = i;
		iN -= i;
	}

	if (!bTurn)
	{
		cout << -1;
		return 0;
	}
		

	int iCount = iM + 1;
	while (true)
	{
		--iCount;

		if (0 >= iCount)
			iCount = iM;


		if (iN - 1 < 0)
			break;
		else
		{
			++Boxs[iCount];
			--iN;
		}
	}

	int iMin = INT_MAX;
	int iMax = 0;
	for (int i = 1; i <= iM; ++i)
	{
		if (Boxs[i] > iMax)
		{
			iMax = Boxs[i];
		}
		if (Boxs[i] < iMin)
		{
			iMin = Boxs[i];
		}
	}


	cout << iMax - iMin;


	return 0;
}