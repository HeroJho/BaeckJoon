#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int Run(char Check, int N, string S)
{
	int Left = 0, Right = S.size() - 1;
	
	while (Right >= 0 && S[Right] == Check)
	{
		// Right 찾기
		// Left 찾기
		--Right;
		if (Right < 0)
			return 0;
	}
	// RB
	int iCount = 0;

	Left = Right - 1;
	while (Left >= 0)
	{
		if (S[Left] == Check)
		{
			--Right;
			++iCount;
		}

		--Left;
	}

	return iCount;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	string S;
	cin >> S;

	int iAns = 0;
	iAns = Run('R', N, S);
	iAns = min(iAns, Run('B', N, S));
	reverse(S.begin(), S.end());
	iAns = min(iAns, Run('R', N, S));
	iAns = min(iAns, Run('B', N, S));

	cout << iAns;

	return 0;
}