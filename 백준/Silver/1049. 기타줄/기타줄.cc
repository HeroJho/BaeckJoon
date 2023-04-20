#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    // N 끊어진 기타줄, M 기타 브랜드
    // P 6개 가격, A 한 개 가격
    int N, M; cin >> N; cin >> M;
    int MP = 2000; int MA = 2000;
    for (int i = 0; i < M; ++i)
    {
        int P, A;
        cin >> P >> A;
        if (P < MP)
        {
            MP = P;
        }
        if (A < MA)
        {
            MA = A;
        }
    }


    // 낱개로 다 산다
    int iResult = MA * N;
    // 패키지로 한 번씩 사본다.
    int iTempN = N;
    int iPCount = 0;
    while (1)
    {
        int iTempResult = 0;

        iTempN -= 6;
        ++iPCount;

        if (iTempN >= 0)
            iTempResult = MA * iTempN + MP * iPCount;
        else
            iTempResult = MP * iPCount;

        if (iResult > iTempResult)
        {
            iResult = iTempResult;
        }

        if (0 >= iTempN)
        {
            break;
        }
    }

    cout << iResult;

    return 0;
}