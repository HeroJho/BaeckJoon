#include <iostream>

using namespace std;

long long Mods[1001] = { 0 };

int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int N, M, T;
	cin >> N >> M;

	long long Sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> T;
		Sum += T;
		Mods[Sum % M]++;
	}

	long long Ans = 0;
	for (int i = 0; i <= M; i++)
		Ans += (Mods[i] * (Mods[i] - 1)) / 2;

	cout << Mods[0] + Ans;

	return 0;
}