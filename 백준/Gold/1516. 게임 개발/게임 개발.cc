#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Func
{
public:
    bool operator()(pair<int, int> L, pair<int, int> R)
    {
        return L.second < R.second;
    }
};


int N;
vector<pair<int, int>> Matrix[501];
vector<int> InvMatrix[501];
int DP[501] = { 0 };


bool CanVisited(int Index)
{
    for (int i = 0; i < InvMatrix[Index].size(); ++i)
    {
        int Par = InvMatrix[Index][i];
        if (DP[Par] == -1)
            return false;
    }

    return true;
}

void Dij(vector<int> Starts)
{
    priority_queue<pair<int, int>, vector<pair<int ,int>>, Func> Qs;

    for (int i = 0; i < Starts.size(); ++i)
    {
        Qs.push({ Starts[i], DP[Starts[i]] });
    }

    
    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.top();
        Qs.pop();

        int CurIndex = Cur.first;
        int CurValue = Cur.second;

        for (int i = 0; i < Matrix[CurIndex].size(); ++i)
        {
            int nIndex = Matrix[CurIndex][i].first;
            int nValue = CurValue + Matrix[CurIndex][i].second;

            // 사전 건물들 체크
            //if (!CanVisited(nIndex))
            //    continue;

            if (DP[nIndex] >= nValue)
                continue;
            DP[nIndex] = nValue;

            Qs.push({nIndex, nValue});

        }

    }


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 501; ++i)
    {
        DP[i] = -1;
    }


    vector<int> Starts;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int Value, Next, End;
        cin >> Value >> Next;
        if (Next == -1)
        {
            DP[i] = Value;
            Starts.push_back(i);
            continue;
        }
        else
        {
            Matrix[Next].push_back({ i, Value });
            InvMatrix[i].push_back(Next);

            while (true)
            {
                cin >> End;
                if (End == -1)
                    break;

                Matrix[End].push_back({ i, Value });
                InvMatrix[i].push_back(End);
            }

        }

    }


    Dij(Starts);

    for (int i = 1; i <= N; ++i)
    {
        cout << DP[i] << '\n';
    }

    return 0;
}