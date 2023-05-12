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

	int iN; cin >> iN;

	list<int> iNums;
	for (int i = 1; i <= iN; ++i)
	{
		iNums.push_back(i);
	}

	// 위의 카드를 버린다.
	// 위의 카드를 맨 뒤로 보낸다.

	while (true)
	{
		int iAnsTemp = iNums.front();
		iNums.pop_front();

		if (iNums.empty())
		{
			cout << iAnsTemp;
			break;
		}


		int iTemp = iNums.front();
		iNums.pop_front();
		iNums.push_back(iTemp);
	}


	return 0;
}