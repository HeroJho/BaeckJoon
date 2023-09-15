#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Data
{
	pair<int, int> Start, End;
};

struct Comp1
{
	bool operator() (Data L, Data R)
	{
		if (L.Start.first != R.Start.first)
		{
			return L.Start.first < R.Start.first;
		}
		else
		{
			return L.Start.second < R.Start.second;
		}
			
	}
};
struct Comp2
{
	bool operator() (Data L, Data R)
	{
		if (L.Start.first == R.Start.first &&
			L.Start.second == R.Start.second)
		{
			if (L.End.first != R.End.first)
			{
				return L.End.first < R.End.first;
			}
			else
			{
				return L.End.second < R.End.second;
			}
		}

		return false;
	}
};

bool Comp_Day(pair<int, int> L, pair<int, int> R)
{
	if (L.first != R.first)
	{
		return L.first > R.first;
	}
	else
	{
		return L.second > R.second;
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int iN;
	cin >> iN;
	vector<Data> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		Data Temp; 
		cin >> Temp.Start.first >> Temp.Start.second;
		cin >> Temp.End.first >> Temp.End.second;
		Inputs.push_back(Temp);
	}

	sort(Inputs.begin(), Inputs.end(), Comp1());
	// sort(Inputs.begin(), Inputs.end(), Comp2());

	int iAns = 0;

	pair<int, int> EndMax, TempEndMax;
	EndMax.first = 3;
	EndMax.second = 1;

	TempEndMax.first = 0;
	TempEndMax.second = 0;

	for (int i = 0; i < iN; ++i)
	{

		if (Comp_Day(Inputs[i].Start, EndMax))
		{
			++iAns;
			EndMax = TempEndMax;

			// EndMax가 11월 30일을 넘었냐
			if (Comp_Day(EndMax, make_pair(11, 30)))
			{
				cout << iAns;
				return 0;
			}

			if (Comp_Day(Inputs[i].Start, EndMax))
			{
				// 끊김
				cout << 0;
				return 0;
			}
		}
		
		if(Comp_Day(Inputs[i].End, TempEndMax))
		{
			TempEndMax = Inputs[i].End;
		}

	}


	if (Comp_Day(TempEndMax, make_pair(11, 30)))
	{
		++iAns;
		cout << iAns;
	}
	else
	{
		cout << 0;
	}
		

	return 0;
}