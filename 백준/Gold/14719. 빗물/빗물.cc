#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> Inputs;
	for (int i = 0; i < M; ++i)
	{
		int iTemp;
		cin >> iTemp;
		Inputs.push_back(iTemp);
	}


	int iAns = 0;
	for (int i = 0; i < M; ++i)
	{
		int iStartIndex = i;

		// 제일 큰 값
		int Left = iStartIndex - 1;
		int LeftIndex = iStartIndex, Max = Inputs[iStartIndex];
		while (Left >= 0)
		{
			if (Max < Inputs[Left])
			{
				LeftIndex = Left;
				Max = Inputs[Left];
			}
			--Left;
		}

		int Right = iStartIndex + 1;
		int RightIndex = iStartIndex;
		Max = Inputs[iStartIndex];
		while (Right < M)
		{
			if (Max < Inputs[Right])
			{
				RightIndex = Right;
				Max = Inputs[Right];
			}
			++Right;
		}

		if (Inputs[RightIndex] > Inputs[LeftIndex])
		{
			iAns += Inputs[LeftIndex] - Inputs[iStartIndex];
		}
		else
		{
			iAns += Inputs[RightIndex] - Inputs[iStartIndex];
		}
		
	}

	cout << iAns;

	return 0;
}