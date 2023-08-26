#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;

	int iOne;
	cin >> iOne;
	priority_queue<int> Qs;
	for (int i = 1; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Qs.push(iTemp);
	}

	int iAns = 0;
	while (!Qs.empty())
	{
		int iTop = Qs.top();
		Qs.pop();
		if (iOne <= iTop)
		{
			++iOne;
			--iTop;
			Qs.push(iTop);
			++iAns;
		}
		else
		{
			break;
		}
	}
	
	cout << iAns;

	return 0;
}