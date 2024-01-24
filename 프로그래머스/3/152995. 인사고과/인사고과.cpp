#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

bool g_Nos[100001] = { false };

class Func
{
public:
	bool operator()(vector<int> L, vector<int> R)
	{
		return L[0] > R[0];
	}
};

class Func2
{
public:
	bool operator()(vector<int> L, vector<int> R)
	{
		return L[0] == R[0] && L[1] < R[1];
	}
};

class Func3
{
public:
	bool operator()(vector<int> L, vector<int> R)
	{
		return L[3] > R[3];
	}
};

int solution(vector<vector<int>> scores) {
	int answer = 0;

	// 2 = 인덱스
	for (int i = 0; i < scores.size(); ++i)
	{
		scores[i].push_back(i);
	}

	// 0 내림 1 오름
	sort(scores.begin(), scores.end(), Func());
	stable_sort(scores.begin(), scores.end(), Func2());


	int Min = scores[0][1];
	for (int i = 0; i < scores.size() - 1; ++i)
	{
		if (Min > scores[i][1])
		{
			g_Nos[i] = true;
		}

		if (scores[i][0] != scores[i + 1][0])
		{
			if(Min < scores[i][1])
				Min = scores[i][1];
		}

	}

	if (Min > scores[scores.size() - 1][1])
	{
		g_Nos[scores.size()-1] = true;
	}
	


	int Count = -1;
	for (auto iter = scores.begin(); iter != scores.end();)
	{
		++Count;
		if (g_Nos[Count])	
		{
			iter = scores.erase(iter);
			continue;
		}

		int Score = (*iter)[0] + (*iter)[1];
		iter->push_back(Score);

		++iter;
	}

	sort(scores.begin(), scores.end(), Func3());


	int Rank = 0;
	int PreScore = -1;
	for (int i = 0; i < scores.size(); ++i)
	{
		if (PreScore != scores[i][3])
		{
			Rank = i + 1;
			PreScore = scores[i][3];
		}

		if (scores[i][2] == 0)
		{
			return Rank;
		}
	}

	return -1;
}
