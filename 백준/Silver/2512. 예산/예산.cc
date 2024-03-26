#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> Inputs;

int Cal(int Bu)
{
    int Sum = 0;

    for (int i = 0; i < Inputs.size(); ++i)
    {
        if (Inputs[i] > Bu)
            Sum += Bu;
        else
            Sum += Inputs[i];
    }

    return Sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int Max = 0;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);

        if (Max < Temp)
            Max = Temp;
    }
    cin >> M;

    int Ans = 0;

    int Left = 0;
    int Right = Max;
    while (Left <= Right)
    {
        int Middle = (Left + Right) / 2;


        int Bu = Cal(Middle);
        // 예산이 높다면
        if (Bu > M)
        {// 줄인다
            Right = Middle - 1;
        }
        else if(Bu <= M)  // 예산이 낮다면
        { // 높인다
            Left = Middle + 1;

            Ans = Middle;
        }

    }

    cout << Ans;

    return 0;
}
