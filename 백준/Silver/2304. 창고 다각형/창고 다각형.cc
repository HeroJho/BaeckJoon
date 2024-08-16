#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


int N;
vector<pair<int, int>> Inputs;

int MaxHIndex = -1;


int GO(bool Flips, stack<pair<int ,int>>& S)
{
    // 높은 애 기준으로 대칭으로 다음 알고리즘을 돌린다.
    int Ans = 0;

    pair<int, int> Pre = S.top();
    S.pop();
    while (!S.empty())
    {
        pair<int, int> Cur = S.top();
        S.pop();

        int DisL = Pre.first - Cur.first;

        if (Flips)
            DisL *= -1;

        Ans += DisL * Pre.second;

        Pre = Cur;
    }

    return Ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int L, H;
        cin >> L >> H;
        Inputs.push_back({ L, H });
    }

    sort(Inputs.begin(), Inputs.end());

    // 제일 높은 애를 찾는다.
    int MaxHIndex = 0;
    int MaxH = 0;
    for (int i = 0; i < N; ++i)
    {
        if (MaxH < Inputs[i].second)
        {
            MaxH = Inputs[i].second;
            MaxHIndex = i;
        }
    }


    int Ans = 0;

    // 우
    stack<pair<int, int>> SR;

    SR.push(Inputs[MaxHIndex]);
    for (int i = MaxHIndex + 1; i < N; ++i)
    {
        int TopH = SR.top().second;
        if (TopH >= Inputs[i].second)
        {
            SR.push(Inputs[i]);
        }
        else
        {
            while (!SR.empty())
            {
                TopH = SR.top().second;

                if (TopH >= Inputs[i].second)
                {
                    SR.push(Inputs[i]);
                    break;
                }

                SR.pop();
            }
        }
    }

    Ans += GO(false, SR);




    stack<pair<int, int>> SL;

    SL.push(Inputs[MaxHIndex]);
    for (int i = MaxHIndex - 1; i >= 0; --i)
    {
        int TopH = SL.top().second;
        if (TopH >= Inputs[i].second)
        {
            SL.push(Inputs[i]);
        }
        else
        {
            while (!SL.empty())
            {
                TopH = SL.top().second;

                if (TopH >= Inputs[i].second)
                {
                    SL.push(Inputs[i]);
                    break;
                }

                SL.pop();
            }

        }

    }

    Ans += GO(true, SL);


    cout << Ans + Inputs[MaxHIndex].second;


    return 0;
}