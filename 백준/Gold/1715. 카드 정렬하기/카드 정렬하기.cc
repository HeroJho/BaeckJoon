#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Fuc
{
public:
	bool operator()(int iL, int iR)
	{
		return iL > iR;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	priority_queue<int, vector<int>, Fuc> iNums;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iNums.push(iTemp);
	}

	if (iN == 1)
	{
		cout << 0;
		return 0;
	}


	int iSumNum = 0;
	while (true)
	{
		// 제일 작은애 2개를 뽑고 더한다.
		int iTemp1 = iNums.top();
		iNums.pop();
		int iTemp2 = iNums.top();
		iNums.pop();
		iSumNum += iTemp1 + iTemp2;

		if (iNums.empty())
		{
			break;
		}

		iNums.push(iTemp1 + iTemp2);
	}

	cout << iSumNum;

	return 0;
}