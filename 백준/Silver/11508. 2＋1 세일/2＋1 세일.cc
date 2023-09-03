#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	vector<int> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;

		Inputs.push_back(iTemp);
	}

	sort(Inputs.rbegin(), Inputs.rend());

	int iAns = 0;
	int iCount = 0;
	int iSum = 0;
	for (int i = 0; i < Inputs.size(); ++i)
	{
		++iCount;
		if (iCount >= 3)
		{
			iAns += iSum;
			iSum = 0;
			iCount = 0;
		}
		else
			iSum += Inputs[i];
		
	}

	if (iCount > 0)
	{
		iAns += iSum;
	}

	cout << iAns;

	return 0;
}