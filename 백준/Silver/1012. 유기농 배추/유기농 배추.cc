#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Matrix[51][51];
bool Visited[51][51];

int T, M, N, K;

void Clear()
{
	for (int i = 0; i < 51; ++i)
	{
		for (int j = 0; j < 51; ++j)
		{
			Matrix[i][j] = 0;
			Visited[i][j] = false;
		}
	}
}

int DFS(int x, int y, int iCount)
{
	Visited[x][y] = true;

	// 상하좌우
	bool bRange = ((x >= 0 && x < M) && (y + 1 >= 0 && y + 1 < N));
	if (bRange && Matrix[x][y + 1] == 1 && Visited[x][y + 1] == false)
	{
		iCount += DFS(x, y + 1, ++iCount);
	}
	bRange = ((x >= 0 && x < M) && (y - 1 >= 0 && y - 1 < N));
	if (bRange && Matrix[x][y - 1] == 1 && Visited[x][y - 1] == false)
	{
		iCount += DFS(x, y - 1, ++iCount);
	}
	bRange = ((x + 1 >= 0 && x + 1 < M) && (y >= 0 && y < N));
	if (bRange && Matrix[x + 1][y] == 1 && Visited[x + 1][y] == false)
	{
		iCount += DFS(x + 1, y, ++iCount);
	}
	bRange = ((x - 1 >= 0 && x - 1 < M) && (y >= 0 && y < N));
	if (bRange && Matrix[x - 1][y] == 1 && Visited[x - 1][y] == false)
	{
		iCount += DFS(x - 1, y, ++iCount);
	}

	return iCount;
}

int DFS_All()
{
	int iCount = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Matrix[i][j] == 1 && Visited[i][j] == false)
			{
				int iiCount = 0;
				++iCount;
				iiCount = DFS(i, j, iiCount);
			}
		}
	}

	return iCount;
}

int main()
{
	cin >> T;
	vector<int> Answer;
	for (int t = 0; t < T; ++t)
	{
		Clear();
		cin >> M >> N >> K;

		for (int i = 0; i < K; ++i)
		{
			int X, Y; cin >> X >> Y;
			Matrix[X][Y] = 1;
		}

		Answer.push_back(DFS_All());
	}

	for (int i = 0; i < Answer.size(); ++i)
	{
		cout << Answer[i] << endl;
	}

	return 0;
}
