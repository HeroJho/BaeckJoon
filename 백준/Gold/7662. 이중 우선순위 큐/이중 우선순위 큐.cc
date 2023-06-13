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

	int iT;
	cin >> iT;
	vector<string> Anss;
	for (int t = 0; t < iT; ++t)
	{
		multiset<int> iNums;
		int iNum;
		cin >> iNum;
		for (int i = 0; i < iNum; ++i)
		{
			char cOrder;
			int iInt;
			cin >> cOrder >> iInt;
			if (cOrder == 'I')
			{
				iNums.emplace(iInt);
			}
			else
			{
				if (!iNums.empty())
				{
					if (iInt == 1)
					{
						auto iter = iNums.end();
						--iter;
						iNums.erase(iter);
					}
					else
					{
						auto iter = iNums.begin();
						iNums.erase(iter);
					}
				}
			}
		}

		if (iNums.empty())
		{
			Anss.push_back("EMPTY");
		}
		else
		{
			Anss.push_back(to_string(*(--iNums.end())));
			Anss.push_back(to_string(*iNums.begin()));
		}
	}


	for (int i = 0; i < Anss.size(); ++i)
	{
		if ("EMPTY" == Anss[i])
			cout << Anss[i] << '\n';
		else
		{
			cout << Anss[i] << ' ' << Anss[i + 1] << '\n';
			++i;
		}
	}



	return 0;
}