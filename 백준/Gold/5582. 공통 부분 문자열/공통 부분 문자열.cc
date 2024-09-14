#include <iostream>
#include <string>
#include <cmath>

using namespace std;


string A, B;
int DP[4001][4001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B;

    int Ans = 0;
    for (int i = 1; i <= A.length(); ++i)
    {
        for (int j = 1; j <= B.length(); ++j)
        {
            if (A[i-1] == B[j-1])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }

            if (Ans < DP[i][j])
                Ans = DP[i][j];
        }
    }

    cout << Ans;

    return 0;
}