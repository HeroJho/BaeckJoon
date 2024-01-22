#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;


int g_N;
int g_Matrix[20][20] = { 0 };
bool g_Visited[20] = { false };

vector<int> g_Team1;
vector<int> g_Team2;

int g_Ans = INT_MAX;

void Check()
{
    g_Team2.clear();
    for (int i = 0; i < g_N; ++i)
    {
        if (g_Visited[i])
            continue;
        g_Team2.push_back(i);
    }

    int Sum1 = 0;
    int Sum2 = 0;
    for (int i = 0; i < g_Team1.size(); ++i)
    {
        for (int j = i + 1; j < g_Team1.size(); ++j)
        {
            Sum1 += g_Matrix[g_Team1[i]][g_Team1[j]];
            Sum1 += g_Matrix[g_Team1[j]][g_Team1[i]];

            Sum2 += g_Matrix[g_Team2[i]][g_Team2[j]];
            Sum2 += g_Matrix[g_Team2[j]][g_Team2[i]];
        }
    }

    int ASum = abs(Sum1 - Sum2);
    if (ASum < g_Ans)
        g_Ans = ASum;

}

void DFS(int Depth, int Start)
{
    if (Depth >= g_N / 2)
    {
        Check();
        return;
    }


    for (int i = Start; i < g_N; ++i)
    {
        if (g_Visited[i])
            continue;

        g_Team1.push_back(i);
        g_Visited[i] = true;
        DFS(Depth + 1, i + 1);
        g_Team1.pop_back();
        g_Visited[i] = false;

    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_N;
    for (int i = 0; i < g_N; ++i)
    {
        for (int j = 0; j < g_N; ++j)
        {
            cin >> g_Matrix[i][j];
        }
    }


    DFS(0, 0);
 
    cout << g_Ans;

    return 0;
}
