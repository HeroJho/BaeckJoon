#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int iN, iSen;
	cin >> iN >> iSen;
	vector<int> Poss;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Poss.push_back(iTemp);
	}
	if (iN <= iSen)
	{
		cout << 0;
		return 0;
	}

	sort(Poss.begin(), Poss.end());

	vector<int> Diss;
	vector<int> TempDiss;
	multiset<int> MaxDis;

	Diss.push_back(0);
	for (int i = 0; i < iN - 1; ++i)
	{
		Diss.push_back(Poss[i + 1] - Poss[i]);
		TempDiss.push_back(Poss[i + 1] - Poss[i]);
	}

	sort(TempDiss.rbegin(), TempDiss.rend());
	// iSen - 1 개의 내림차순 Dis를 구한다.
	for (int i = 0; i < iSen - 1; ++i)
	{
		MaxDis.emplace(TempDiss[i]);
	}

	int iAns = 0;
	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		// 찾았다면
		auto iter = MaxDis.find(Diss[i]);
		if (iter != MaxDis.end())
		{
			MaxDis.erase(iter);
			iAns += iSum;
			iSum = 0;
		}
		else
		{
			iSum += Diss[i];
		}

	}

	iAns += iSum;

	cout << iAns;

	return 0;
}