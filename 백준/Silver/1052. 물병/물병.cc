#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iAns = 0;

	while (true)
	{

		stack<int> Ss;
		int iNum = 1;
		int inNum = 1;
		int iTempN = iN;
		while (iTempN > 0)
		{
			if (iTempN < inNum)
			{
				Ss.push(iNum);
				iTempN -= iNum;

				iNum = 1;
				inNum = 1;
				continue;
			}
			else
				iNum = inNum;

			inNum = iNum * 2;
		}

		if (Ss.size() <= iM)
		{
			cout << iAns;
			return 0;
		}
		else
		{
			iAns += Ss.top();
			iN += Ss.top();
		}

	}



	return 0;
}