#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

class Func1
{
public:
	bool operator()(string L, string R)
	{
		return L.length() < R.length();
	}
};

class Func2
{
public:
	bool operator()(string L, string R)
	{
		return L.length() == R.length() && L < R;
	}
};

int g_N;
vector<string> g_Inputs;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_N;
	for (int i = 0; i < g_N; ++i)
	{
		string Temp;
		cin >> Temp;
		g_Inputs.push_back(Temp);
	}

	sort(g_Inputs.begin(), g_Inputs.end(), Func1());
	stable_sort(g_Inputs.begin(), g_Inputs.end(), Func2());

	auto iter = unique(g_Inputs.begin(), g_Inputs.end());
	g_Inputs.erase(iter, g_Inputs.end());

	for (int i = 0; i < g_Inputs.size(); ++i)
	{
		cout << g_Inputs[i] << '\n';
	}


	return 0;
}
