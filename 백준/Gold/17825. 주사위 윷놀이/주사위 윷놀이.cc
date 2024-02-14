#include <iostream>
#include <vector>
#include <queue>

#define MAX 35

using namespace std;


struct Node
{
    
    int NodeNum = 0;
    int Score = 0;
    bool bOther = false;

};

vector<int> g_Inputs;
// vector<Node> g_Nodes;
vector<Node> g_Matrix[MAX];
int g_Hor[4] = { 0 };

int g_Ans = 0;

bool Go(int HorNum, int GoNum, int& Score)
{
    int HorNodeNum = g_Hor[HorNum];
    if (g_Matrix[HorNodeNum].empty())
    {
        Score = 0;
        g_Hor[HorNum] = -1;
        return true;
    }

    Node StartNode = g_Matrix[HorNodeNum][0];
    
    // 두 갈래
    if (g_Matrix[HorNodeNum].size() > 1)
    {
        if (g_Matrix[HorNodeNum][0].bOther)
            StartNode = g_Matrix[HorNodeNum][0];
        else
            StartNode = g_Matrix[HorNodeNum][1];
    }

    for (int i = 0; i < GoNum - 1; ++i)
    {
        int CurNum = StartNode.NodeNum;

        // 도착
        if (g_Matrix[CurNum].empty())
        {
            Score = 0;
            g_Hor[HorNum] = -1;
            return true;
        }
        
        if (g_Matrix[CurNum].size() > 1)
        {
            if (g_Matrix[CurNum][0].bOther)
                StartNode = g_Matrix[CurNum][1];
            else
                StartNode = g_Matrix[CurNum][0];
        }
        else
        {
            StartNode = g_Matrix[CurNum][0];
        }

    }

    Score = StartNode.Score;

    // 도착 지점에 말이 있으면 넘긴다
    for (int i = 0; i < 4; ++i)
    {
        if (i == HorNum)
            continue;

        if (g_Hor[i] == StartNode.NodeNum)
            return false;
    }

    g_Hor[HorNum] = StartNode.NodeNum;

    return true;
}

void DFS(int Depth, int Score, int StartNum)
{
    if (Depth >= 10)
    {
        if (g_Ans < Score)
            g_Ans = Score;

        return;
    }

    for (int i = StartNum; i < 10; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int HorNum = g_Hor[j];
            // 도착한 말이면 넘긴다
            if (HorNum == -1)
                continue;

            int TempScore = 0;
            // j번째 말을 i번째 주사위로 옮긴다
            // 도착 지점에 말이 있으면 넘긴다
            if (!Go(j, g_Inputs[i], TempScore))
                continue;

            DFS(Depth + 1, TempScore + Score, i + 1);

            g_Hor[j] = HorNum;
        }

    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 10; ++i)
    {
        int Temp;
        cin >> Temp;
        g_Inputs.push_back(Temp);
    }

    int Sum = 0;
    for (int i = 1; i < 21; ++i)
    {
        Sum += 2;

        if (Sum > 40)
            break;

        Node Temp;
        Temp.bOther = false;
        Temp.NodeNum = i;
        Temp.Score = Sum;

        g_Matrix[i-1].push_back(Temp);
    }

    // 10번과 21번
    Node Temp;
    Temp.bOther = true;
    Temp.NodeNum = 21;
    Temp.Score = 22;
    g_Matrix[10].push_back(Temp);

    vector<int> Scores = { 24, 25, 30, 35 };
    int ScoreIndex = 0;
    for (int i = 22; i < 26; ++i)
    {
        Node Temp;
        Temp.bOther = false;
        Temp.NodeNum = i;
        Temp.Score = Scores[ScoreIndex];;

        g_Matrix[i - 1].push_back(Temp);
        ++ScoreIndex;
    }

    // 20번과 25 연결
    Temp.bOther = false;
    Temp.NodeNum = 20;
    Temp.Score = 40;
    g_Matrix[25].push_back(Temp);



    // 5번과 26 연결
    Temp.bOther = true;
    Temp.NodeNum = 26;
    Temp.Score = 13;
    g_Matrix[5].push_back(Temp);

    Temp.bOther = false;
    Temp.NodeNum = 27;
    Temp.Score = 16;
    g_Matrix[26].push_back(Temp);
    Temp.bOther = false;
    Temp.NodeNum = 28;
    Temp.Score = 19;
    g_Matrix[27].push_back(Temp);
    Temp.bOther = false;
    Temp.NodeNum = 23;
    Temp.Score = 25;
    g_Matrix[28].push_back(Temp);


    // 15번과 29 연결
    Temp.bOther = true;
    Temp.NodeNum = 29;
    Temp.Score = 28;
    g_Matrix[15].push_back(Temp);

    Temp.bOther = false;
    Temp.NodeNum = 30;
    Temp.Score = 27;
    g_Matrix[29].push_back(Temp);
    Temp.bOther = false;
    Temp.NodeNum = 31;
    Temp.Score = 26;
    g_Matrix[30].push_back(Temp);
    Temp.bOther = false;
    Temp.NodeNum = 23;
    Temp.Score = 25;
    g_Matrix[31].push_back(Temp);


    DFS(0, 0, 0);

    cout << g_Ans;


    return 0;
}
