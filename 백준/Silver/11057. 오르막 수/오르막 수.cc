#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long DP[1001][10] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;

    for (int i = 0; i < 10; ++i)
    {
        DP[1][i] = i + 1;
    }


    for (int n = 2; n <= N; ++n)
    {
        for (int i = 0; i < 10; ++i)
        {
            if(i == 0)
                DP[n][i] = DP[n - 1][9];
            else
            {
                DP[n][i] = (((DP[n - 1][9] - DP[n - 1][i - 1] + 10007) % 10007) + DP[n][i - 1]) % 10007;
               //  DP[n][i] = (((DP[n - 1][9] - DP[n - 1][i - 1] + 10004) % 10004) + DP[n][i - 1]) % 10004;
            }

        }
    }

    cout << DP[N][9];


    return 0;
}
