#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	map<string, string> iMaps;
	vector<string> iInputs;
	for (int i = 0; i < iN; ++i)
	{
		string sTemp1, sTemp2;
		cin >> sTemp1 >> sTemp2;
		iMaps.insert({ sTemp1, sTemp2 });
	}


	for (int i = 0; i < iM; ++i)
	{
		string sTemp;
		cin >> sTemp;

		auto iter = iMaps.find(sTemp);
		if (iter == iMaps.end())
			continue;

		iInputs.push_back((*iter).second);
	}


	for (int i = 0; i < iM; ++i)
	{
		cout << iInputs[i] << '\n';
	}

	return 0;
}