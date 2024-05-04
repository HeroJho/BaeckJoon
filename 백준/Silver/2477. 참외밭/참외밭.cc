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

	// 1동 2서 3남 4북

	// 작 큰

	// 3개 꺼내서 교차되는 변 찾기
	// 교차하고 같은 방향
	int N;
	cin >> N;
	vector<pair<int, int>> Inputs;
	int CrossCnt[6] = { 0 };
	for (int i = 0; i < 6; ++i)
	{
		pair<int, int> Temp;
		cin >> Temp.first >> Temp.second;
		Inputs.push_back(Temp);
	}


	vector<int> Max;
	for (int i = 0; i < 6; ++i)
	{
		int One1 = i;
		int Two1 = (i + 1) % 6;
		int Three1 = (i + 2) % 6;

		if (Inputs[One1].first != Inputs[Two1].first &&
			Inputs[One1].first == Inputs[Three1].first)
		{
			CrossCnt[One1]++;
			CrossCnt[Two1]++;
			CrossCnt[Three1]++;
			
			// 2
			if (Inputs[One1].first == 1)
			{
				for (int z = 0; z < 6; ++z)
				{
					if(Inputs[z].first == 2)
						Max.push_back(z);
				}

			}
			else if (Inputs[One1].first == 2)
			{
				for (int z = 0; z < 6; ++z)
				{
					if (Inputs[z].first == 1)
						Max.push_back(z);
				}
			}
			else if (Inputs[One1].first == 3)
			{
				for (int z = 0; z < 6; ++z)
				{
					if (Inputs[z].first == 4)
						Max.push_back(z);
				}

			}
			else if (Inputs[One1].first == 4)
			{
				for (int z = 0; z < 6; ++z)
				{
					if (Inputs[z].first == 3)
						Max.push_back(z);
				}
			}

		}

	}


	int DeMax = Inputs[Max[0]].second * Inputs[Max[1]].second;
	// 2개
	vector<int> Cr;
	for (int i = 0; i < 6; ++i)
	{
		if (CrossCnt[i] == 2)
		{
			Cr.push_back(i);
		}
	}

	int De = Inputs[Cr[0]].second * Inputs[Cr[1]].second;



	int Total = DeMax - De;
	int Ans = Total * N;

	cout << Ans;

	return 0;
}
