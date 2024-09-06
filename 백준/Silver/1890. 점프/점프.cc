#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int Matrix[101][101] = { 0 };
long long DP[101][101] = { 0 };

bool IsIn(int X, int Y)
{
    return X >= 0 && X < N&& Y >= 0 && Y < N;
}

long long DFS(pair<int, int> Pos)
{
    if (Pos.first == N - 1 && Pos.second == N - 1)
    {
        return 1;
    }

    if (DP[Pos.second][Pos.first] != 0)
    {
        return DP[Pos.second][Pos.first];
    }

    int Dis = Matrix[Pos.second][Pos.first];
    if (Dis == 0)
        return 0;

    int nX = Dis + Pos.first;
    int nY = Pos.second;
    if (IsIn(nX, nY))
    {
       DP[Pos.second][Pos.first] += DFS({nX,nY});
    }


    nX = Pos.first;
    nY = Dis + Pos.second;
    if (IsIn(nX, nY))
    {
        DP[Pos.second][Pos.first] += DFS({ nX,nY });
    }

    return DP[Pos.second][Pos.first];
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Matrix[i][j];
        }
    }


    cout << DFS({ 0, 0});


    return 0;
}