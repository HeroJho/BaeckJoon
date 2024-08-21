#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


int Ccw(pair<int, int> P1, pair<int, int> P2, pair<int, int> P3) 
{
    int S = P1.first * P2.second + P2.first * P3.second + P3.first * P1.second
    - (P1.second * P2.first + P2.second * P3.first + P3.second * P1.first);

    if (S > 0) 
        return 1;
    else if (S == 0) 
        return 0;
    else 
        return -1;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pair<int, int> P1, P2, P3;
    cin >> P1.first >> P1.second;
    cin >> P2.first >> P2.second;
    cin >> P3.first >> P3.second;

    cout << Ccw(P1, P2, P3);

    return 0;
}