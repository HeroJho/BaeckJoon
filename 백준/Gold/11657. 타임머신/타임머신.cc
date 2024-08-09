#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

ll Dist[504];
int N, M;
vector<pair<pair<int, int>, int>> V;

void Belman() 
{
	Dist[1] = 0;
	for (int i = 1; i <= N - 1; i++) 
	{
		for (int j = 0; j < V.size(); j++)
		{
			int St = V[j].first.first;
			int En = V[j].first.second;
			int Cost = V[j].second;

			if (Dist[St] == INT_MAX) 
				continue;

			if (Dist[En] > Dist[St] + Cost) 
				Dist[En] = Dist[St] + Cost;
		}
	}

	for (int j = 0; j < V.size(); j++)
	{
		int St = V[j].first.first;
		int En = V[j].first.second;
		int Cost = V[j].second;
		if (Dist[St] == INT_MAX)
			continue;
		if (Dist[En] > Dist[St] + Cost) 
		{
			cout << -1;
			return;
		}
	}
	for (int i = 2; i <= N; i++) 
	{
		if (Dist[i] == INT_MAX)
			cout << -1 << '\n';
		else 
			cout << Dist[i] << '\n';
	}
}

int main(void) 
{

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i <= 500; i++) 
		Dist[i] = INT_MAX;

	for (int i = 0; i < M; i++) 
	{
		int A, B, C;
		cin >> A >> B >> C;
		V.push_back({ {A,B}, C });
	}

	Belman();

	return 0;
}