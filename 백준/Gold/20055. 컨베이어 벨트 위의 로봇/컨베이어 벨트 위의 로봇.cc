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

	// 200 *400
	int N, K;
	cin >> N >> K;
	vector<int> Inputs;
	for (int i = 0; i < N*2; ++i)
	{
		int iTemp; cin >> iTemp;
		Inputs.push_back(iTemp);
	}

	int iAns = 0;

	vector<int> Ba(N, 0);
	while (true)
	{
		// 회전한다
		int RTemp = Inputs[2 * N - 1];
		for (int i = 2 * N - 2; i >= 0; --i)
		{
			if(i < N-1)
				Ba[i + 1] = Ba[i];
			Inputs[i + 1] = Inputs[i];
		}
		Inputs[0] = RTemp;
		Ba[0] = 0;

		Ba[N - 1] = 0;


		for (int i = N-2; i >= 0; --i)
		{
			int iIndex = i;
			int iNexIndex = i + 1;
			// 현재 로봇이 있고
			if (Ba[iIndex] == 0)
				continue;
			// 다음 로봇이 없고
			if (Ba[iNexIndex] != 0)
				continue;
			// 벨트 칸 남아있는지
			if (Inputs[iNexIndex] <= 0)
				continue;
			
			Inputs[iNexIndex]--;
			Ba[iNexIndex] = Ba[iIndex];
			Ba[iIndex] = 0;
		}


		// 로봇을 올린다
		if (Inputs[0] > 0 && Ba[0] == 0)
		{
			Ba[0] = 1;
			--Inputs[0];
		}

		++iAns;

		// 내구도를 체크한다
		int iCount = 0;
		for (int i = 0; i < 2*N; ++i)
		{
			if (Inputs[i] == 0)
			{
				++iCount;
			}
		}

		if (iCount >= K)
			break;

	}

	cout << iAns;

	return 0;
}