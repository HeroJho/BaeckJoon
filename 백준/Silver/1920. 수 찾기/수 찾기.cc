#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int g_iN, g_iM;
vector<int> g_iNs;
vector<int> g_iMs;

bool isIn(int iValue)
{
	int iLeft = 0;
	int iRight = g_iNs.size() - 1;
	int iMid = 0;
	while (iLeft <= iRight)
	{
		iMid = (iLeft + iRight) / 2;

		if (g_iNs[iMid] == iValue)
			return true;
		else if (g_iNs[iMid] < iValue)
		{
			iLeft = iMid + 1;
		}
		else if (g_iNs[iMid] > iValue)
		{
			iRight = iMid - 1;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp; cin >> iTemp;
		g_iNs.push_back(iTemp);
	}
	cin >> g_iM;
	for (int i = 0; i < g_iM; ++i)
	{
		int iTemp; cin >> iTemp;
		g_iMs.push_back(iTemp);
	}

	
	sort(g_iNs.begin(), g_iNs.end());

	for (int i = 0; i < g_iM; ++i)
	{
		if (isIn(g_iMs[i]))
		{
			cout << '1' << '\n';
		}
		else
		{
			cout << '0' << '\n';
		}
	}


	return 0;
}