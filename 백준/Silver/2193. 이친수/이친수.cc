#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
long long DP[91][2] = { 0 };

long long DFS(int Depth, int CurNum)
{
    if (Depth >= N)
        return 1;

    if (DP[Depth][CurNum] != 0)
        return DP[Depth][CurNum];

    // 0
    DP[Depth][CurNum] += DFS(Depth + 1, 0);
    // 1
    if(CurNum == 0)
        DP[Depth][CurNum] += DFS(Depth + 1, 1);

    return DP[Depth][CurNum];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    cout << DFS(1, 1);

    // cout << DP[0][1];

    return 0;
}
