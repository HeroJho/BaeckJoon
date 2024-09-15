#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int N;
vector<pair<int, int>> Inputs;

int Ans = INT_MAX;

void DFS(int Start, int S, int D)
{

    for (int i = Start; i < Inputs.size(); ++i)
    {
        int nS = S * Inputs[i].first;
        int nD = D + Inputs[i].second;

        int Dis = abs(nS - nD);
        if (Dis < Ans)
            Ans = Dis;

        DFS(i + 1, nS, nD);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int One, Two;
        cin >> One >> Two;
        Inputs.push_back({One, Two});
    }

    DFS(0, 1, 0);

    cout << Ans;

    return 0;
}