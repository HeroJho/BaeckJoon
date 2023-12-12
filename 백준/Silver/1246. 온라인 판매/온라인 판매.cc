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

	int n, m;
	cin >> n >> m;
	vector<int> inputs;
	for (int i = 0; i < m; ++i)
	{
		int temp; cin >> temp;
		inputs.push_back(temp);
	}

	sort(inputs.begin(), inputs.end());

	int max = 0;
	int maxindex = 0;
	for (int i = 0; i < m; ++i)
	{
		int count = (m - i);
		if (count > n)
			count = n;

		int sum = inputs[i] * count;
		if (sum > max)
		{
			max = sum;
			maxindex = inputs[i];
		}
			
	}

	cout << maxindex << " " << max;
	
	return 0;
}
