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

	int iN;
	cin >> iN;

	vector<long long> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		long long iTemp; cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	sort(Inputs.begin(), Inputs.end());

	int iLeft = 0, iRight = Inputs.size() - 1;
	int ivLeft = 0, ivRight = 0;
	long long iMin = LLONG_MAX;

	while (iLeft < iRight)
	{
		long long iM = Inputs[iLeft] + Inputs[iRight];

		if (iMin > abs(iM))
		{
			ivLeft = iLeft;
			ivRight = iRight;
			iMin = abs(iM);
		}

		if (iM > 0)
		{
			--iRight;
		}
		else if (iM < 0)
		{
			++iLeft;
		}
		else
		{
			break;
		}
		
	}
	

	cout << Inputs[ivLeft] << " " << Inputs[ivRight];

	return 0;
}
