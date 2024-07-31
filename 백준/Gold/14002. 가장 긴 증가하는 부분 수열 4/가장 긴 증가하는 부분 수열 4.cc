#include <iostream>
#include <vector>
#include <climits>

using namespace std;


vector<int> Ways[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    Ways[N - 1].push_back(Inputs[N-1]);
    for (int i = N - 2; i >= 0; --i)
    {
        int MaxCnt = 0;
        int MaxIndex = 0;
        for (int s = i + 1; s < N; ++s)
        {
            if (Inputs[i] < Inputs[s] && MaxCnt < Ways[s].size())
            {
                MaxCnt = Ways[s].size();
                MaxIndex = s;
            }
        }

        Ways[i].push_back(Inputs[i]);
        // 앞에 나보다 큰 수열이 있다
        if (MaxCnt > 0)
        {
            for (int z = 0; z < Ways[MaxIndex].size(); ++z)
            {
                Ways[i].push_back(Ways[MaxIndex][z]);
            }
        }

    }


    int MaxCnt = 0;
    int MaxIndex = 0;
    for (int i = 0; i < N; ++i)
    {
        if (MaxCnt < Ways[i].size())
        {
            MaxCnt = Ways[i].size();
            MaxIndex = i;
        }
    }



    cout << Ways[MaxIndex].size() << '\n';
    for (int i = 0; i < Ways[MaxIndex].size(); ++i)
    {
        cout << Ways[MaxIndex][i] << ' ';
    }


    return 0;
}