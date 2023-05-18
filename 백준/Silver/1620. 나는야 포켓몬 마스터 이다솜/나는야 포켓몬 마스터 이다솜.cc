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

	unordered_map<string, int> mStringList;
	unordered_map<int, string> mIntList;
	for (int i = 1; i <= iN; ++i)
	{
		string sTemp;
		cin >> sTemp;
		mStringList.insert({ sTemp, i });
		mIntList.insert({ i, sTemp });
	}

	vector<string> sInput(iM+1, "");
	for (int i = 1; i <= iM; ++i)
	{
		string sTemp;
		cin >> sTemp;
		sInput[i] = sTemp;
	}

	vector<string> sAnss;
	for (int i = 1; i <= iM; ++i)
	{
		string sS = sInput[i];
		char czChar = sS[0];
		int iChar = czChar - '0';
		if (iChar < 10)
		{
			sAnss.push_back(mIntList[stoi(sS)]);
		}
		else
		{
			sAnss.push_back(to_string(mStringList[sS]));
		}
	}
	
	for (int i = 0; i < sAnss.size(); ++i)
	{
		cout << sAnss[i] << '\n';
	}

	return 0;
}