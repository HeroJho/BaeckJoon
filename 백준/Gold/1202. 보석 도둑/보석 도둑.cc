#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

class Func
{
public:
    bool operator() (int X, int Y)
    {
        return X < Y;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> Jus;
    for (int i = 0; i < N; ++i)
    {
        int M, V;
        cin >> M >> V;

        Jus.push_back({M, V});
    }

    vector<int> Backs;
    for (int i = 0; i < K; ++i)
    {
        int Temp;
        cin >> Temp;

        Backs.push_back(Temp);
    }


    priority_queue<int, vector<int>, Func> Qs;

    // 가방 오름차순
    sort(Backs.begin(), Backs.end());
    // 보석 무게 오름차순
    sort(Jus.begin(), Jus.end());

    long long Ans = 0;
    int Index = 0;
    for (int i = 0; i < Backs.size(); ++i)
    {
        int CurBack = Backs[i];

        // 해당 가방에 넣을 수 있다면 Q에 다 넣는다       
        
        while (Index < Jus.size())
        {
            if (CurBack >= Jus[Index].first)
            {
                Qs.push(Jus[Index].second);
                ++Index;
            }
            else
            {
                break;
            }
        }

        // 제일 큰 보석을 꺼낸다
        if (!Qs.empty())
        {
            int Top = Qs.top();
            Qs.pop();

            Ans += Top;
        }

    }

    cout << Ans;


    return 0;
}