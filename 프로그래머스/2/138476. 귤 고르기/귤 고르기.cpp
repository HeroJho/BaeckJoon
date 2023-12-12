#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Func
{
public:
	bool operator()(int l, int r)
	{
		return l > r;
	}
};

int g_DP[10000001] = { 0 };

int solution(int k, vector<int> tangerine) {
	int answer = 0;

	for (int i = 0; i < tangerine.size(); ++i)
	{
		++g_DP[tangerine[i]];
	}

	vector<int> inputs;
	for (int i = 0; i < 10000001; ++i)
	{
		if (g_DP[i])
			inputs.push_back(g_DP[i]);
	}

	sort(inputs.begin(), inputs.end(), Func());

	for (int i = 0; i < inputs.size(); ++i)
	{
		k -= inputs[i];
		++answer;
		if (k <= 0)
			break;
	}

	return answer;
}