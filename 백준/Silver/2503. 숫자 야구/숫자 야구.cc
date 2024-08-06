#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;


bool CheckZero(string& S)
{
    for (int i = 0; i < S.length(); ++i)
    {
        if ('0' == S[i])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool Check[1000] = { false };

    for (int i = 0; i < 1000; ++i)
        Check[i] = true;

    int N;
    cin >> N;

    vector<pair<int, pair<int, int>>> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Inputs.push_back({ A,{B,C} });
    }


    for (int i = 111; i <= 999; ++i)
    {
        string Ss = to_string(i);

        if (CheckZero(Ss))
        {
            Check[i] = false;
            continue;
        }

        if(Ss[0] == Ss[1] || Ss[1] == Ss[2] || Ss[0] == Ss[2])
        {
            Check[i] = false;
            continue;
        }

        for (int o = 0; o < Inputs.size(); ++o)
        {
            int CurNum = Inputs[o].first;
            int S = Inputs[o].second.first;
            int B = Inputs[o].second.second;
            
            string sCurNum = to_string(CurNum);
            // 볼 확인
            int TempS = 0;
            int TempB = 0;
            
            for (int z = 0; z < 3; ++z)
            {
                for (int h = 0; h < 3; ++h)
                {
                    if (z == h)
                    {
                        if (sCurNum[z] == Ss[h])
                            ++TempS;
                    }
                    else
                    {
                        if (sCurNum[z] == Ss[h])
                            ++TempB;
                    }

                }
            }

            if (S != TempS || B != TempB)
                Check[i] = false;

        }
    }

    int Ans = 0;
    for (int i = 111; i <= 999; ++i)
    {
        if (Check[i])
            ++Ans;
    }

    cout << Ans;

    return 0;
}