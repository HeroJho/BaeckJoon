#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data
{
    int Start, End;
    int Dis;

    Data() : Start(0), End(0), Dis(0) {};
    Data(int start, int end, int dis) : Start(start), End(end), Dis(dis) {};

};

class Func
{
public:
    bool operator()(Data L, Data R)
    {
        return L.Dis > R.Dis;
    }
};

int N, M;
vector<pair<int, int>> Matrix[100001];
vector<pair<int, int>> SPMatrix[100001];
bool Added[100001] = { false };


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int Start, End, V;
        cin >> Start >> End >> V;
        Matrix[Start].push_back({ End, V });
        Matrix[End].push_back({ Start, V });
    }


    // 시작 노드 추가한다
    // 간선을 우선순위 큐에 넣는다
    
    // 짧은 간선을 꺼낸다
    // 연결된 노드를 추가한다

    priority_queue<Data, vector<Data>, Func> Qs;
    for (int i = 0; i < Matrix[1].size(); ++i)
    {
        Qs.push({ 1,Matrix[1][i].first, Matrix[1][i].second });
    }
    Added[1] = true;

    int TotalDis = 0;
    int MaxDis = 0;
    while (!Qs.empty())
    {
        // 제일 작은 간선을 꺼낸다
        Data Top = Qs.top();
        Qs.pop();

        if (Added[Top.End])
            continue;
        
        SPMatrix[Top.Start].push_back({ Top.End, Top.Dis });
        SPMatrix[Top.End].push_back({ Top.Start, Top.Dis });

        if (MaxDis < Top.Dis)
            MaxDis = Top.Dis;
        TotalDis += Top.Dis;

        Added[Top.End] = true;

        // End의 간선을 넣는다
        for (int i = 0; i < Matrix[Top.End].size(); ++i)
        {
            if (Added[Matrix[Top.End][i].first])
                continue;

            Qs.push({ Top.End, Matrix[Top.End][i].first, Matrix[Top.End][i].second });
        }

    }

    // 제일 긴 간선을 하나 뺀다
    TotalDis -= MaxDis;
    cout << TotalDis;

    return 0;
}
