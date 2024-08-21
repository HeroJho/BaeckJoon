#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<int> Matrix[501];
vector<int> InvMatrix[501];

bool Visited[501] = { false };

void Reset()
{
    for (int i = 0; i < 501; ++i)
    {
        Visited[i] = false;
    }
}

void BFS(const vector<int>* const Ms, int Start)
{
    queue<int> Qs;
    Qs.push(Start);
    Visited[Start] = true;

    while (!Qs.empty())
    {
        int Cur = Qs.front();
        Qs.pop();

        for (int i = 0; i < Ms[Cur].size(); ++i)
        {
            int Nex = Ms[Cur][i];
            if (Visited[Nex])
                continue;
            Visited[Nex] = true;

            Qs.push(Nex);
        }

    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;
        Matrix[Start].push_back(End);
        InvMatrix[End].push_back(Start);
    }

    int Ans = 0;

    for (int i = 1; i <= N; ++i)
    {
        Reset();
        BFS(Matrix, i);
        BFS(InvMatrix, i);

        bool bCheck = true;
        for (int v = 1; v <= N; ++v)
        {
            if (Visited[v] == false)
            {
                bCheck = false;
                break;
            }
        }

        if (bCheck)
        {
            ++Ans;
        }
    }

    cout << Ans;

    return 0;
}