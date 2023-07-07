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

	int iN;
	cin >> iN;

	vector<int> iDis;
	vector<int> iM;

	for (int i = 0; i < iN - 1; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iDis.push_back(iTemp);
	}
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iM.push_back(iTemp);
	}

	int iAns = iM[0] * iDis[0];
	int iCurMaxM = iM[0];
	for (int i = 1; i < iN - 1; ++i)
	{
		if (iCurMaxM > iM[i])
		{
			iCurMaxM = iM[i];
		}
		
		iAns += iCurMaxM * iDis[i];
	}

	cout << iAns;

	return 0;
}