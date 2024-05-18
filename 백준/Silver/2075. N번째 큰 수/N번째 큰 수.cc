#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

class Func
{
public:
	bool operator()(int L, int R)
	{
		return L > R;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int N;
	cin >> N;
	
	priority_queue<int, vector<int>, Func> Qs;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Temp;
			cin >> Temp;

			if (i == 0)
			{
				Qs.push(Temp);
			}
			else
			{
				Qs.push(Temp);
				Qs.pop();
			}

		}
	}

	/*for (int i = 1; i < N; ++i)
	{
		Qs.pop();
	}*/

	cout << Qs.top();

	return 0;
}
