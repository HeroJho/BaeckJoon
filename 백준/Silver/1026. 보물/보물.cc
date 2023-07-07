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

	vector<int> iAs;
	vector<int> iBs;

	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iAs.push_back(iTemp);
	}
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iBs.push_back(iTemp);
	}

	sort(iAs.begin(), iAs.end());
	sort(iBs.rbegin(), iBs.rend());

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		iAns += iAs[i] * iBs[i];
	}
	
	cout << iAns;


	return 0;
}