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

	int iN, iM;
	string sS;
	cin >> iN >> iM;
	cin >> sS;

	// 1 = 3, 2 = 5, 3 = 7
	// 1010101
	// N = iN + iN + 1
	iN = iN + iN + 1;

	int iCount = 0;
	for (int i = 0; i < iM - iN + 1; ++i)
	{
		int iStartIndex, iEndIndex;
		iStartIndex = i;
		iEndIndex = i + iN - 1;

		if (sS[iStartIndex] != 'I')
			continue;

		char cCur = 'I';
		bool bIs = true;
		while (iStartIndex <= iEndIndex)
		{
			if (cCur == sS[iStartIndex] && cCur == sS[iEndIndex])
			{
				if (cCur == 'I')
					cCur = 'O';
				else
					cCur = 'I';

				++iStartIndex;
				--iEndIndex;

				continue;
			}

			bIs = false;
			break;
		}

		if (bIs)
			++iCount;
	}

	cout << iCount;


	return 0;
}