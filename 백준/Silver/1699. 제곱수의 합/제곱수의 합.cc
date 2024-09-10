#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int DP[100001];
    for (int i = 0; i <= N; ++i) 
        DP[i] = i;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j * j <= i; ++j)
        {
            DP[i] = min(DP[i], DP[i - j * j] + 1);
        }
    }

    cout << DP[N];

    return 0;
}