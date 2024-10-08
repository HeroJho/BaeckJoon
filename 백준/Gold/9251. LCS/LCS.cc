#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int DP[1001][1001] = {0};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string A, B;
    cin >> A >> B;

    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (A[i - 1] == B[j - 1]) 
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else 
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
        
    cout << DP[A.length()][B.length()] << '\n';


    return 0;
}