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

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		string sS = to_string(i);
		int iADis = 0;
		bool bFirst = true;
		bool bT = true;
		for (int j = 1; j < sS.length(); ++j)
		{
			int iDis = (sS[j - 1] - '0') - (sS[j] - '0');
			if (bFirst)
			{
				iADis = iDis;
				bFirst = false;
			}
			else if (iDis != iADis)
			{
				bT = false;
				break;
			}
		}

		if (bT)
			++iAns;
	}

	cout << iAns;

	return 0;
}