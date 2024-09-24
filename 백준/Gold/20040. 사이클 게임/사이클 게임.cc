#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


int Parent[500001] = { 0 };

int FindParent(int Num)
{
    if (Parent[Num] == Num)
        return Num;

    Parent[Num] = FindParent(Parent[Num]);

    return Parent[Num];
}

bool Join(int First, int Second)
{
    int Num1 = FindParent(First);
    int Num2 = FindParent(Second);

    if (Num1 == Num2)
        return true;
    
    if (Num1 > Num2)
        Parent[Num1] = Num2;
    else
        Parent[Num2] = Num1;


    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        Parent[i] = i;
    }

    vector<pair<int, int>> Inputs;
    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;

        Inputs.push_back({ Start, End});

    }



    int Cnt = 0;
    for (int i = 0; i < M; ++i)
    {
        ++Cnt;

        bool IsS = Join(Inputs[i].first, Inputs[i].second);
        // 서클이냐
        if (IsS)
        {
            cout << Cnt;
            return 0;
        }

    }


    cout << 0;



    return 0;
}