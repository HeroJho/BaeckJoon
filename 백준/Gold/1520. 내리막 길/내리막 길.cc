#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int g_N, g_M;
int g_Matrix[500][10000] = { 0 };
int g_DP[500][10000] = { 0 };

int g_DirX[] = { 0, 0, -1, 1 };
int g_DirY[] = { -1, 1, 0, 0 };

void Reset()
{
    for (int y = 0; y < g_M; ++y)
    {
        for (int x = 0; x < g_N; ++x)
        {
            g_DP[y][x] = -1;
        }
    }
}

bool IsIn(int X, int Y)
{
    return X >= 0 && X < g_N && Y >= 0 && Y < g_M;
}


int DFS(pair<int ,int> Pos)
{
    if(Pos.first == g_N - 1 && Pos.second == g_M - 1)
    {
        return 1;
    }
    else if (g_DP[Pos.second][Pos.first] != - 1)
    {
        return g_DP[Pos.second][Pos.first];
    }

    g_DP[Pos.second][Pos.first] = 0;

    for (int i = 0; i < 4; ++i)
    {
        int inX = g_DirX[i] + Pos.first;
        int inY = g_DirY[i] + Pos.second;

        if (!IsIn(inX, inY))
            continue;

        if (g_Matrix[inY][inX] >= g_Matrix[Pos.second][Pos.first])
            continue;
        
        g_DP[Pos.second][Pos.first] += DFS({inX, inY});

    }
    
    return g_DP[Pos.second][Pos.first];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_M >> g_N;
    for (int y = 0; y < g_M; ++y)
    {
        for (int x = 0; x < g_N; ++x)
        {
            cin >> g_Matrix[y][x];
        }
    }

    Reset();
    DFS({0, 0});

    cout << g_DP[0][0];

    return 0;
}
