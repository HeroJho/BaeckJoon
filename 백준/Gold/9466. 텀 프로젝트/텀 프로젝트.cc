#include <iostream>
#include <queue>
#include <cstring>

#define MAX 100001

using namespace std;

int T, N;
int Graph[MAX];
bool Visited[MAX];
bool Done[MAX];
int Cnt;

void DFS(int Node) 
{

	Visited[Node] = true;
	int Next = Graph[Node];

	if (!Visited[Next])
	{
		DFS(Next);
	}
	else if (!Done[Next]) 
	{
		//방문은 했지만 아직 사이클이 아니라면 next까지 포함해서 사이클 완성
		//자기 자신을 포함한 팀의 멤버를 카운트
		for (int i = Next; i != Node; i = Graph[i])
			Cnt++;
		
		Cnt++;
	}

	Done[Node] = true;

}


int main() 
{

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> T;
	while (T--) 
	{
		cin >> N;
		for (int i = 1; i <= N; ++i) 
		{
			cin >> Graph[i];
		}

		for (int i = 1; i <= N; ++i) 
		{
			if (!Visited[i])
				DFS(i);
			
		}

		cout << N - Cnt << '\n';

		Cnt = 0;
		memset(Visited, false, sizeof(Visited));
		memset(Done, false, sizeof(Done));
	}


	return 0;
}