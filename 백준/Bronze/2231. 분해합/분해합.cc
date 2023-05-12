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

	// 256 = 245+2+4+5 = 245
	int iNum;
	cin >> iNum;

	for (int i = 1; i <= iNum; ++i)
	{
		int iTemp = 0;
		string sNum = to_string(i);
		iTemp += i;
		for (int j = 0; j < sNum.length(); ++j)
		{
			iTemp += sNum[j] - '0';
		}

		if (iNum == iTemp)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;

	return 0;
}