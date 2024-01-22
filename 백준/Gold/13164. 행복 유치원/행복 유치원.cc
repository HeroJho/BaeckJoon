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

	int N, M;
	cin >> N >> M;
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}

	vector<int> Diss;
	for (int i = 1; i < N; ++i)
	{
		int Dis = Inputs[i] - Inputs[i - 1];
		Diss.push_back(Dis);
	}

	sort(Diss.begin(), Diss.end());

	M -= 1;

	int Ans = 0;
	for (int i = 0; i < Diss.size() - M; ++i)
	{
		Ans += Diss[i];
	}

	cout << Ans;

	return 0;
}
