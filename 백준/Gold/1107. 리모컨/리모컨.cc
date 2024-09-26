#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Input;
    cin >> Input;
    int N;
    cin >> N;
    bool BreakNum[10] = {false};
    for (int i = 0; i < N; ++i)
    {
        int C;
        cin >> C;
        BreakNum[C] = true;
    }

    int MinDis = INT_MAX;
    int DestNum = stoi(Input);
    for (int i = 0; i < 1000001; ++i)
    {
        string S = to_string(i);
        bool Can = true;
        for (int s = 0; s < S.length(); ++s)
        {
            int Num = S[s] - '0';
            if (BreakNum[Num])
            {
                Can = false;
                break;
            }

        }

        if (!Can)
            continue;

        // 만들 수 있는 숫자
        int Min = abs(i - DestNum) + S.length();
        if (Min < MinDis)
            MinDis = Min;
    }


    int Min = abs(100 - DestNum);
    if (Min < MinDis)
        MinDis = Min;

    cout << MinDis;

    return 0;
}