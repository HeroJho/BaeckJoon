#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_set>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S;
	cin >> S;

	unordered_set<string> Set;
	for (int i = 0; i < S.length(); ++i)
	{
		string Temp;
		for (int j = i; j < S.length(); ++j)
		{
			Temp += S[j];
			Set.emplace(Temp);
		}
	}

	cout << Set.size();

	return 0;
}
