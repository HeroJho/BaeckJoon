#include <iostream>
#include <vector>

using namespace std;


int N;
vector<int>Inputs[1000001];
bool Visited[1000001] = { false };
int DP[1000001][2] = { 0 };

void DFS(int Cur)
{

    DP[Cur][0] = 1; 
    DP[Cur][1] = 0;

    for (int i = 0; i < Inputs[Cur].size(); ++i)
    {
        int Sub = Inputs[Cur][i];
        if (Visited[Sub])
            continue;
        Visited[Sub] = true;

        DFS(Sub);

        DP[Cur][1] += DP[Sub][0];
        DP[Cur][0] += min(DP[Sub][0], DP[Sub][1]);
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N;
    for (int i = 0; i < N-1; ++i)
    {
        int Start, End;
        cin >> Start >> End;
        Inputs[Start].push_back(End);
        Inputs[End].push_back(Start);
    }

    Visited[1] = true;
    DFS(1);

    cout << min(DP[1][0], DP[1][1]);

    return 0;
}