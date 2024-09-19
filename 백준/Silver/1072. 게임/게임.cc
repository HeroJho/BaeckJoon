#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long X, Y;
    cin >> X >> Y;

    long long Z = 100.0 * Y / X;
    
    if (Z >= 99)
    {
        cout << -1;
        return 0;
    }
        

    long long Ans = 0;

    long long Left = 1, Right = 1000000000;
    while (Left <= Right)
    {
        long long Mid = (Left + Right) / 2;

        long long nX, nY;
        nX = X + Mid;
        nY = Y + Mid;

        long long nZ = 100.0 * nY / nX;

        // 작거나 같다면 높인다
        if (nZ <= Z)
        {
            Left = Mid + 1;
        }
        else // 크다면 좁힌다
        {
            Right = Mid - 1;
            Ans = Mid;
        }

        
    }

    cout << Ans;

    return 0;
}