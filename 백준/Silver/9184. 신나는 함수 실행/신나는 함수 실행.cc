#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

long long DP[51][51][51] = { 0 };

void Reset()
{
	for (int i = 0; i < 51; ++i)
	{
		for (int j = 0; j < 51; ++j)
		{
			for (int z = 0; z < 51; ++z)
			{
				DP[i][j][z] = 0;
			}
		}
	}
}


long long DFS(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (DP[a][b][c] != 0)
	{
		return DP[a][b][c];
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return DP[a][b][c] = DFS(20, 20, 20);
	}
	else if(a < b && b < c)
	{
		DP[a][b][c] = DFS(a, b, c - 1) + DFS(a, b - 1, c - 1) - DFS(a, b - 1, c);
		return DP[a][b][c];
	}
	else
	{
		DP[a][b][c] = DFS(a - 1, b, c) + DFS(a - 1, b - 1, c) + DFS(a - 1, b, c - 1) - DFS(a - 1, b - 1, c - 1);
		return DP[a][b][c];
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
		{
			return 0;
		}

		Reset();
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << DFS(a, b, c) << '\n';

	}

	
	

	return 0;
}
