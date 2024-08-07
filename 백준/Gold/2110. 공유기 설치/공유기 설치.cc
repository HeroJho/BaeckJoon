#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // i 거리로 설치가 다 되면 크게해서 확인
    // 설치가 안 된다면 작게해서 확인


    int N, C;
    cin >> N >> C;
    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    sort(Inputs.begin(), Inputs.end());

    int Ans = 0;

    int Left = 1, Right = Inputs.back() - Inputs.front();
    while (Left <= Right)
    {
        int Middle = (Left + Right) / 2;

        int Cnt = 1;
        int PreIndex = 0;
        for (int i = 1; i < Inputs.size(); ++i)
        {
            if (Middle <= Inputs[i] - Inputs[PreIndex])
            {
                ++Cnt;
                PreIndex = i;
            }
        }

        // 같거나 더 설치됐다
        if (Cnt >= C)
        {
            Left = Middle + 1;
            Ans = max(Ans, Middle);
        }
        // 덜 설치됐다
        else if(Cnt < C)
        {
            Right = Middle - 1;
        }

    }

    cout << Ans;


    return 0;
}