#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int DP[1000001] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;

        int Index = i - 1;
        while (!Inputs.empty())
        {
            // 뒤를 확인한다
            pair<int, int> Back = Inputs.back();
            // 뒤가 더 크다
            if (Back.first < Temp)
            {
                Inputs.pop_back();
                DP[Back.second] = Temp;
            }
            else
                break;
        }


        Inputs.push_back({ Temp, i });
    }

    for (int i = 0; i < N; ++i)
    {
        if (DP[i])
            cout << DP[i] << ' ';
        else
            cout << -1 << ' ';
    }


    return 0;
}
