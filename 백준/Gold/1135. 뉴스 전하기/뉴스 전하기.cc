#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> Matrix[50];


int DFS(int CurNode)
{
    priority_queue<int> Qs;
    for (int i = 0; i < Matrix[CurNode].size(); ++i)
    {
        int NexNode = Matrix[CurNode][i];

        int Time = DFS(NexNode);
        Qs.push(Time);
    }

    int Cnt = 0;
    int MaxTime = 0;
    while (!Qs.empty())
    {
        ++Cnt;
        int Time = Qs.top() + Cnt;
        Qs.pop();

        if (MaxTime < Time)
            MaxTime = Time;
    }

    return MaxTime;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int Temp;
    cin >> Temp;
    for (int i = 1; i < N; ++i)
    {
        cin >> Temp;
        Matrix[Temp].push_back(i);
    }

    cout << DFS(0);

    return 0;
}