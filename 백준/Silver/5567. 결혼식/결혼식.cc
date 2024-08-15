#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N, M;
vector<int> Matrix[501];
bool Visited[501] = { false };

void BFS()
{
    queue<int> Qs;
    Qs.push(1);
    Visited[1] = true;

    int Cnt = 0;
    while (!Qs.empty())
    {
        int Size = Qs.size();

        for (int s = 0; s < Size; ++s)
        {
            int Cur = Qs.front();
            Qs.pop();

            for (int i = 0; i < Matrix[Cur].size(); ++i)
            {
                int Nex = Matrix[Cur][i];

                if (Visited[Nex])
                    continue;
                Visited[Nex] = true;

                Qs.push(Nex);

            }
        }


        ++Cnt;
        if (Cnt == 2)
            break;
        
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
        Matrix[End].push_back(Start);
    }

    BFS();

    int Ans = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (Visited[i])
            ++Ans;
    }

    cout << Ans;

    return 0;
}