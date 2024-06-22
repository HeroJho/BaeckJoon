#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int N;
vector<int> Inputs;
int Ans = 0;

int DP[1000] = { 0 };

void DFS(int Depth, int CurIndex)
{
	if (Depth > Ans)
		Ans = Depth;

	if (DP[CurIndex] >= Depth)
		return;
	DP[CurIndex] = Depth;

	for (int i = CurIndex + 1; i < N; ++i)
	{
		if (Inputs[CurIndex] > Inputs[i])
		{
			DFS(Depth + 1, i);
		}
	
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}


	for (int i = 0; i < N; ++i)
	{
		DFS(1, i);
	}

	cout << Ans;

	return 0;
}
