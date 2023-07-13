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

	string sInput;
	cin >> sInput;

	int iZero = 0;
	int iOne = 0;
	int iPreNum = -1;
	for (int i = 0; i < sInput.length(); ++i)
	{
		if (iPreNum == sInput[i])
		{
			continue;
		}
		else
		{
			if (sInput[i] == '0')
			{
				++iZero;
			}
			else if(sInput[i] == '1')
			{
				++iOne;
			}

			iPreNum = sInput[i];
		}
	}

	cout << min(iZero, iOne);

	return 0;
}