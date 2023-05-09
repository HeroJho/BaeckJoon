#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	map<int, int> iMapNums;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp; cin >> iTemp;
		iMapNums.insert({ iTemp, iTemp });
	}
	int iM;
	cin >> iM;
	vector<int> iNums;
	for (int i = 0; i < iM; ++i)
	{
		int iTemp; cin >> iTemp;
		iNums.push_back(iTemp);
	}

	for (int i = 0; i < iM; ++i)
	{
		if (iMapNums.find(iNums[i]) != iMapNums.end())
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}

	return 0;
}