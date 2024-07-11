#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N, K;
    cin >> N >> K;

    // DP[k][n] = K개를 더해서 합이 N일 경우
    int DP[201][201] = { 0 };
    
    for (int i = 0; i <= N; ++i)
    {
        DP[1][i] = 1;
    }
   

    for (int k = 1; k <= K; ++k)
    {
        for (int n = 0; n <= N; ++n)
        {
            for (int i = 0; i <= n; ++i)
            {
                DP[k][n] += DP[k - 1][n - i];
                DP[k][n] %= 1000000000;
            }
        }
    }


    cout << DP[K][N];


    return 0;
}