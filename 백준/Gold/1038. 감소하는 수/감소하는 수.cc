#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
long long DP[1000500] = { 0 };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    queue<long long> Qs;
    for (int i = 1; i <= 9; ++i)
    {
        Qs.push(i);
        DP[i] = i;
    }

    if (0 <= N && N <= 10)
    {
        cout << N;
        return 0;
    }

    int Idx = 10;
    while (Idx <= N && !Qs.empty())
    {
        long long Number = Qs.front();
        Qs.pop();

        int Last = Number % 10;
        for (int i = 0; i < Last; ++i)
        {
            long long NexNum = Number * 10 + i;
            Qs.push(NexNum);
            DP[Idx] = NexNum;

            ++Idx;
        }

    }

    if (Idx >= N && DP[N] != 0)
        cout << DP[N];
    else
        cout << -1;



    return 0;
} 