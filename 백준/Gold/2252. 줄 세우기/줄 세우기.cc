#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> InDegree, Result;
vector<vector<int>> Graph;

void TopologySort()
{
    queue<int> Q;

    for (int i = 1; i <= N; i++)
    {
        if (InDegree[i] == 0)
            Q.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (Q.empty())
            return;

        int Cur = Q.front();
        Result[i] = Cur;
        Q.pop();

        for (int k = 0; k < Graph[Cur].size(); k++)
        {
            int Next = Graph[Cur][k];
            if (--InDegree[Next] == 0)
                Q.push(Next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    InDegree.assign(N + 1, 0);
    Result.assign(N + 1, 0);
    Graph.assign(N + 1, vector<int>(0, 0));

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        Graph[A].emplace_back(B);
        InDegree[B]++;
    }


    TopologySort();



    for (int i = 0; i < N; i++)
    {
        cout << Result[i] << " ";
    }

    return 0;
}