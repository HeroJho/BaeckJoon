#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


class Func
{
public:
    bool operator()(pair<int, int> L, pair<int, int> R)
    {
        return L.second > R.second;
    }
};

int N, M, Start;
vector<pair<int, int>> Matrix[10001];
int DP[10001] = { INT_MAX };

void Reset()
{
    for (int i = 0; i <= N; ++i)
    {
        Matrix[i].clear();
        DP[i] = INT_MAX;
    }
}

void Dij()
{
    priority_queue<pair<int, int>> Qs;
    Qs.push({Start, 0});
    DP[Start] = 0;

    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.top();
        Qs.pop();

        for (int i = 0; i < Matrix[Cur.first].size(); ++i)
        {
            int Nex = Matrix[Cur.first][i].first;
            int NexValue = Cur.second + Matrix[Cur.first][i].second;

            if (DP[Nex] <= NexValue)
                continue;
            DP[Nex] = NexValue;

            Qs.push({Nex, NexValue});

        }
    }

}

void GoAns()
{
    int Cnt = 0;
    int MaxTime = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (DP[i] == INT_MAX)
            continue;

        ++Cnt;

        if (MaxTime < DP[i])
            MaxTime = DP[i];

    }

    cout << Cnt << ' ' << MaxTime << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N >> M >> Start;

        Reset();

        for (int i = 0; i < M; ++i)
        {
            int End, Start, Value;
            cin >> End >> Start >> Value;
            Matrix[Start].push_back({ End, Value });
        }

        Dij();

        GoAns();

    }



    return 0;
}