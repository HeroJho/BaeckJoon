#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> inputs;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		inputs.push_back(temp);
	}


	int DPs[100000] = { 0 };
	DPs[0] = inputs[0];
	int ans = DPs[0];
	for (int i = 1; i < inputs.size(); ++i)
	{
		DPs[i] = max(DPs[i - 1] + inputs[i], inputs[i]);
		if (ans < DPs[i])
			ans = DPs[i];
	}

	cout << ans;

	return 0;
}
