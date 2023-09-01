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
		int iTemp; cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	sort(Inputs.rbegin(), Inputs.rend());

	long long iSum = 0;
	for (int i = 0; i < Inputs.size(); ++i)
	{
		int iTemp = Inputs[i] - i;
		if (iTemp < 0)
			iTemp = 0;

		iSum += iTemp;
	}

	cout << iSum;

	return 0;
}