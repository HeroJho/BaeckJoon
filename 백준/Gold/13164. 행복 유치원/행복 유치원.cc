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

	int iN, iM;
	cin >> iN >> iM;
	vector<int> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	vector<int> Diss;
	for (int i = 1; i < iN; ++i)
	{
		Diss.push_back(Inputs[i] - Inputs[i - 1]);
	}

	sort(Diss.begin(), Diss.end());

	for (int i = 0; i < iM - 1; ++i)
	{
		Diss.pop_back();
	}

	int iAns = 0;
	for (int i = 0; i < Diss.size(); ++i)
	{
		iAns += Diss[i];
	}

	cout << iAns;

	return 0;
}