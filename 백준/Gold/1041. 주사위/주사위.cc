#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	long long iN;
	long long  Inputs[6] = { 0 };
	cin >> iN;
	for (int i = 0; i < 6; ++i)
	{
		cin >> Inputs[i];
	}

	if (iN < 2)
	{
		long long  iOneMax = 0;
		long long iTotal = 0;
		for (int i = 0; i < 6; ++i)
		{
			iTotal += Inputs[i];
			if (iOneMax < Inputs[i])
				iOneMax = Inputs[i];
		}

		cout << iTotal - iOneMax;

		return 0;
	}
	

	long long  iOne, iTwo, iThree;
	iThree = 4;
	iTwo = 8 * (iN - 2) + 4;
	iOne = ((iN * iN - (4 + ((iN - 2) * 3))) * 4) + (iN * iN - (4+(4*(iN-2))));


	// 한 면이 최소
	long long  iOneMin = INT_MAX;
	for (int i = 0; i < 6; ++i)
	{
		if (iOneMin > Inputs[i])
			iOneMin = Inputs[i];
	}


	// 두 면이 최소
	long long  iTwoMin = 0;
	vector<long long > Temps;
	long long  InvIndex = 5 - 0;
	Temps.push_back(min(Inputs[0], Inputs[InvIndex]));

	InvIndex = 5 - 1;
	Temps.push_back(min(Inputs[1], Inputs[InvIndex]));

	InvIndex = 5 - 2;
	Temps.push_back(min(Inputs[2], Inputs[InvIndex]));

	sort(Temps.begin(), Temps.end());
	iTwoMin = Temps[0] + Temps[1];
	

	// 세 면이 최소
	long long  iThreeMin = Temps[0] + Temps[1] + Temps[2];



	long long  iAns = iOne * iOneMin + iTwo * iTwoMin + iThree * iThreeMin;
	cout << iAns;


	return 0;
}