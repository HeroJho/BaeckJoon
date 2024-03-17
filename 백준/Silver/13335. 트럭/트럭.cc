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

	// 트럭 수, 다리 길이, 다리 무게
	int N, L, W;
	cin >> N >> L >> W;
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}


	queue<pair<int ,int>> Qs;
	
	int CurTime = 0;
	int CurW = W;
	int TruckIndex = 0;
	while (true)
	{
		++CurTime;

		// front를 확인한다.
		// 시간 차가 M 이상
		//	트럭을 뺀다
		//	뺄 때 무게를 다시 더해준다.
		if (!Qs.empty())
		{
			pair<int, int> FrontTruck = Qs.front();
			int DisTime = CurTime - FrontTruck.second;
			if (DisTime >= L)
			{
				Qs.pop();
				CurW += FrontTruck.first;
			}
		}
		

		if (TruckIndex < N)
		{
			int TruckW = Inputs[TruckIndex];

			// 다리 하중을 확인한다
			// 올라갈 수 있다
			// 현재 무게를 뺀다
			// 큐에 넣는다
			// 인덱스를 늘린다
			if (CurW >= TruckW)
			{
				CurW -= TruckW;
				Qs.push({ TruckW ,CurTime });
				TruckIndex++;
			}
		}

		if (Qs.empty())
			break;
	}

	cout << CurTime;

	return 0;
}
