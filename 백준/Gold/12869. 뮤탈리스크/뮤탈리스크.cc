#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N;
int DP[61][61][61] = { INT_MAX };
int Ans = INT_MAX;

void  Reset()
{
    for (int i = 0; i < 61; ++i)
    {
        for (int j = 0; j < 61; ++j)
        {
            for (int k = 0; k < 61; ++k)
            {
                DP[i][j][k] = INT_MAX;
            }
        }
    }
}

void DFS(int One, int Two, int Three, int Count)
{
    if (One < 0)
        One = 0;
    if (Two < 0)
        Two = 0;
    if (Three < 0)
        Three = 0;

    // 이미 해당 상태를 만들기 위해 더 낮게 한 적이 있다
    if (DP[One][Two][Three] <= Count)
        return;
    DP[One][Two][Three] = Count;

    if (One == 0 && Two == 0 && Three == 0)
    {
        if (Ans > Count)
            Ans = Count;
        return;
    }


    DFS(One - 9, Two - 3, Three - 1, Count + 1);
    DFS(One - 9, Two - 1, Three - 3, Count + 1);

    DFS(One - 3, Two - 9, Three - 1, Count + 1);
    DFS(One - 1, Two - 9, Three - 3, Count + 1);

    DFS(One - 3, Two - 1, Three - 9, Count + 1);
    DFS(One - 1, Two - 3, Three - 9, Count + 1);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int Temp[3] = { 0 };
    for (int i = 0; i < N; ++i)
    {
        cin >> Temp[i];
    }

    Reset();

    DFS(Temp[0], Temp[1], Temp[2], 0);

    cout << Ans;

    return 0;
}
