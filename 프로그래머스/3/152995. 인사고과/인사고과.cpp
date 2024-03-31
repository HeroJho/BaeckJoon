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
	bool operator()(pair<int, pair<int, int>> L, pair<int, pair<int, int>> R)
	{
		return L.second.first > R.second.first;
	}
};

int solution(vector<vector<int>> scores) 
{
   
	vector <pair<int, pair<int, int>>> Inputs;
	for (int i = 0; i < scores.size(); ++i)
	{
		Inputs.push_back({ i, { scores[i][0], scores[i][1] }});
	}

	sort(Inputs.begin(), Inputs.end(), Func());

	vector<pair<int, int>> Scores;

	int Cur = -1;
	int Max = 0;
	int CurMax = -1;
	for (int i = 0; i < Inputs.size(); ++i)
	{
		// 이전과 first가 같다면 Min을 갱신
		if (Cur == Inputs[i].second.first)
		{
			if (CurMax < Inputs[i].second.second)
			{
				CurMax = Inputs[i].second.second;
			}
		}
		else
		{
			if(Max < CurMax)
				Max = CurMax;
			CurMax = Inputs[i].second.second;
		
			Cur = Inputs[i].second.first;
		}

		if (Max <= Inputs[i].second.second)
		{
			// 넣는다
			Scores.push_back({ Inputs[i].second.first + Inputs[i].second.second, Inputs[i].first });
		}
	}

	sort(Scores.rbegin(), Scores.rend());

	int Score = 1;
	int Cnt = 1;
	for (int i = 0; i < Scores.size() - 1; ++i)
	{
		if (Scores[i].second == 0)
		{
			return Score;
		}

		if (Scores[i].first == Scores[i + 1].first)
		{
			++Cnt;
		}
		else
		{
			Score += Cnt;
			Cnt = 1;
		}
	}

	if (Scores.back().second == 0)
		return Score;

    return -1;
}
