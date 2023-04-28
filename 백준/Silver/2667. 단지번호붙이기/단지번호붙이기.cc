#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int Matrix[26][26];
bool Visited[26][26];

int N;
vector<int> Answer;

void Clear()
{
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			Matrix[i][j] = 0;
			Visited[i][j] = false;
		}
	}
}

void DFS(int x, int y, int* iCount)
{
	Visited[x][y] = true;
	(*iCount)++;

	// 상하좌우
	if ((x >= 0 && x < N && y + 1 >= 0 && y + 1 < N) && Visited[x][y + 1] == false && Matrix[x][y + 1] == 1)
	{
		DFS(x, y + 1, iCount);
	}
	if ((x >= 0 && x < N && y - 1 >= 0 && y - 1 < N) && Visited[x][y - 1] == false && Matrix[x][y - 1] == 1)
	{
		DFS(x, y - 1, iCount);
	}
	if ((x - 1 >= 0 && x - 1 < N && y >= 0 && y < N) && Visited[x - 1][y] == false && Matrix[x - 1][y] == 1)
	{
		DFS(x - 1, y, iCount);
	}
	if ((x + 1 >= 0 && x + 1 < N && y >= 0 && y < N) && Visited[x + 1][y] == false && Matrix[x + 1][y] == 1)
	{
		DFS(x + 1, y, iCount);
	}
}

void DFS_Loop()
{
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (Matrix[i][j] == 1 && Visited[i][j] == false)
			{
				int iCount = 0;
				DFS(i, j, &iCount);
				Answer.push_back(iCount);
			}
		}
	}
}

int main()
{
	Clear();

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s; cin >> s;

		for (int j = 0; j < N; ++j)
		{
			if(s[j] == '1')
				Matrix[i][j] = 1;
		}
	}

	DFS_Loop();

	sort(Answer.begin(), Answer.end());

	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); ++i)
	{
		cout << Answer[i] << endl;
	}

	// cout << Answer.back();

	return 0;
}
