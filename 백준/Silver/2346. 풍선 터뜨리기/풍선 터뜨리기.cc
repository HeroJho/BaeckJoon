#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(string word) {
    int answer = 0;
    return answer;
}

bool Visited[1001] = { false };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> Inputs;
    Inputs.push_back(0);
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    vector<int> Anss;
    Anss.push_back(1);

    int MoveNum = Inputs[1];
    int CurPos = 1;
    Visited[1] = true;

    int Cnt = 1;
    while (Cnt < N)
    {
        // 이동한다
        if (MoveNum > 0)
        {
            --MoveNum;
            while (true)
            {
                CurPos = CurPos + 1;
                if (CurPos > N)
                    CurPos = 1;

                if (!Visited[CurPos])
                    break;                
            }
        }
        else if(MoveNum < 0)
        {
            ++MoveNum;
            while (true)
            {
                CurPos = CurPos - 1;
                if (CurPos < 1)
                    CurPos = N;

                if (!Visited[CurPos])
                    break;
            }
        }
        else
        {
            Visited[CurPos] = true;
            MoveNum = Inputs[CurPos];
            Anss.push_back(CurPos);

            ++Cnt;
        }

    }


    for (int i = 0; i < Anss.size(); ++i)
    {
        cout << Anss[i] << ' ';
    }


    return 0;
}
