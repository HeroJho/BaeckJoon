#include <iostream>

using namespace std;

long long DP[101][10] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    // DP[N][5] = DP[N-1][4] + DP[N-1][3]

    DP[1][0] = 0;
    for (int i = 1; i <= 9; ++i)
        DP[1][i] = 1;

    for (int n = 2; n <= N; ++n)
    {
        for (int i = 0; i <= 9; ++i)
        {
            if(i + 1 <= 9)
                DP[n][i] = (DP[n][i] + DP[n - 1][i + 1]) % 1000000000;
            if(i - 1 >= 0)
                DP[n][i] = (DP[n][i] + DP[n - 1][i - 1]) % 1000000000;

        }

    }

    long long Ans = 0;
    for (int i = 0; i <= 9; ++i)
        Ans =(Ans + DP[N][i]) % 1000000000;

    cout << Ans;

    return 0;
}