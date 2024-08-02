#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<string> Inputs;
    for (int i = 0; i < N; ++i)
    {
        string Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }
    
    int Max = max(N, M);

    int Ans = 0;
    for (int i = 0; i < Max; ++i)
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                int nY = y + i;
                int nX = x + i;

                if (nX >= M || nY >= N)
                    continue;

                if (Inputs[y][x] == Inputs[nY][x] &&
                    Inputs[y][x] == Inputs[y][nX] &&
                    Inputs[y][x] == Inputs[nY][nX])
                {
                    if ((i+1) * (i + 1) > Ans)
                        Ans = (i + 1) * (i + 1);
                }

            }
        }
    }

    cout << Ans;

    return 0;
}