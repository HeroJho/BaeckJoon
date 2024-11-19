#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> Dist(V + 1, vector<int>(V + 1, INT_MAX));

    for (int i = 1; i <= V; ++i)
    {
        Dist[i][i] = 0;
    }

    for (int i = 0; i < E; ++i)
    {
        int S, E, W;
        cin >> S >> E >> W;
        Dist[S][E] = W;
    }

    for (int k = 1; k <= V; ++k)
    {
        for (int i = 1; i <= V; ++i)
        {
            for (int j = 1; j <= V; ++j)
            {
                if (Dist[i][k] != INT_MAX && Dist[k][j] != INT_MAX)
                {
                    Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
                }
            }
        }
    }

    int MinCycle = INT_MAX;
    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (i != j && Dist[i][j] != INT_MAX && Dist[j][i] != INT_MAX)
            {
                MinCycle = min(MinCycle, Dist[i][j] + Dist[j][i]);
            }
        }
    }

    if (MinCycle == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << MinCycle << '\n';
    }

    return 0;
}
