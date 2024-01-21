#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int g_N, g_M;
vector<int> g_Inputs;
vector<int> g_Temp;
bool g_Visited[10] = { false };

void DFS(int Depth)
{
    if (Depth >= g_M)
    {
        for (int i = 0; i < g_M; ++i)
        {
            cout << g_Temp[i] << " ";
        }
        cout << "\n";

        return;
    }
        
    int PreNum = -1;
    for (int i = 0; i < g_Inputs.size(); ++i)
    {
        if (g_Visited[i])
            continue;

        if (PreNum == g_Inputs[i])
            continue;

        g_Visited[i] = true;
        g_Temp.push_back(g_Inputs[i]);

        DFS(Depth + 1);

        PreNum = g_Inputs[i];
        g_Visited[i] = false;
        g_Temp.pop_back();
    }

}

// 1 7 9 9
// 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_N >> g_M;
    for (int i = 0; i < g_N; ++i)
    {
        int Temp;
        cin >> Temp;
        g_Inputs.push_back(Temp);
    }

    sort(g_Inputs.begin(), g_Inputs.end());

    DFS(0);

    return 0;
}
