#include <string>
#include <vector>

#include <algorithm>
#include "limits.h"

using namespace std;

int BinCheck(int iStart, const vector<int>& weights)
{

	int iLeft = iStart + 1, iRight = weights.size() - 1;
	int iMiddle = 0;
	while (iLeft <= iRight)
	{
		iMiddle = (iLeft + iRight) / 2;

		int iIMax = weights[iStart] * 4; // 180 * 4 = 720
		int iJMax = weights[iMiddle] * 2; // 720
		if (iIMax < iJMax)
		{
			iRight = iMiddle - 1;
			continue;
		}

		iIMax = weights[iStart] * 2;
		iJMax = weights[iMiddle] * 4;
		if (iIMax > iJMax)
		{
			iLeft = iMiddle + 1;
			continue;
		}

		break;
	}


	int iCount = 0;
	
	for (int j = iLeft; j <= iRight; ++j)
	{

		bool bT = false;
		for (int k = 2; k <= 4; ++k)
		{
			for (int z = 2; z <= 4; ++z)
			{
				if (weights[iStart] * k == weights[j] * z)
				{
					++iCount;
					bT = true;
					break;
				}
				if (bT)
					break;
			}

		}

	}

	

	return iCount;
}

long long solution(vector<int> weights) {
	long long answer = 0;

	sort(weights.begin(), weights.end());

	// 100 100 180 270 360 


	for (int i = 0; i < weights.size(); ++i)
	{
		answer += BinCheck(i, weights);
	}


	return answer;
}
