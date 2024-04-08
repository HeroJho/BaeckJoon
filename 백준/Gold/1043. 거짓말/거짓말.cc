#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // 진실을 아는 사람이 있는 파티인가?
    //  이 파티 사람들도 진실을 아는 사람들이 된다
    // 아닌가?


    // 진실을 아는 사람들이 있는 파티를 우선으로 얘기
    // 

    bool True[51] = { false };

    int N, M;
    cin >> N >> M;
    
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int Temp;
        cin >> Temp;
        True[Temp] = true;
    }

    list<vector<int>> Party;
    for (int i = 0; i < M; ++i)
    {
        int Cnt;
        cin >> Cnt;
        vector<int> Temps;
        bool bIsTrue = false;
        for (int c = 0; c < Cnt; ++c)
        {
            int Temp;
            cin >> Temp;
            Temps.push_back(Temp);

            if (True[Temp] == true)
                bIsTrue = true;

        }

        if (bIsTrue == false)
        {
            Party.push_back(Temps);
        }
        else
        {
            for (int c = 0; c < Cnt; ++c)
            {
                True[Temps[c]] = true;
            }
        }

    }



    while (true)
    {
        bool bEnd = true;
        for (auto iter = Party.begin(); iter != Party.end();)
        {
            bool bIsTrue = false;
            for (int i = 0; i < (*iter).size(); ++i)
            {
                int Temp = (*iter)[i];
                if (True[Temp] == true)
                {
                    bIsTrue = true;
                    bEnd = false;
                    break;
                }
            }

            if (bIsTrue == true)
            {
                for (int i = 0; i < (*iter).size(); ++i)
                {
                    int Temp = (*iter)[i];
                    True[Temp] = true;
                }

                iter = Party.erase(iter);

            }
            else
                ++iter;

        }

        if (bEnd == true)
            break;

    }


    cout << Party.size();


    return 0;
}
