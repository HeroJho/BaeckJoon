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

	string sInput;
	cin >> sInput;

	string sTemp = "";
	int iAns = 0;
	int iSum = 0;
	bool bMinus = false;
	for (int i = 0; i < sInput.length(); ++i)
	{
		sTemp += sInput[i];

		if (sInput[i] == '-')
		{
			int iNum = stoi(sTemp);
			sTemp = "";

			if (!bMinus)
			{
				iAns += iNum;
				bMinus = true;
			}
			else
			{
				iSum += iNum;
			}
		}
		else if (sInput[i] == '+')
		{
			int iNum = stoi(sTemp);
			sTemp = "";
			if (bMinus)
				iSum += iNum;
			else
				iAns += iNum;
		}
	}

	int iNum = stoi(sTemp);
	sTemp = "";
	if (bMinus)
		iSum += iNum;
	else
		iAns += iNum;

	iAns -= iSum;
	cout << iAns;


	return 0;
}