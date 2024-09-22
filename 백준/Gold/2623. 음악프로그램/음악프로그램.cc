#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


int N, M;

vector<int> Matrix[1001];
int DP[1001] = { 0 };



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int Z, PreTemp = -1;
        cin >> Z;
        for (int z = 0; z < Z; ++z)
        {
            int Temp;
            cin >> Temp;
            if (PreTemp == -1)
            {
                PreTemp = Temp;
                continue;
            }

            Matrix[PreTemp].push_back(Temp);
            PreTemp = Temp;
            ++DP[Temp];
        }
    }


    // 자식 없는 애 출력
    // DP[i] == 0
    // i가 가리키는 애들 DP 낮춤
    int Cnt = N;

    vector<int> Anss;
    while (Cnt > 0)
    {
        vector<int> Temps;
        bool bIsZero = false;
        for (int i = 1; i <= N; ++i)
        {
            if (DP[i] == 0)
            {
                Anss.push_back(i);
                DP[i] = -1;
                Temps.push_back(i);
                --Cnt;
                bIsZero = true;
            }
        }

        if (bIsZero == false)
        {
            cout << 0;
            return 0 ;
        }


        for (int i = 0; i < Temps.size(); ++i)
        {
            int Cur = Temps[i];
            for (int j = 0; j < Matrix[Cur].size(); ++j)
            {
                --DP[Matrix[Cur][j]];
            }
        }
    }

    for (int i = 0; i < Anss.size(); ++i)
    {
        cout << Anss[i] << '\n';
    }


    return 0;
}