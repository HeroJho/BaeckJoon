#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;


class Func
{
public:
    bool operator()(pair<LL, LL> L, pair<LL, LL> R)
    {
        return L.second > R.second;
    }
};

int N, M;
vector<pair<LL, LL>> Matrix[10001];
bool Visited[10001] = { false };
LL DP[10001] = { 0 };

int Go(int Start)
{
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, Func> Qs;
    
    Qs.push({ 1, 0 });


    LL Ans = 0;
    int Cnt = N;
    while (Cnt)
    {
        // 간선 선택
        pair<LL, LL> Top = Qs.top();
        Qs.pop();

        if (Visited[Top.first])
            continue;
        Visited[Top.first] = true;

        Ans += Top.second;
        --Cnt;


        // 연결된 노드 간선 추가
        for (int i = 0; i < Matrix[Top.first].size(); ++i)
        {
            int nNode = Matrix[Top.first][i].first;

            if (Visited[nNode])
                continue;

            Qs.push(Matrix[Top.first][i]);
        }

    }


    return Ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 간선 음수 가능
    // 답은 -INT_MAX보다 높다

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        LL Start, End, Value;
        cin >> Start >> End >> Value;
        Matrix[Start].push_back({ End, Value });
        Matrix[End].push_back({ Start, Value });

    }

    cout << Go(1);

    return 0;
}