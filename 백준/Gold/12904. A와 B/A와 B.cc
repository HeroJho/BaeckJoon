#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string sS, sT;
	cin >> sS >> sT;

	bool bAns = false;
	while (true)
	{
		if (sS.length() == sT.length())
		{
			bAns = sS == sT;
			break;
		}

		if (sT[sT.length() - 1] == 'A')
			sT.pop_back();
		else
		{
			sT.pop_back();
			reverse(sT.begin(), sT.end());
		}
	}

	cout << bAns;

	return 0;
}