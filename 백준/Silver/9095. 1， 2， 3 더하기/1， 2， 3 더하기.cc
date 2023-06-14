#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;



void DFS(int iCount, int iStopValue, int& Out_iAns)
{
	if (iStopValue == iCount)
	{
		++Out_iAns;
		return;
	}
	else if (iStopValue < iCount)
		return;

	DFS(iCount + 1, iStopValue, Out_iAns);
	DFS(iCount + 2, iStopValue, Out_iAns);
	DFS(iCount + 3, iStopValue, Out_iAns);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;

	vector<int> iAnss;

	for (int i = 0; i < iT; ++i)
	{
		int iN; cin >> iN;
		int iAns = 0;
		DFS(0, iN, iAns);
		iAnss.push_back(iAns);
	}

	for (auto iNum : iAnss)
	{
		cout << iNum << '\n';
	}

	return 0;
}