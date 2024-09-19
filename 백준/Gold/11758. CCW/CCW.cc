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


    pair<int, int> P1, P2, P3;
    cin >> P1.first >> P1.second;
    cin >> P2.first >> P2.second;
    cin >> P3.first >> P3.second;

    pair<int, int> A, B;
    A.first = P2.first - P1.first;
    A.second = P2.second - P1.second;
    B.first = P3.first - P1.first;
    B.second = P3.second - P1.second;

    int S = A.second * B.first - A.first * B.second;
    if (S == 0)
        cout << 0;
    else if (S > 0)
        cout << -1;
    else if (S < 0)
        cout << 1;


    return 0;
}