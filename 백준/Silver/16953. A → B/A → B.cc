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

	long long iN, iM;
	cin >> iN >> iM;
	
	long long iAns = 1;
	while (iN < iM)
	{
		if (iM % 10 == 1)
		{
			iM /= 10;
		}
		else
		{
			if(iM % 2 == 0)
				iM /= 2;
			else
			{
				cout << -1;
				return 0;
			}
		}

		++iAns;
	}

	if (iM == iN)
		cout << iAns;
	else
		cout << -1;

	return 0;
}