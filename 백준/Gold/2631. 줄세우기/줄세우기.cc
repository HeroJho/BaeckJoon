#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Child[201] = { 0 };

int Result = 0;
int DP[201] = { 0 };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Child[i];
        DP[i] = 1;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (Child[j] < Child[i])
                DP[i] = max(DP[i], DP[j] + 1);
            Result = max(Result, DP[i]);
        }
    }

    cout << N - Result;

    return 0;
}