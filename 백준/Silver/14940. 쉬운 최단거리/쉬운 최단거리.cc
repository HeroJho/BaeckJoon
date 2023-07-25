#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

#define MAX 1000
#define FOUR 4

int n{ 0 }, m{ 0 };
vector<vector<int>> vec;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

void BFS()
{
	array<int, 4> dx{ 0,0,-1,1 };
	array<int, 4> dy{ -1,1,0,0 };

	while (false == q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < FOUR; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			{
				continue;
			}

			if (0 == vec[ny][nx])
			{
				continue;
			}

			if (false == visited[ny][nx])
			{
				vec[ny][nx] = vec[y][x] + 1;
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> n >> m;

	vec.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];

			if (2 == vec[i][j])
			{
				q.push({ i, j });
				visited[i][j] = true;
				vec[i][j] = 0;	// target 변수에 값을 저장해 두고, 목표지점을 0으로 시작해서 값이 증가하도록 한다.
			}
		}
	}

	BFS();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == false && vec[i][j] == 1)
			{
				cout << -1 << " ";
				continue;
			}

			cout << vec[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
