#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include "limits.h"

using namespace std;

long long g_iAns = INT_MAX;

void BFS(int storey)
{
	queue<pair<int, long long>> Qs;
	Qs.push({ storey, 0});

	while (!Qs.empty())
	{
		pair<int,int> Cur = Qs.front();
		Qs.pop();
   
		if (Cur.first < 10)
		{	
			if (Cur.first > 5)
			{
				if (g_iAns > Cur.second + 10 - Cur.first)
				{
					g_iAns = Cur.second + 10 - Cur.first + 1;
				}
			}
			else
			{
				if (g_iAns > Cur.second + Cur.first)
				{
					g_iAns = Cur.second + Cur.first;
				}
			}


			
			continue;
		}


		int iCurNum = Cur.first % 10;
		int iTemp = 10 - iCurNum;
		Qs.push({ Cur.first / 10 + 1, Cur.second + iTemp});
		Qs.push({ Cur.first / 10, Cur.second + iCurNum });

	}


}


int solution(int storey) {
    int answer = 0;

	BFS(storey);

    return g_iAns;
}
