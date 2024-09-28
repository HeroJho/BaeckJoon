#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int DP[100][10001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);

    }

    for (int i = 0; i < N; ++i)
    {
        for (int m = 0; m <= M; ++m)
        {
            DP[i][m] = INT_MAX;
            DP[i][0] = 0;
        }
    }


    // 2 15
    // 5 12
    for (int m = 0; m <= M; ++m)
    {
        if(m % Inputs[0] == 0)
            DP[0][m] = m / Inputs[0];
    }



    for (int i = 1; i < N; ++i)
    {
        for (int m = 0; m <= M; ++m)
        {
            if (m - Inputs[i] >= 0 && DP[i][m - Inputs[i]] != INT_MAX)
                DP[i][m] = min(DP[i - 1][m], DP[i][m - Inputs[i]] + 1);
            else
                DP[i][m] = DP[i - 1][m];
        }
    }

    if (DP[N - 1][M] == INT_MAX)
        cout << -1;
    else
        cout << DP[N - 1][M];

    return 0;
}