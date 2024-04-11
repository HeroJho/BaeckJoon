#include <iostream>
#include <vector>
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

int N, M;
int Matrix[1001][1001] = { 0 };
bool Visited[1001] = { false };

int Go()
{
    // 노드, 간선 길이
    priority_queue<pair<int, int>, vector<pair<int ,int>>, Func> Qs;
    Qs.push({1, 0});

    int Sum = 0;
    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.top();
        Qs.pop();

        if (Visited[Cur.first])
            continue;
        Visited[Cur.first] = true;

        Sum += Cur.second;

        for (int i = 1; i <= N; ++i)
        {
            if (Matrix[Cur.first][i] == 0)
                continue;

            if (Visited[i])
                continue;

            Qs.push({i, Matrix[Cur.first][i]});

        }

    }

    return Sum;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int Start, End, Value;
        cin >> Start >> End >> Value;

        //if (Start == End)
        //    continue;

        Matrix[Start][End] = Value;
        Matrix[End][Start] = Value;
    }

    cout << Go();

    return 0;
}
