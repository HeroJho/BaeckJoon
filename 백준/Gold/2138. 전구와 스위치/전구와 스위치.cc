#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void Flip(int iIndex, string& sTemp)
{
	if (iIndex - 1 >= 0)
	{
		if (sTemp[iIndex-1] == '0')
			sTemp[iIndex-1] = '1';
		else
			sTemp[iIndex-1] = '0';
	}

	if (iIndex + 1 < sTemp.size())
	{
		if (sTemp[iIndex+1] == '0')
			sTemp[iIndex+1] = '1';
		else
			sTemp[iIndex+1] = '0';
	}

	if (sTemp[iIndex] == '0')
		sTemp[iIndex] = '1';
	else
		sTemp[iIndex] = '0';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	string sInput;
	string sDest;
	cin >> sInput;
	cin >> sDest;

	string sTemp = sInput;

	int iAns = 0;
	// 첫 전구를 안 누른 상태
	for (int i = 1; i < iN; ++i)
	{
		if (sDest[i - 1] != sTemp[i - 1])
		{
			Flip(i, sTemp);
			++iAns;
		}

		if (sDest == sTemp)
		{
			cout << iAns;
			return 0;
		}
	}


	sTemp = sInput;
	iAns = 1;
	// 첫 전구를 누른 상태
	Flip(0, sTemp);
	for (int i = 1; i < iN; ++i)
	{
		if (sDest[i - 1] != sTemp[i - 1])
		{
			Flip(i, sTemp);
			++iAns;
		}

		if (sDest == sTemp)
		{
			cout << iAns;
			return 0;
		}
	}

	cout << -1;


	return 0;
}