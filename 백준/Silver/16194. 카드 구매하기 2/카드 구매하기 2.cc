#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int DP[1001][1001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> Inputs;
    Inputs.push_back(-1);
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }
    // i개 = 가격

    // i까지 고려해서 N개를 만들기 위한 최소 가격
    // DP[i][N] = DP[i-1][N] or DP[i-1][N- V] + V
    
    for (int i = 0; i <= N; ++i)
    {
        for (int n = 0; n <= N; ++n)
        {
            DP[i][n] = INT_MAX;
            DP[i][0] = 0;
        }
    }


    for (int i = 1; i <= N; ++i)
    {
        for (int n = 0; n <= N; ++n)
        {
            if (n - i >= 0)
                DP[i][n] = min(DP[i - 1][n], DP[i][n - i] + Inputs[i]);
            else
                DP[i][n] = DP[i - 1][n];

        }
    }

    cout << DP[N][N];

    return 0;
}