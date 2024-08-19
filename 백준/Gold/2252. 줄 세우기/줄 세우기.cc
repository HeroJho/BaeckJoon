#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> Matrix[32002];
int InNode[32002] = { 0 };

vector<int> Ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;
        Matrix[Start].push_back(End);
        ++InNode[End];
    }

    queue<int> Qs;
    // 진입차수가 0인 정점을 모두 넣는다
    for (int i = 1; i <= N; ++i)
    {
        if (InNode[i] == 0)
            Qs.push(i);
    }

    // 반복한다
    while (!Qs.empty())
    {
        int Cur = Qs.front();
        Qs.pop();

        Ans.push_back(Cur);

        for (int i = 0; i < Matrix[Cur].size(); ++i)
        {
            int Next = Matrix[Cur][i];
            --InNode[Next];
            if (InNode[Next] == 0)
                Qs.push(Next);
        }

    }

    for (int i = 0; i < Ans.size(); ++i)
    {
        cout << Ans[i] << ' ';
    }

    return 0;
}
