#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;

	vector<int> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	sort(Inputs.begin(), Inputs.end());
	for (int i = 0; i < iN; ++i)
	{
		if (iM >= Inputs[i])
		{
			++iM;
		}
		else
		{
			break;
		}
	}

	cout << iM;

	return 0;
}