#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main()
{
	int iT = 0;
	cin >> iT;

	for (int t = 0; t < iT; ++t)
	{
		int iN = 0;
		cin >> iN;
		priority_queue<int> Qs;
		list<int> Anss;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp;
			cin >> iTemp;
			Qs.push(iTemp);
		}

		bool bFlip = false;
		while (!Qs.empty())
		{
			int iNum = Qs.top();
			Qs.pop();

			if (bFlip)
			{
				Anss.push_back(iNum);
			}
			else
			{
				Anss.push_front(iNum);
			}

			bFlip = !bFlip;
		}

		vector<int> Ansss;
		for (auto iNum : Anss)
		{
			Ansss.push_back(iNum);
		}

		int iMaxDis = 0;
		for (int i = 0; i < Ansss.size(); ++i)
		{
			int iLastIndex = (i + 1) % Ansss.size();
			int iTemp = abs(Ansss[i] - Ansss[iLastIndex]);
			if (iMaxDis < iTemp)
			{
				iMaxDis = iTemp;
			}
		}

		cout << iMaxDis << endl;
	}

	

	return 0;
}