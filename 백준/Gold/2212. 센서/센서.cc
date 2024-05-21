#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N, K;
    cin >> N >> K;
    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    sort(Inputs.begin(), Inputs.end());

    priority_queue<int> Qs;
    for (int i = 1; i < N; ++i)
    {
        if (Inputs[i] == Inputs[i - 1])
            continue;

        int Dis = abs(Inputs[i] - Inputs[i - 1]);
        Qs.push(Dis);
    }

    for (int i = 0; i < K-1; ++i)
    {
        if(!Qs.empty())
            Qs.pop();
    }

    int Ans = 0;
    while (!Qs.empty())
    {
        Ans += Qs.top();
        Qs.pop();
    }

    cout << Ans;

    return 0;
}