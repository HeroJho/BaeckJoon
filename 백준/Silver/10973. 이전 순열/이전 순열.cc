#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, Num;
	cin >> N;
	vector<int> V(N);

	for (int i = 0; i < N; i++) 
	{
		cin >> V[i];
	}

	if (prev_permutation(V.begin(), V.end()))
	{
		for (int i = 0; i < N; i++)
			cout << V[i] << " ";	
	}
	else
	{
		cout << -1;
	}

	return 0;
}