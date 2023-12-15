#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int DPs[1000001] = { 0 };

class Func
{
public:
	bool operator()(pair<int, int> l, pair<int, int> r)
	{
		return l.first > r.first;
	}
};

vector<int> solution(vector<int> numbers) {
	vector<int> answer;

	priority_queue<pair<int ,int>, vector<pair<int ,int>>, Func> Qs;
	for (int i = 0; i < 1000001; ++i)
		DPs[i] = -1;

	for (int i = 0; i < numbers.size(); ++i)
	{		
		while(!Qs.empty())
		{
			pair<int, int> top = Qs.top();
			if (numbers[i] <= top.first)
				break;

			Qs.pop();
			DPs[top.second] = numbers[i];
		}

		Qs.push({ numbers[i], i});

	}

	for (int i = 0; i < numbers.size(); ++i)
	{
		answer.push_back(DPs[i]);
	}

	return answer;
}

