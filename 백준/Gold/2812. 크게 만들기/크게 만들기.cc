#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iC;
	string sNums;
	cin >> iN >> iC;
	cin >> sNums;

	vector<int> iStacks;
	iStacks.push_back(sNums[0]);
	// 1231234
	// 32
	for (int i = 1; i < sNums.size(); ++i)
	{
		while(!iStacks.empty() && iStacks.back() < sNums[i] && iC != 0)
		{
			iStacks.pop_back();
			--iC;
		}
		iStacks.push_back(sNums[i]);
	}

	
	for (int i = 0; i < iC; ++i)
	{
		iStacks.pop_back();
	}

	for (int i = 0; i < iStacks.size(); ++i)
	{
		cout << iStacks[i] - '0';
	}

	return 0;
}