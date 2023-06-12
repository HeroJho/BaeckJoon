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

	int iT;
	cin >> iT;

	vector<int> iAnss;
	for (int t = 0; t < iT; ++t)
	{
		int iM, iN, iX, iY;
		cin >> iM >> iN >> iX >> iY;

		int iAnsMinX, iAnsMinY;
		if (iX < iY)
		{
			iAnsMinX = 1;
			iAnsMinY = iY - iX + 1;
		}
		else
		{
			iAnsMinX = iX - iY + 1;
			iAnsMinY = 1;
		}

		//int iEndX, iEndY;
		//if (iX < iY)
		//{
		//	iEndX = 1;
		//	iEndY = iY - iX + 1;
		//}
		//else
		//{
		//	iEndX = iX - iY + 1;
		//	iEndY = 1;
		//}


		bool bEnd = false;
		int iAnsCount = 0;
		int iTempMinX = 1, iTempMinY = 1;
		while (true)
		{
			int iTempX = abs(iM - iTempMinX);
			int iTempY = abs(iN - iTempMinY);

			// 정답
			if (iAnsMinX == iTempMinX && iAnsMinY == iTempMinY)
			{
				break;
			}

			if (iTempX == iTempY) // 멸망해
			{
				bEnd = true;
				break;
			}


			if (iTempX < iTempY)
			{
				iTempMinX = 1;
				iTempMinY += iTempX + 1;

				iAnsCount += iTempX + 1;
			}
			else if (iTempX > iTempY)
			{
				iTempMinX += iTempY + 1;
				iTempMinY = 1;

				iAnsCount += iTempY + 1;
			}

		}
		

		if(bEnd)
			iAnss.push_back(-1);
		else
		{
			while (iAnsMinX != iX)
			{
				++iAnsMinX;
				++iAnsCount;
			}

			iAnss.push_back(iAnsCount + 1);
		}

	}


	for (auto iNum : iAnss)
		cout << iNum << '\n';


	return 0;
}