#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define MAX 100001

using namespace std;

//void Reset()
//{
//	for (int i = 1; i <= g_N; ++i)
//	{
//		g_Inputs[i] = 0;
//		g_Check[i] = 0;
//	}
//}
//void ResetVisited()
//{
//	for (int i = 1; i <= g_N; ++i)
//	{
//		g_Visited[i] = false;
//	}
//}

void Pro()
{
	int N;
	cin >> N;
	vector<int> Inputs;
	Inputs.push_back(0);
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}


	vector<int> Check(N + 1, false);
	
	for (int i = 1; i <= N; ++i)
	{
		if (Check[i] != 0)
			continue;

		// 자신 바로 끝
		if (i == Inputs[i])
		{
			Check[i] = 1;
			continue;
		}


		vector<bool> Visited(N + 1, false);
		vector<int> Teams;

		int Nex = i;
		Visited[Nex] = true;
		Teams.push_back(Nex);

		while (true)
		{
			Nex = Inputs[Nex];
			// 거쳐서 아닌거 확정된 -1, 서클 1
			if (Check[Nex] != 0)
			{
				for (int i = 0; i < Teams.size(); ++i)
				{
					Check[Teams[i]] = -1;
				}
				break;
			}


			// 서클 완성 = 전부 1
			if (i == Nex)
			{
				for (int i = 0; i < Teams.size(); ++i)
				{
					Check[Teams[i]] = 1;
				}

				break;
			}

			// 거친 노드 도착
			if (Visited[Nex])
			{
				// 거친 노드 이후로는 Check = 1;
				// 이전은 Check - 1
				bool bF = false;
				for (int i = 0; i < Teams.size(); ++i)
				{
					if (Nex == Teams[i])
						bF = true;

					if(!bF)
						Check[Teams[i]] = -1;
					else
						Check[Teams[i]] = 1;
				}

				break;
			}
				

			Visited[Nex] = true;
			Teams.push_back(Nex);
		}

		
	}

	int Ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Check[i] != 1)
			++Ans;
	}

	cout << Ans << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int T;
	cin >> T;

	while (T--)
	{
		Pro();
	}



	return 0;
}
