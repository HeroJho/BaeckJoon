#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_Matrix[500][500] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iAnsHeight = INT_MAX, iAnsTime = INT_MAX;

	int iN, iM, iB;
	cin >> iN >> iM >> iB;
	

	for (int y = 0; y < iN; ++y)
		for (int x = 0; x < iM; ++x)
			cin >> g_Matrix[y][x];

	// 높이를 h로 평평하게 만들려고할 때
	for (int h = 0; h <= 256; ++h)
	{
		// 쌓을 개수와 지울 개수를 구한다
		int iUpCount = 0;
		int iDownCount = 0;
		for (int y = 0; y < iN; ++y)
		{
			for (int x = 0; x < iM; ++x)
			{
				int iDis = h - g_Matrix[y][x];
				if (iDis < 0)
				{// 더 높다
					iDownCount -= iDis;
				}
				else
				{// 더 낮다
					iUpCount += iDis;
				}
			}
		}
			
		// 인벤 블럭 개수가 쌓아야할 블럭 개수보다 많을 때만 체크
		if (iB + iDownCount >= iUpCount)
		{
			int iTime = iDownCount * 2 + iUpCount;
			if (iTime <= iAnsTime)
			{
				iAnsTime = iTime;
				iAnsHeight = h;
			}
		}

	}

	cout << iAnsTime << ' ' << iAnsHeight;


	return 0;
}