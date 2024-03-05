#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool DP[2001][2001] = { false };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp; cin >> Temp;
        Inputs.push_back(Temp);
    }
    int M;
    cin >> M;
    vector<pair<int ,int>> Orders;
    for (int i = 0; i < M; ++i)
    {
        pair<int, int> Temp;
        cin >> Temp.first >> Temp.second;
        Orders.push_back(Temp);
    }

    

    for (int i = 0; i < N-1; ++i)
    {
        // 하나는 무조건 true
        DP[i][i] = true;
        // 둘은 두 개가 같으면 true
        DP[i][i + 1] = Inputs[i] == Inputs[i + 1];
    }
    DP[N-1][N-1] = true;

    // i = 간격
    for (int i = 2; i < N; ++i)
    {
        for (int j = 0; j+i < N; ++j)
        {
            DP[j][j+i] = Inputs[j] == Inputs[j+i] && DP[j + 1][j+i - 1];
        }
    }


    for (int i = 0; i < M; ++i)
    {
        cout << DP[Orders[i].first - 1][Orders[i].second - 1] << '\n';
    }


    return 0;
}
