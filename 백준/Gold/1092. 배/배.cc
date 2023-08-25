#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main()
{
	int iN, iM;
	vector<int> Crains;
	list<int> Boxs;

	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Crains.push_back(iTemp);
	}

	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Boxs.push_back(iTemp);
	}



	sort(Crains.rbegin(), Crains.rend());
	Boxs.sort();
	Boxs.reverse();

	if (Crains.front() < Boxs.front())
	{
		cout << -1;
		return 0;
	}


	int iAns = 0;
	while (!Boxs.empty())
	{
		for (int i = 0; i < Crains.size(); ++i)
		{
			bool bIsNoSkip = false;
			for (list<int>::iterator iter = Boxs.begin(); iter != Boxs.end();)
			{
				if (Crains[i] >= *iter)
				{
					iter = Boxs.erase(iter);
					bIsNoSkip = true;
					break;
				}
				else
					++iter;

			}

			if (!bIsNoSkip)
				break;

		}

		++iAns;
	}

	cout << iAns;

	return 0;
}