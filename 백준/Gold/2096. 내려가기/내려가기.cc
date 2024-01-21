#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int g_DP[100001][3] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제일 큰 거 먼저 붙인다
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> g_DP[i][0] >> g_DP[i][1] >> g_DP[i][2];
    }


    int MaxTemp[3] = { g_DP[0][0], g_DP[0][1],g_DP[0][2] };
    int MinTemp[3] = { g_DP[0][0], g_DP[0][1],g_DP[0][2] };
    
    for (int i = 1; i < N; ++i)
    {
        int Temp[3] = { MaxTemp[0], MaxTemp[1],MaxTemp[2] };
        MaxTemp[0] = g_DP[i][0] + max(Temp[0], Temp[1]);
        MaxTemp[1] = max(Temp[0], Temp[1]);
        MaxTemp[1] = g_DP[i][1] + max(MaxTemp[1], Temp[2]);
        MaxTemp[2] = g_DP[i][2] + max(Temp[1], Temp[2]);


        int Temp1[3] = { MinTemp[0], MinTemp[1],MinTemp[2] };

        MinTemp[0] = g_DP[i][0] + min(Temp1[0], Temp1[1]);
        MinTemp[1] = min(Temp1[0], Temp1[1]);
        MinTemp[1] = g_DP[i][1] + min(MinTemp[1], Temp1[2]);
        MinTemp[2] = g_DP[i][2] + min(Temp1[1], Temp1[2]);

    }


    int Max = max(MaxTemp[0], MaxTemp[1]);
    Max = max(Max, MaxTemp[2]);
    int Min = min(MinTemp[0], MinTemp[1]);
    Min = min(Min, MinTemp[2]);

    cout << Max << " " << Min;


    return 0;
}
