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

	int iN; cin >> iN;
	vector<int> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Inputs.push_back(iTemp);
	}


	vector<int> Pvs;
	Pvs.push_back(0);
	Pvs.push_back(1);
	int iIndex = 1;
	while (true)
	{
		int iSum = Pvs[iIndex] + Pvs[iIndex - 1];
		if (iSum > 1000000000)
			break;
		Pvs.push_back(iSum);
		++iIndex;
	}


	for (int i = 0; i < iN; ++i)
	{
		int iInput = Inputs[i];

		vector<int> TempAns;

		for (int p = Pvs.size() - 1; p >= 0; --p)
		{
			if (iInput <= 0)
				break;

			if (iInput >= Pvs[p])
			{
				iInput -= Pvs[p];
				TempAns.push_back(Pvs[p]);
			}
		}

		for (int j = TempAns.size() - 1; j >= 0; --j)
		{
			cout << TempAns[j] << ' ';
		}
		cout << '\n';

	}



	return 0;
}