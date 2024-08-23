#include <iostream>

using namespace std;

int N,K;
long dp[201][201];
long DIV = 1000000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> K;

    dp[0][0] = 1;

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) dp[i][j] += dp[i-1][k]; 
            
            dp[i][j] %= DIV;
        }
    }

    cout << dp[K][N];

    return 0;
}