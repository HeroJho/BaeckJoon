#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int Matrix[1000][1000] = { 0 };
int DP[1000][1000] = { 0 };

int DirX[] = { 0, 1, 1 };
int DirY[] = { 1, 0, 1 };

bool IsIn(int X, int Y)
{
    return X >= 0 && X < M && Y >= 0 && Y < N;
}

void BFS()
{
    queue<pair<int, int>> Qs;
    Qs.push({0,0});
    DP[0][0] = Matrix[0][0];

    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.front();
        Qs.pop();

        for (int i = 0; i < 3; ++i)
        {
            int nX = DirX[i] + Cur.first;
            int nY = DirY[i] + Cur.second;
            int nV = Matrix[nY][nX] + DP[Cur.second][Cur.first];

            if (!IsIn(nX, nY))
                continue;

            if (DP[nY][nX] >= nV)
                continue;
            DP[nY][nX] = nV;
            
            Qs.push({nX,nY});

        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Matrix[i][j];

            DP[i][j] = -1;
        }
    }

    BFS();

    cout << DP[N - 1][M - 1];

    return 0;
}
