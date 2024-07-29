#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N, K;
vector<int> Inputs;
int DP[101][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    // 초기화
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= K; ++j)
        {
            DP[i][j] = (j == 0) ? 0 : INT_MAX;
        }
    }

    // 첫 번째 동전 사용 초기화
    for (int k = 1; k <= K; ++k)
    {
        if (k % Inputs[0] == 0)
        {
            DP[1][k] = k / Inputs[0];
        }
    }

    // 동적 계획법 채우기
    for (int n = 2; n <= N; ++n)
    {
        for (int k = 1; k <= K; ++k)
        {
            if (k - Inputs[n - 1] >= 0)
            {
                if (DP[n][k - Inputs[n - 1]] != INT_MAX)
                {
                    DP[n][k] = min(DP[n][k], DP[n][k - Inputs[n - 1]] + 1);
                }

                if (DP[n-1][k - Inputs[n - 1]] != INT_MAX)
                {
                    DP[n][k] = min(DP[n][k], DP[n - 1][k - Inputs[n - 1]] + 1);
                }
            }
            DP[n][k] = min(DP[n][k], DP[n - 1][k]);
        }
    }

    // 결과 출력
    if (DP[N][K] == INT_MAX)
        cout << -1;
    else
        cout << DP[N][K];

    return 0;
}