#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


int N;
vector<int> Inputs;
int DP[1001] = { 0 };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }


    int Ans = 0;

    DP[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        int Max = 0;
        for (int j = 0; j < i; ++j)
        {
            if (Inputs[j] < Inputs[i])
            {
                if (DP[j] > Max)
                    Max = DP[j];
            }
        }

        DP[i] = Max + 1;
        if (Ans < DP[i])
            Ans = DP[i];
    }

    cout << Ans;

    return 0;
}