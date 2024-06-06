#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;


int N, M, Start;
vector<int> Matrix[100001];
int Visited[100001] = { 0 };

void BFS()
{
    queue<int> Qs;
    Qs.push(Start);
    Visited[Start] = 1;

    int Count = 1;
    while (!Qs.empty())
    {
        int Cur = Qs.front();
        Qs.pop();

        for (int i = 0; i < Matrix[Cur].size(); ++i)
        {
            int Nex = Matrix[Cur][i];

            if (Visited[Nex] != 0)
                continue;

            ++Count;
            Visited[Nex] = Count;

            Qs.push(Nex);
        }

    }

    for (int i = 1; i <= N; ++i)
    {
        cout << Visited[i] << '\n';
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> Start;

    for (int i = 0; i < M; ++i)
    {
        int One, Two;
        cin >> One >> Two;
        Matrix[One].push_back(Two);
        Matrix[Two].push_back(One);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(Matrix[i].rbegin(), Matrix[i].rend());
    }


    BFS();


    return 0;
}