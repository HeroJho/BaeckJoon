#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

int g_DP[1000001] = {0};

int solution(vector<int> order) {
	int answer = 0;

	stack<int> Ss;

	int iSize = order.size();
	for (int i = 0; i < iSize; ++i)
		g_DP[order[i]] = i + 1;

	int iStack = 1;
	int i = 1;
	while (true)
	{
		if (i <= iSize)
		{
			
			// 상자 순서가 맞다
			if (g_DP[i] == iStack)
			{
				++iStack;
				++i;
			}
			else // 다르다
			{
				if (Ss.empty())
				{
					Ss.push(g_DP[i]);
					++i;
				}
				else
				{
					if (iStack == Ss.top())
					{
						++iStack;
						Ss.pop();
					}
					else
					{
						Ss.push(g_DP[i]);
						++i;
					}

				}

			}

		}
		else
		{
			if (Ss.empty())
			{
				break;
			}
			else
			{
				if (iStack == Ss.top())
				{
					++iStack;
					Ss.pop();
				}
				else
				{
					break;
				}

			}
		}
		
	}

	answer = iStack - 1;

	return answer;
}