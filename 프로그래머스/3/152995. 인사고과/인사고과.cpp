#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

struct Data
{
	pair<int, int> Score;
	int iIndex = 0;

	Data() {};
	Data(pair<int, int> _Score, int _iIndex) : Score(_Score), iIndex(_iIndex) {};
};

class Func
{
public:
	bool operator() (Data L, Data R)
	{
		return L.Score.first > R.Score.first;
	}
};
class Func3
{
public:
	bool operator() (Data L, Data R)
	{
		return L.Score.first == R.Score.first && L.Score.second < R.Score.second;
	}
};
class Func1
{
public:
	bool operator() (pair<int ,int> L, pair<int, int> R)
	{
		return L.first > R.first;
	}
};


int solution(vector<vector<int>> scores) {
	int answer = 0;

	vector<Data> Inputs;
	for (int i = 0; i < scores.size(); ++i)
	{
		Data Temp;
		Temp.Score.first = scores[i][0];
		Temp.Score.second = scores[i][1];
		Temp.iIndex = i;
		Inputs.push_back(Temp);
	}

	sort(Inputs.begin(), Inputs.end(), Func());
	stable_sort(Inputs.begin(), Inputs.end(), Func3());

	vector<Data> Temps;
	Temps.push_back(Inputs[0]);
	int iMax = Inputs[0].Score.second;
	for (int i = 1; i < Inputs.size(); ++i)
	{
		if (Inputs[0].Score.first == Inputs[i].Score.first)
		{
			Temps.push_back(Inputs[i]);
			if (iMax <= Inputs[i].Score.second)
			{
				iMax = Inputs[i].Score.second;
			}
		}
		else
		{
			if (iMax <= Inputs[i].Score.second)
			{
				Temps.push_back(Inputs[i]);
				iMax = Inputs[i].Score.second;
			}
		}


	}

	vector<pair<int, int>> Temps2;
	for (int i = 0; i < Temps.size(); ++i)
	{
		Temps2.push_back({ Temps[i].Score.first + Temps[i].Score.second, Temps[i].iIndex});
	}

	sort(Temps2.begin(), Temps2.end(), Func1());


	int iCount = 0;
	int iHoldScore = Temps2[0].first;
	if (Temps2[0].second == 0)
	{
		return iCount + 1;
	}


	for (int i = 1; i < Temps2.size(); ++i)
	{
		if (iHoldScore == Temps2[i].first)
		{
			if (Temps2[i].second == 0)
			{
				return iCount + 1;
			}
		}
		else
		{
			iHoldScore = Temps2[i].first;
			iCount = i;
			if (Temps2[i].second == 0)
			{
				return i + 1;
			}
		}

	}


	return -1;
}
