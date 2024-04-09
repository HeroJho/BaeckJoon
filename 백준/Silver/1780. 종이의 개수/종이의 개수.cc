#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int Matrix[2500][2500] = { 0 };
int Ans[3] = { 0 };

bool Check(pair<int ,int> StartPos, int Dis)
{
    int Num = Matrix[StartPos.second][StartPos.first];
    for (int i = StartPos.second; i < StartPos.second + Dis; ++i)
    {
        for (int j = StartPos.first; j < StartPos.first + Dis; ++j)
        {
            if (Num != Matrix[i][j])
                return false;
        }
    }

    return true;
}

void DFS(pair<int, int> StartPos, int Dis)
{
    // 확인
    if (Check(StartPos, Dis))
    {
        int Num = Matrix[StartPos.second][StartPos.first];
        Num++;
        Ans[Num]++;

        return;
    }

    if (Dis == 1)
    {
        return;
    }

    // 자른다
    pair<int, int> TempPos;
    int TempDis = Dis / 3;

    // 1
    TempPos = StartPos;
    DFS(TempPos, TempDis);
    // 2
    TempPos.first += TempDis;
    DFS(TempPos, TempDis);
    // 3
    TempPos.first += TempDis;
    DFS(TempPos, TempDis);

    TempPos = StartPos;
    TempPos.second += TempDis;
    // 3
    DFS(TempPos, TempDis);
    // 4
    TempPos.first += TempDis;
    DFS(TempPos, TempDis);
    // 5
    TempPos.first += TempDis;
    DFS(TempPos, TempDis);

    TempPos = StartPos;
    TempPos.second += TempDis;
    TempPos.second += TempDis;
    // 3
    DFS(TempPos, TempDis);
    // 4
    TempPos.first += TempDis;
    DFS(TempPos, TempDis);
    // 5
    TempPos.first += TempDis;
    DFS(TempPos, TempDis);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Matrix[i][j];
        }
    }

    DFS({0, 0}, N);

    cout << Ans[0] << endl;
    cout << Ans[1] << endl;
    cout << Ans[2] << endl;


    return 0;
}
