#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"


using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// i 보다 i-1 크면 i를 뺀다
	

	int N, K;
	cin >> N >> K;
	string sS;
	cin >> sS;

	string Stack;
	for (int i = 0; i < N; ++i)
	{
		if (K <= 0)
		{
			Stack.push_back(sS[i]);
			continue;
		}

		int CurNum = sS[i] - '0';

		while (!Stack.empty())
		{
			int TopNum = Stack.back() - '0';
			if (TopNum < CurNum)
			{
				Stack.pop_back();
				K--;
				if (K <= 0)
					break;

				continue;
			}

			break;
		}

		Stack.push_back(CurNum + '0');
	}

	// 끝났는데 더 빼야하면?  뒤에서 나머지 뺀다
	for (int i = 0; i < K; ++i)
	{
		Stack.pop_back();
	}

	cout << Stack;

	return 0;
}
