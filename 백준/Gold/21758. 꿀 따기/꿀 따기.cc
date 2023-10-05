#include <iostream>

using namespace std;

int g_Sums[100001] = { 0 };
int g_Inputs[100001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		cin >> g_Inputs[i];
		g_Sums[i] = g_Sums[i - 1] + g_Inputs[i];
	}


	int iAns = 0;
	// 벌 통 벌
	for (int i = 2; i < iN; ++i)
	{
		int iTemp = (g_Sums[i] - g_Sums[1]) + (g_Sums[iN - 1] - g_Sums[i - 1]);
		iAns = max(iAns, iTemp);
	}

	// 벌 벌 통
	for (int i = 2; i < iN; ++i)
	{
		int iTemp = (g_Sums[iN] - g_Sums[1] - g_Inputs[i]) + (g_Sums[iN] - g_Sums[i]);
		iAns = max(iAns, iTemp);
	}

	// 통 벌 벌
	for (int i = 2; i < iN; ++i)
	{
		int iTemp = (g_Sums[iN - 1] - g_Inputs[i]) + g_Sums[i - 1];
		iAns = max(iAns, iTemp);
	}


	cout << iAns;

	return 0;
}