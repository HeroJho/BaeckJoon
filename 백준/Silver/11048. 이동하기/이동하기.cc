#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int map[1001][1001];
bool check[1001][1001];
int answer[1001][1001];
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	answer[0][0] = map[0][0];
	while (!q.empty())
	{
		int x, y; tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (check[ny][nx] == false)
				{
					q.push(make_pair(nx, ny));
					check[ny][nx] = true;
					answer[ny][nx] = answer[y][x] + map[ny][nx];
				}
				else if (answer[ny][nx] < answer[y][x] + map[ny][nx])
				{
					q.push(make_pair(nx, ny));
					answer[ny][nx] = answer[y][x] + map[ny][nx];
				}

			}
		}
	}
	cout << answer[n - 1][m - 1];
	return 0;
}
