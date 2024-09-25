#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int DP[1500005] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector <pair<int, int>> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Start, End;
        cin >> Start >> End;
        Inputs.push_back({ Start, End });
    }

    for (int day = N; day >= 1; --day)
    {
        pair<int, int> Cur = Inputs[day-1];
        // 
        if (day + Cur.first - 1 > N)
            DP[day] = DP[day + 1];
        else
        {
            // 다음꺼나, first일 뒤
            DP[day] = max(DP[day+1], DP[day + Cur.first] + Cur.second);
        }
    }

    cout << DP[1];


    return 0;
}