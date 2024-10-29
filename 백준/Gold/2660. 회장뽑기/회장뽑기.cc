#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
vector<int> Matrix[51];
int DP[51][51] = { 0 };

void Dij(int Start)
{
    priority_queue<pair<int, int>> Qs;
    Qs.push({0, Start});
    DP[Start][Start] = 0;

    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.top();
        Qs.pop();

        for (int i = 0; i < Matrix[Cur.second].size(); ++i)
        {
            int Nex = Matrix[Cur.second][i];
            int Dis = Cur.first + 1;

            if (DP[Start][Nex] <= Dis)
                continue;
            DP[Start][Nex] = Dis;

            Qs.push({ Dis, Nex });
        }

    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N;
    while(true)
    {
        int Start, End;
        cin >> Start >> End;

        if (Start == -1)
            break;

        Matrix[Start].push_back(End);
        Matrix[End].push_back(Start);
    }


    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            DP[i][j] = INT_MAX;


    for (int i = 1; i <= N; ++i)
    {
        Dij(i);
    }

    int MinDis = INT_MAX;
    for (int i = 1; i <= N; ++i)
    {
        int Max = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                continue;

            if (Max < DP[i][j])
                Max = DP[i][j];
        }

        if (MinDis > Max)
            MinDis = Max;

    }

    vector<int> Temps;
    for (int i = 1; i <= N; ++i)
    {
        int Max = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                continue;

            if (Max < DP[i][j])
                Max = DP[i][j];
        }

        if (MinDis == Max)
            Temps.push_back(i);

    }

    cout << MinDis << ' ' << Temps.size() << '\n';
    for (int i = 0; i < Temps.size(); ++i)
    {
        cout << Temps[i] << ' ';
    }


    return 0;
}