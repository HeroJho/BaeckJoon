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

	int iN; string sS;
	cin >> iN >> sS;

	// LL 처음만 2개로 친다.
	int iAnsCount = 0;
	bool bIsFirstLL = true;
	for (int i = 0; i < iN;)
	{
		if (sS[i] == 'S')
		{	
			++iAnsCount;

			++i;
		}
		else
		{
			if (bIsFirstLL)
			{
				iAnsCount += 2;
				bIsFirstLL = false;
			}
			else
				++iAnsCount;

			i += 2;
		}

	}

	cout << iAnsCount;

	return 0;
}