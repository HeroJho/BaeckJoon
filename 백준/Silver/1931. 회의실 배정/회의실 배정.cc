#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct TimeData
{
	int iStart = 0;
	int iEnd = 0;
};

class Fuc
{
public:
	bool operator()(TimeData L, TimeData R)
	{
		return L.iEnd < R.iEnd;
	}
};

class Fuc1
{
public:
	bool operator()(TimeData L, TimeData R)
	{
		return L.iStart < R.iStart;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	
	vector<TimeData> TimeDatas;
	for (int i = 0; i < iN; ++i)
	{
		TimeData Data;
		cin >> Data.iStart;
		cin >> Data.iEnd;
		TimeDatas.push_back(Data);
	}

	sort(TimeDatas.begin(), TimeDatas.end(), Fuc1());
	stable_sort(TimeDatas.begin(), TimeDatas.end(), Fuc());

	int iCount = 1;
	int iMaxEnd = 0;
	TimeData Cur = TimeDatas[0];
	iMaxEnd = Cur.iEnd;


	for (int i = 1; i < TimeDatas.size(); ++i)
	{
		Cur = TimeDatas[i];
		if (iMaxEnd <= Cur.iStart)
		{
			++iCount;
			iMaxEnd = Cur.iEnd;
		}
	}

	cout << iCount;

	return 0;
}