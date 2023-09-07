#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

bool g_DP[10001] = { false };

void DFS(int iNum)
{
	if (iNum * iNum > 10000)
		return;

	if (g_DP[iNum * iNum])
		return;

	g_DP[iNum * iNum] = true;
	DFS(iNum * iNum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	
	for (int i = 0; i < 10001; ++i)
	{
		DFS(i);
	}

	int iMin = 0;
	int iSum = 0;
	for (int i = iN; i <= iM; ++i)
	{
		if (g_DP[i])
		{
			if (!iMin)
				iMin = i;

			iSum += i;
		}
			
	}

	if (iMin)
	{
		cout << iSum << '\n';
		cout << iMin << '\n';
	}
	else
		cout << -1;


	return 0;
}