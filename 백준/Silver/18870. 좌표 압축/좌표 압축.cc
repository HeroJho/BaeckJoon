#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

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
	vector<int> iNums;
	priority_queue<int, vector<int>, Fuc> iQs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iNums.push_back(iTemp);
		iQs.push(iTemp);
	}

	map<int, int> iTables;
	int iCount = 0;
	while (!iQs.empty())
	{
		int iNum = iQs.top();
		iQs.pop();

		if (iTables.find(iNum) == iTables.end())
		{
			iTables[iNum] = iCount;
			++iCount;
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		iNums[i] = iTables[iNums[i]];
	}

	for (auto iNum : iNums)
	{
		cout << iNum << ' ';
	}

	return 0;
}