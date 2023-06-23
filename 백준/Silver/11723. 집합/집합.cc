#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int iN;
	cin >> iN;
	vector<bool> iNums(21, false);
	vector<bool> iAnss;
	for (int i = 0; i < iN; ++i)
	{
		string sOrder;
		int iNum = 0;
		cin >> sOrder;

		if("all" != sOrder && "empty" != sOrder)
			cin >> iNum;

		if ("add" == sOrder)
		{
			iNums[iNum] = true;
		}
		else if ("remove" == sOrder)
		{
			iNums[iNum] = false;
		}
		else if ("check" == sOrder)
		{
			iAnss.push_back(iNums[iNum]);
		}
		else if ("toggle" == sOrder)
		{
			iNums[iNum] = !iNums[iNum];
		}
		else if ("all" == sOrder)
		{
			for (int j = 0; j < 21; ++j)
				iNums[j] = true;
		}
		else if ("empty" == sOrder)
		{
			for (int j = 0; j < 21; ++j)
				iNums[j] = false;
		}
	}

	for (auto iNum : iAnss)
		cout << iNum << '\n';

	return 0;
}