#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
int T;
int DP[501][501];
int Sum[501];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) 
    {
        int K;
        cin >> K;
        for (int i = 1; i <= K; i++) 
        {
            int A;
            cin >> A;
            Sum[i] = Sum[i - 1] + A;
        }

        for (int i = 1; i < K; i++) 
        { 
            // i는 구해야하는 범위, ex) i=1이면 1~2, 2~3 ... 파일
            for (int x = 1; x <= K - i; x++)
            { 
                int y = x + i;
                DP[x][y] = INT_MAX; 

                // x~y 범위 파일들을 합치는 최소 비용
                for (int mid = x; mid < y; mid++) 
                { 
                    DP[x][y] = min(DP[x][y], DP[x][mid] + DP[mid + 1][y] + Sum[y] - Sum[x - 1]);
                }

            }

        }

        cout << DP[1][K] << "\n";
    }

    return 0;
}
