#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TimeTest[100000];
    for(int i = 0; i < 100000; ++i)
    {
        TimeTest[i] = i;
    }
    

    int N, M;
    cin >> N >> M;
    vector<int> Times;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Times.push_back(Temp);
    }

  
    sort(Times.begin(), Times.end());

    long long Ans = 0;

    long long Left = Times[0];
    long long Right = M * (long long)Times.back();

    while (Left <= Right)
    {
        long long Mid = (Right + Left) / 2;
        long long TempM = 0;

        // 현재 시간 기준으로 심사위원들이 몇명을 처리하는지 확인
        for (int i = 0; i < Times.size(); ++i)
        {
            TempM += (Mid / (long long)Times[i]);

            // 오버플로 방지
            if (M < TempM)
                break;
        }

        // 현재 값 보다 많은 사람을 처리할 수 있을 경우
        if (TempM >= M)
        {
            Right = Mid - 1;
            Ans = Mid;
        }
        // 현재 값보다 적은 사람을 처리할 수 있을 경우
        else
        {
            Left = Mid + 1;
        }

    }

    cout << Ans;

    return 0;
}