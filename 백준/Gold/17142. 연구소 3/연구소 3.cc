#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;


int N, M;
int Matrix[51][51] = { 0 };

int TempMatrix[51][51] = { 0 };
int Visited[51][51] = { false };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

void Reset()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Visited[i][j] = false;
            TempMatrix[i][j] = Matrix[i][j];
        }
    }
}

bool IsIn(int InX, int InY)
{
    return InX >= 0 && InX < N && InY >= 0 && InY < N;
}

bool IsFull()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (TempMatrix[i][j] == 0)
                return false;
        }
    }

    return true;
}

int BFS(vector<pair<int, int>>& StartPoss)
{
    Reset();

    queue<pair<int, int>> Qs;
    
    for (int i = 0; i < StartPoss.size(); ++i)
    {
        Qs.push(StartPoss[i]);
        Visited[StartPoss[i].second][StartPoss[i].first] = 8;
    }

    int Time = 0;
    if (IsFull())
        return Time;

    while (!Qs.empty())
    {
        int Size = Qs.size();

        ++Time;

        for (int s = 0; s < Size; ++s)
        {
            pair<int, int> Cur = Qs.front();
            Qs.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nX = Cur.first + DirX[i];
                int nY = Cur.second + DirY[i];

                if (!IsIn(nX, nY))
                    continue;

                if (TempMatrix[nY][nX] == 1)
                    continue;

                if (Visited[nY][nX])
                    continue;
                Visited[nY][nX] = Time;

                TempMatrix[nY][nX] = 2;

                if (IsFull())
                    return Time;

                Qs.push({ nX, nY });

            }

        }

    }

    return INT_MAX;
}

// 조합 중복x
vector<pair<int, int>> BPoss;
vector<pair<int, int>> Temp;
 
int MaxDepth = 0;
int Ans = INT_MAX;

void DFS(int Depth, int StartIndex)
{
    if (Depth == M)
    {
        int Time = BFS(Temp);
        if (Time < Ans)
            Ans = Time;

        return;
    }


    for (int i = StartIndex; i < BPoss.size(); ++i)
    {
        Temp.push_back(BPoss[i]);
        DFS(Depth + 1, i + 1);
        Temp.pop_back();
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 2500
    // 10
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Matrix[i][j];
            if (Matrix[i][j] == 2)
                BPoss.push_back({ j,i });
        }
    }

    

    DFS(0, 0);

    if (Ans == INT_MAX)
        cout << -1;
    else
        cout << Ans;


    return 0;
}