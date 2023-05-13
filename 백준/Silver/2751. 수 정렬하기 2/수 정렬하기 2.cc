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

	int iNum; cin >> iNum;
	vector<int> iNums;
	for (int i = 0; i < iNum; ++i)
	{
		int iTemp; cin >> iTemp;
		iNums.push_back(iTemp);
	}

	sort(iNums.begin(), iNums.end());

	for (auto& iNum : iNums)
	{
		cout << iNum << '\n';
	}

	return 0;
}