#include <iostream>
#include <vector>

using namespace std;

int N;
int Inputs[2001] = { 0 };

bool DP[2001][2001] = { false };


bool IsIn(int X, int Y)
{
    return X >= 0 && X < N&& Y >= 0 && Y < N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Inputs[i];
    }

    int M;
    cin >> M;
    vector<pair<int, int>> Orders;
    for (int i = 0; i < M; ++i)
    {
        int S, E;
        cin >> S >> E;
        Orders.push_back({ S-1, E-1 });
    }

    //  4 1
    // 0 / 3
    // DP[n][i] = DP[n-2][i] && Inputs[i-(n/2)] == Inputs[i+(n/2)]  홀수
    // DP[n][i] = DP[n-2][i] && Inputs[i-(n/2)] == Inputs[i+(n/2) + 1]  짝수
    for (int i = 0; i < N; ++i)
    {
        DP[0][i] = true;
        DP[1][i] = true;
    }


    for (int n = 2; n <= N; ++n)
    {
        for (int i = 0; i < N; ++i)
        {
            int Left, Right;
            Left = i - (n / 2);
            Right = i + (n / 2);
            if (n % 2 == 0)
                Left += 1;

            if (!IsIn(Left, Right))
                continue;

            DP[n][i] = DP[n - 2][i] && (Inputs[Left] == Inputs[Right]);
            
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int Dis = Orders[i].second - Orders[i].first + 1;
        int Middle = (Orders[i].second + Orders[i].first) / 2;

        cout << DP[Dis][Middle] << '\n';
    }


    return 0;
}