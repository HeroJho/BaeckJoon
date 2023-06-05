#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	set<string> Temps1;
	set<string> Temps2;

	for (int i = 0; i < iN; ++i)
	{
		string sTemp;
		cin >> sTemp;
		Temps1.emplace(sTemp);
	}
	for (int i = 0; i < iM; ++i)
	{
		string sTemp;
		cin >> sTemp;
		Temps2.emplace(sTemp);
	}

	vector<string> sV;
	for (auto& sTemp1 : Temps1)
	{
		if (Temps2.find(sTemp1) != Temps2.end())
		{
			sV.push_back(sTemp1);
		}
	}

	cout << sV.size() << '\n';
	for (auto& sTemp : sV)
	{
		cout << sTemp << '\n';
	}

	return 0;
}