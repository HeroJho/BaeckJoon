#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long DP[91][2] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    DP[1][0] = 0;
    DP[1][1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
        DP[i][1] = DP[i - 1][0];
    }

    cout << DP[N][0] + DP[N][1];

    return 0;
}
