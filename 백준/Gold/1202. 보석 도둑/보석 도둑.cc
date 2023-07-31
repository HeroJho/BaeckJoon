#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Fuc
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.first < R.first;
	}
};

class Fuc1
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second < R.second;
	}
};

int main()
{
	int iN = 0, iK = 0;
	cin >> iN >> iK;

	list<pair<int, int>> Jus;
	for (int i = 0; i < iN; ++i)
	{
		pair<int, int> Ju;		// 무게, 돈
		cin >> Ju.first >> Ju.second;
		Jus.push_back(Ju);
	}
	vector<int> Back(iK);
	for (int i = 0; i < iK; ++i)
	{
		cin >> Back[i];
	}

	Jus.sort(Fuc());
	sort(Back.begin(), Back.end());
	
	long long iAns = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Fuc1> Qs;
	for (int i = 0; i < iK; ++i)
	{
		while (!Jus.empty() && Back[i] >= Jus.front().first)
		{
			Qs.push(Jus.front());
			Jus.pop_front();
		}

		if (!Qs.empty())
		{
			iAns +=	Qs.top().second;
			Qs.pop();
		}
	}

	cout << iAns;

	return 0;
}