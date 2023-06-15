#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int iT;
	cin >> iT;
	vector<int> iAnss;
	++iT;;
	while(--iT)
	{
		int iN;
		cin >> iN;
		map<string, int> Inputs;
		for (int i = 0; i < iN; ++i)
		{
			string sTemp1, sTemp2;
			cin >> sTemp1 >> sTemp2;
			++Inputs[sTemp2];
		}

		int iAns = 1;

		for (auto pair : Inputs)
		{
			iAns *= pair.second + 1;
		}

		iAnss.push_back(iAns);
	}

	for (auto iAns : iAnss)
	{
		cout << iAns - 1 << '\n';
	}

	return 0;
}