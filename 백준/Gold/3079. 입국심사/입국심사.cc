#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long Solution(int M, vector<int>& Times) 
{
    long long Ans = 0;

    sort(Times.begin(), Times.end());

    long long Left = Times[0];
    long long Right = M * (long long)Times.back();

    
    
    // 최대값과 최소값이 바뀌는 구간이 가장 최소 시간이다.
    while (Left <= Right)
    {
        long long Mid = (Right + Left) / 2;
        long long TempM = 0;

        // 현재 시간 기준으로 심사위원들이
        // 몇명을 처리하는지 확인하는 부분
        for (int i = 0; i < Times.size(); ++i) 
        {
            TempM += (Mid / (long long)Times[i]);
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

    return Ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N, M;
    cin >> N >> M;
    vector<int> Times;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Times.push_back(Temp);
    }

    cout << Solution(M, Times);


    return 0;
}