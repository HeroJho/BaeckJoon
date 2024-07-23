#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N;
int Matrix[501][501] = { 0 };
// 이 이후로 N개가 최대다
int DP[501][501] = { 0 };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };


bool IsIn(int X, int Y)
{
    return X >= 0 && X < N&& Y >= 0 && Y < N;
}

int DFS(int Depth, pair<int, int> Pos)
{
    if (DP[Pos.second][Pos.first] != 0)
    {
        return DP[Pos.second][Pos.first];
    }

    for (int i = 0; i < 4; ++i)
    {
        int nX = Pos.first + DirX[i];
        int nY = Pos.second + DirY[i];

        if (!IsIn(nX, nY))
            continue;

        if (Matrix[Pos.second][Pos.first] < Matrix[nY][nX])
        {
            DP[Pos.second][Pos.first] = max(DP[Pos.second][Pos.first] , DFS(Depth + 1, { nX, nY }) + 1);
        }
            

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

    int Ans = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Ans = max(Ans, DFS(0, { j,i }));
        }
    }

    cout << Ans + 1;

    return 0;
}