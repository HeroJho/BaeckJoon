#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Func
{
public:
    bool operator()(pair<int, int> L, pair<int, int> R)
    {
        return L.second > R.second;
    }
};



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    if (N == 0)
    {
        cout << 0;
        return 0;
    }
    
    vector<pair<int ,int>> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int P, D;
        cin >> P >> D;
        Inputs.push_back({P, D});
    }

    sort(Inputs.begin(), Inputs.end(), Func());

    int Ans = 0;

    priority_queue<int> Qs;
    int Index = 0;
    int Day = Inputs[0].second;
    while (Day)
    {
        // Day에 맞는 넣는다
        while (Index < Inputs.size() && 
            Day == Inputs[Index].second)
        {
            Qs.push(Inputs[Index].first);
            ++Index;
        }

        if (!Qs.empty())
        {
            Ans += Qs.top();
            Qs.pop();
        }

        --Day;

    }

    cout << Ans;


    return 0;
}