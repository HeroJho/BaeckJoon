#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<int> Inputs;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    long long Max = 0;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);

        if (Max < Temp)
            Max = Temp;
    }


    long long Ans = 0;

    long long Left = 1, Right = Max * M;
    while (Left <= Right)
    {
        long long Mid = (Left + Right) / 2;

        long long Cnt = 0;
        for (int i = 0; i < Inputs.size(); ++i)
        {
            Cnt += Mid / Inputs[i];
            if (Cnt > M)
                break;
        }

        if (Cnt < M)
        {
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
            Ans = Mid;
        }

    }

    cout << Ans;

    return 0;
}