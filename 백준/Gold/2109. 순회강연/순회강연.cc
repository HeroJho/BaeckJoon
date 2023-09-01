#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include "limits.h"

using namespace std;

class Fuc
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second < R.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	vector<pair<int, int>> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		pair<int, int> Temp; cin >> Temp.second >> Temp.first;
		Inputs.push_back(Temp);
	}

	sort(Inputs.rbegin(), Inputs.rend());

	priority_queue<pair<int, int>, vector<pair<int, int>>, Fuc> Qs;

	if (iN == 0)
	{
		cout << 0;
		return 0;
	}
	int iCurDay = Inputs[0].first;
	Qs.push(Inputs[0]);
	long long iAns = 0;
	for (int i = 1; i < iN; ++i)
	{
		if (iCurDay > Inputs[i].first)
		{
			
			for (int j = iCurDay; j > Inputs[i].first; --j)
			{
				if (!Qs.empty())
				{
					iAns += Qs.top().second;
					Qs.pop();
				}
			}

			iCurDay = Inputs[i].first;

			Qs.push(Inputs[i]);
		}
		else
		{
			Qs.push(Inputs[i]);
		}

	}

	for (int i = iCurDay; i >= 1; --i)
	{
		if (!Qs.empty())
		{
			iAns += Qs.top().second;
			Qs.pop();
		}
	}

	cout << iAns;

	return 0;
}