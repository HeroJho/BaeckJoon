#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int N, M;
vector<int> Ms;
vector<int> Vs;

int DP[101][10001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // DP[i][j] : i번째 앱까지 확인했을 때 j의 비용으로 얻을 수 있는 최대 메모리
    // DP[i][j] = DP[i-1][j], DP[i][j - Vi] + Mi


    cin >> N >> M;
    
    Ms.push_back(-1);
    Vs.push_back(-1);

    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Ms.push_back(Temp);
    }
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Vs.push_back(Temp);
    }


    for (int n = 1; n <= N; ++n)
    {
        for (int v = 0; v < 10001; ++v)
        {
            if(v - Vs[n] >= 0)
                DP[n][v] = max(DP[n - 1][v], DP[n - 1][v - Vs[n]] + Ms[n]);
            else
                DP[n][v] = DP[n - 1][v];

        }
    }


    for (int v = 0; v < 10001; ++v)
    {
        if (DP[N][v] >= M)
        {
            cout << v;
            break;
        }
    }


    return 0;
}