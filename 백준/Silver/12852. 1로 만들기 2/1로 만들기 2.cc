#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;


int N;
int DP[10000001] = { 0 };


void BFS()
{
	queue<int> Qs;
	Qs.push(N);
	DP[N] = N;

	while (!Qs.empty())
	{
		int Cur = Qs.front();
		Qs.pop();


		if (Cur % 3 == 0 && DP[Cur / 3] == 0)
		{
			DP[Cur / 3] = Cur;
			Qs.push(Cur / 3);
		}

		if (Cur % 2 == 0 && DP[Cur / 2] == 0)
		{
			DP[Cur / 2] = Cur;
			Qs.push(Cur / 2);
		}

		if (Cur - 1 > 0 && DP[Cur - 1] == 0)
		{
			DP[Cur - 1] = Cur;
			Qs.push(Cur - 1);
		}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;



	BFS();


	vector<int> Anss;
	
	int Index = 1;
	int Cnt = 0;
	while (true)
	{
		Anss.push_back(Index);


		if (Index == DP[Index])
			break;

		Index = DP[Index];


		++Cnt;
	}


	cout << Cnt << '\n';
	for (int i = Anss.size() - 1; i >=  0; --i)
	{
		cout << Anss[i] << ' ';
	}


	return 0;
}
