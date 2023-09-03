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

	int iN, iM, iS;
	cin >> iN >> iM >> iS;

	int iAns = 1;
	int inN = 0, inM = 0, inS = 0;
	while (true)
	{
		if (inN + 1 == iN && inM + 1 == iM && inS + 1 == iS)
		{
			cout << iAns;
			break;
		}

		++iAns;

		++inN;
		++inM;
		++inS;

		inN %= 15;
		inM %= 28;
		inS %= 19;

	}


	return 0;
}