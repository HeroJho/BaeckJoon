#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int g_iN = 0;
vector<int> g_iLevels;

int main()
{
	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp; cin >> iTemp;
		g_iLevels.push_back(iTemp);
	}

	int iCount = 0;

	for (int i = g_iN - 1; i >= 1; --i)
	{
		int iCur = g_iLevels[i];
		int iPre = g_iLevels[i - 1];
		while (iCur <= iPre)
		{
			--iPre;
			++iCount;
		}
		g_iLevels[i - 1] = iPre;
	}

	cout << iCount;

	return 0;
}