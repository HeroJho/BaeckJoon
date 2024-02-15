#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Func
{
public:
    bool operator()(pair<int ,int> L, pair<int ,int> R)
    {
        return L.second > R.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int ,int>> Inputs;
    for (int i = 0; i < N; ++i)
    {
        pair<int, int> Temp; 
        cin >> Temp.first >> Temp.second;
        Inputs.push_back(Temp);
    }


    sort(Inputs.begin(), Inputs.end());

    int Ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Func> Qs;

    for (int i = 0; i < N; ++i)
    {
        pair<int, int> Cur = Inputs[i];
        if (!Qs.empty())
        {
            pair<int, int> Top = Qs.top();
            if (Top.second <= Cur.first)
            {
                Qs.pop();
            }
        }

        Qs.push(Cur);
        Ans = max(Ans, (int)Qs.size());
    }

    cout << Ans;


    return 0;
}
