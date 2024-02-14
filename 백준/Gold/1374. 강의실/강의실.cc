#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Func
{
public:
    bool operator()(pair<int, int> Left, pair<int, int> Right)
    {
        return Left.second > Right.second;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;
    vector<pair<int, int>> Inputs;
    // 시작 순으로 정렬
    for (int i = 0; i < N; ++i)
    {
        pair<int, int> Temp;
        cin >> Temp.first;
        cin >> Temp.first >> Temp.second;
        Inputs.push_back(Temp);
    }

    sort(Inputs.begin(), Inputs.end());

    int Ans = 0;

    // Q 끝나는 시간으로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, Func> Qs;

    for (int i = 0; i < N; ++i)
    {
        pair<int ,int> Cur = Inputs[i];
        
        // Q를 확인
        if (!Qs.empty())
        {
            pair<int, int> Top = Qs.top();
            // 끝나는 방이 있다
            if (Cur.first >= Top.second)
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
