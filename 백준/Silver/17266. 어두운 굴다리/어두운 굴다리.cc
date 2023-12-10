#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int g_iN, g_iM;
vector<int> g_Inputs;
int g_iAns = 0;

bool Check(int iH)
{
	int iMin = INT_MAX, iMax = 0;
	for (int i = 0; i < g_Inputs.size(); ++i)
	{
		int iStart = g_Inputs[i] - iH;

		if (iStart > iMax)
			return false;

		if (iMin > iStart)
			iMin = iStart;

		int iEnd = g_Inputs[i] + iH;
		if (iMax < iEnd)
			iMax = iEnd;

	}

	if (iMin <= 0 && iMax >= g_iN)
		return true;

	return false;
}

void Bin()
{
	int iLeft = 1, iRight = g_iN;

	while (iLeft <= iRight)
	{
		int iMiddle = (iLeft + iRight) / 2;

		// 채워진다
		if (Check(iMiddle))
		{
			// 갱신
			g_iAns = iMiddle;
			// 더 쫍혀본다
			iRight = iMiddle - 1;
		}
		else // 안 채워진다
		{
			// 더 높여본다
			iLeft = iMiddle + 1;
		}

	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_iN >> g_iM;

	for (int i = 0; i < g_iM; ++i)
	{
		int iTemp;
		cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}

	sort(g_Inputs.begin(), g_Inputs.end());

	Bin();

	cout << g_iAns;

	return 0;
}