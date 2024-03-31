#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> Inputs;
int DP[1001] = { -1 };

void Reset()
{
    for (int i = 0; i < 1001; ++i)
    {
        DP[i] = -1;
    }
}

void DFS(int Cnt, int Sum)
{
    if (Cnt > N)
        return;

    if (DP[Cnt] >= Sum)
        return;
    DP[Cnt] = Sum;

    for (int i = 1; i <= N; ++i)
    {
        DFS(Cnt + i, Sum + Inputs[i]);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    Inputs.push_back(0);
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    Reset();
    DFS(0, 0);
    
    cout << DP[N];

    return 0;
}
