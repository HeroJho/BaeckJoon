#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN = 0;
vector<long long> g_Inputs[4];
long long g_iCount = 0;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_iN;

	for (int i = 0; i < g_iN; ++i) 
	{
		for (int k = 0; k < 4; ++k)
		{
			long long iTemp;
			cin >> iTemp;
			g_Inputs[k].push_back(iTemp);
			
		}
	}

	vector<long long> ASum, BSum;
	for (int i = 0; i < g_iN; ++i)
	{
		for (int k = 0; k < g_iN; ++k)
		{
			ASum.push_back(g_Inputs[0][i] + g_Inputs[1][k]);
			BSum.push_back(g_Inputs[2][i] + g_Inputs[3][k]);
		}
	}

	sort(ASum.begin(), ASum.end());
	sort(BSum.begin(), BSum.end());
	
	long long Left = 0, Right = BSum.size() - 1;
	while (Left < ASum.size() && Right >= 0)
	{

		long long iSum = ASum[Left] + BSum[Right];
		if (iSum == 0)
		{
			long long iTempIndex = Left + 1;
			long long iAcnt = 1;
			while (iTempIndex < ASum.size() && ASum[Left] == ASum[iTempIndex])
			{
				++iAcnt;
				++iTempIndex;
			}
			Left = iTempIndex;

			iTempIndex = Right - 1;
			long long iBcnt = 1;
			while (iTempIndex >= 0 && BSum[Right] == BSum[iTempIndex])
			{
				++iBcnt;
				--iTempIndex;
			}
			// Right = iTempIndex;

			g_iCount += iAcnt * iBcnt;

		}
		else if (iSum > 0) 
		{
			--Right;
		}
		else if (iSum < 0)
		{
			++Left;
		}

	}

	cout << g_iCount;

	return 0;

}