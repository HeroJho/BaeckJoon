#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <list>
#include "limits.h"

using namespace std;

list<int> g_Temps;

int Push(int Cur)
{
	bool bB = false;
	int Count = -1;
	for (auto iter = g_Temps.begin(); iter != g_Temps.end();)
	{
		if (bB)
			++Count;

		if (!bB && Cur < *iter)
		{
			iter = g_Temps.insert(iter, Cur);
			bB = true;
		}
		else
			++iter;

	}

	if (!bB)
		g_Temps.push_back(Cur);

	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;


	while (T--)
	{
		g_Temps.clear();
		
		int Case;
		cin >> Case;
		
		vector<int> Inputs;
		for (int i = 0; i < 20; ++i)
		{
			int Temp; cin >> Temp;
			Inputs.push_back(Temp);
		}

		int Ans = 0;
		for (int i = 0; i < 20; ++i)
		{
			int Cur = Inputs[i];

			int Count = Push(Cur);
			if (Count != -1)
				Ans += Count;

		}

		cout << Case << " " <<  Ans << endl;
	}
	


	return 0;
}
