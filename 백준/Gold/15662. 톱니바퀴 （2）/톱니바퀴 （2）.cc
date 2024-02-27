#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<string> Inputs;
vector<pair<int, int>> RollInfos;

// 돌리는 함수
void Roll(string& sS, int Dir)
{
    if (Dir == 1)
    {
        // 1001
        // 1100  시계
        int Last = sS.back();
        for (int i = sS.length() - 2; i >= 0; --i)
        {
            sS[i + 1] = sS[i];
        }
        sS.front() = Last;
    }
    else
    {   // 1001
        // 0011
        int First = sS.front();
        for (int i = 1; i < sS.length(); ++i)
        {
            sS[i - 1] = sS[i];
        }
        sS.back() = First;
    }
}

void Go(int Index, int PreIndex, int Dir)
{


    // 2 6
    // 2 = 뒤
    // 6 = 앞

    // 내 앞 뒤 인덱스 애들 돌린다
    int Front = Index - 1;
    if (PreIndex != Front && Front >= 0 && Front < N)
    {
        // 나의 앞
        if (Inputs[Index][6] != Inputs[Front][2])
        {
            // 반대로 돌린다
            Go(Front, Index, Dir * -1);
        }

    }

    int Back = Index + 1;
    if (PreIndex != Back && Back >= 0 && Back < N)
    {
        if (Inputs[Index][2] != Inputs[Back][6])
        {
            Go(Back, Index, Dir * -1);
        }

    }

    // 현재 돌린다
    Roll(Inputs[Index], Dir);
}

int CheckAns()
{
    int Count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (Inputs[i][0] == '1')
            ++Count;
    }

    return Count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string sTemp;
        cin >> sTemp;
        Inputs.push_back(sTemp);
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        pair<int, int> Temp;
        cin >> Temp.first >> Temp.second;
        RollInfos.push_back(Temp);
    }
    

    for (int i = 0; i < M; ++i)
    {
        pair<int, int> Info = RollInfos[i];
        Go(Info.first - 1, -1, Info.second);
    }


    cout << CheckAns();


    return 0;
}
