#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R) {
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
		pair<int, int> Temp;
		cin >> Temp.first >> Temp.second;
		Inputs.push_back(Temp);
	}

	sort(Inputs.rbegin(), Inputs.rend());


	priority_queue<pair<int, int>, vector<pair<int, int>>, Func> Qs;
	int iMaxDay = Inputs[0].first;
	Qs.push(Inputs[0]);
	long long iAns = 0;

	for (int i = 1; i < iN; ++i)
	{
		if (iMaxDay > Inputs[i].first)
		{
			for (int j = 0; j < iMaxDay - Inputs[i].first; ++j)
			{
				if (Qs.empty())
					break;

				iAns += Qs.top().second;
				Qs.pop();
			}

			iMaxDay = Inputs[i].first;
		}

		Qs.push(Inputs[i]);
	}


	for (int j = iMaxDay; j >= 1; --j)
	{
		if (Qs.empty())
			break;

		iAns += Qs.top().second;
		Qs.pop();
	}

	cout << iAns;

	return 0;
}