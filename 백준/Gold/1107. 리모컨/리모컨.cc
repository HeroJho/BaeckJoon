#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

bool DoesMakes[1000001] = { false };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int Num = 0;
    cin >> Num;

    int N;
    cin >> N;
    bool Brok[10] = {false};
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Brok[Temp] = true;
    }

    // 제일 차가 작은 수
    int ButtonCnt = INT_MAX;
    for (int i = 0; i < 1000001; ++i)
    {
        string sNum = to_string(i);
        bool DoesMake = true;
        for (int s = 0; s < sNum.length(); ++s)
        {
            int iNum = sNum[s] - '0';
            if (Brok[iNum])
            {
                DoesMake = false;
                break;
            }
        }

        // 만들 수 있는 숫자
        if (DoesMake)
        {
            // DoesMakes[i] = true;
            int TotalCnt = sNum.length() + abs(Num - i);
            if (TotalCnt < ButtonCnt)
                ButtonCnt = TotalCnt;
        }
    }


    // 100 부터 했을 경우
    int TotalCnt = abs(100 - Num);
    if (TotalCnt < ButtonCnt)
        ButtonCnt = TotalCnt;


    cout << ButtonCnt;
    

    return 0;
}
