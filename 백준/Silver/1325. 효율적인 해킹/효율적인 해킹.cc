#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


int N, M;
vector<int> Matrix[10001];
bool Visited[10001] = { false };
int DP[10001] = { 0 };

void Reset()
{
    for (int i = 1; i <= N; ++i)
    {
        Visited[i] = false;
    }
}

int BFS(int Start)
{
    int Cnt = 1;

    queue<int> Qs;
    Qs.push(Start);
    Visited[Start] = true;

    while (!Qs.empty())
    {
        int Cur = Qs.front();
        Qs.pop();

        for (int i = 0; i < Matrix[Cur].size(); ++i)
        {
            int nNode = Matrix[Cur][i];

            if (Visited[nNode])
                continue;
            Visited[nNode] = true;
            
            ++Cnt;

            Qs.push(nNode);
        }

    }

    return Cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        Matrix[B].push_back(A);
    }

    int Max = 0;
    for (int i = 1; i <= N; ++i)
    {
        Reset();

        int Cnt = BFS(i);
        DP[i] = Cnt;
        if (Max < Cnt)
            Max = Cnt;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (Max == DP[i])
            cout << i << ' ';
    }


    return 0;
}