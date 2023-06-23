#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int g_iN = 0;
int g_iAns = 0;

void BFS()
{
	queue<int> iQs;
	iQs.push(0);

	while (!iQs.empty())
	{
		int iCurNum = iQs.front();
		iQs.pop();

		if (iCurNum == g_iN)
		{
			++g_iAns;
			continue;
		}

		int iNextNum = 0;
		iNextNum = iCurNum + 1;
		if (iNextNum <= g_iN)
			iQs.push(iNextNum);
		iNextNum = iCurNum + 2;
		if (iNextNum <= g_iN)
			iQs.push(iNextNum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	vector<int> iNums(1001, 0);
	iNums[1] = 1;
	iNums[2] = 2;
	iNums[3] = 3;
	for (int i = 4; i <= g_iN; ++i)
	{
		iNums[i] = (iNums[i - 1] + iNums[i - 2]) % 10007;
	}

	cout << iNums[g_iN];

	return 0;
}