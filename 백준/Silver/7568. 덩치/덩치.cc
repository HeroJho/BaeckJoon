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

	vector<pair<int, int>> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		pair<int, int> Temp;
		cin >> Temp.first >> Temp.second;
		Inputs.push_back(Temp);
	}


	int Checks[51] = { 0 };
	for (int i = 0; i < Inputs.size(); ++i)
	{
		for (int j = 0; j < Inputs.size(); ++j)
		{
			if (i == j)
				continue;

			if (Inputs[i].first < Inputs[j].first && Inputs[i].second < Inputs[j].second)
			{
				++Checks[i];
			}
		}
	}


	for (int i = 0; i < iN; ++i)
	{
		cout << (Checks[i] + 1)  << " ";
	}

	return 0;
}