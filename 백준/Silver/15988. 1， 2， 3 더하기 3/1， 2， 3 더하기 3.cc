#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


long long DP[1000010] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;
        for (int i = 4; i <= N; ++i)
        {
            DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % 1000000009;
        }

        cout << DP[N] << '\n';
    }

    return 0;
}