#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Data
{
    pair<int, int> Pos;
    int WallCnt = 0;
    bool bIsWait = false;
    Data() {};
    Data(pair<int, int> pos, int wallCnt, bool IsWait) 
        : Pos(pos), WallCnt(wallCnt), bIsWait(false) {};
};

int N, M, K;
int Matrix[1000][1000] = { 0 };
// 낮, 밤
// 해당 좌표의 최소 벽 개수
int DP[1000][1000][2] = { INT_MAX };
int DirX[] = { 0 ,0, -1, 1 };
int DirY[] = { -1, 1, 0 ,0 };

// 낮에만 벽을 부순다. = 낮에만 1로 갈 수 있다
// 밤이고, 가는 방향이 벽이라면 = 기다린다
// 

void Reset()
{
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
        {
            DP[i][j][0] = INT_MAX;
            DP[i][j][1] = INT_MAX;
        }
            
}

bool IsIn(int X, int Y)
{
    return X >= 0 && X < M&& Y >= 0 && Y < N;
}

int BFS()
{
    queue<Data> Qs;
    Qs.push({ {0, 0}, 0, false });
    // DP[0][0][1] = 0;

    int Count = 0;
    bool Sun = false;
    while (!Qs.empty())
    {
        ++Count;

        Sun = !Sun;
        int Size = Qs.size();
        for (int s = 0; s < Size; ++s)
        {

            Data Cur = Qs.front();
            Qs.pop();

            // K 넘음
            if (Cur.WallCnt > K)
                continue;

            // 제자리 기다렸다면 DP 검사 넘긴다
            if (!Cur.bIsWait)
            {
                // 더 느리게 도착했고, 밤낮도 같을 때 벽도 많다면 넘긴다
                if (DP[Cur.Pos.second][Cur.Pos.first][Sun] <= Cur.WallCnt)
                    continue;
                DP[Cur.Pos.second][Cur.Pos.first][Sun] = Cur.WallCnt;
            }
            // 도착
            if (Cur.Pos.first == M - 1 && Cur.Pos.second == N - 1)
                return Count;



            for (int i = 0; i < 4; ++i)
            {
                int nX = DirX[i] + Cur.Pos.first;
                int nY = DirY[i] + Cur.Pos.second;
                int nWallCnt = Cur.WallCnt;

                if (!IsIn(nX, nY))
                    continue;


                // 다음이 벽이냐
                if (Matrix[nY][nX] == 1)
                {
                    // 밤
                    if (!Sun)
                    {
                        // 제자리
                        Qs.push({ Cur.Pos, nWallCnt, true });
                    }
                    else
                    {   // 벽 뚫고 ㄱㄱ
                        Qs.push({ {nX,nY}, nWallCnt + 1, false });

                    }
                }
                else
                { //간다
                    Qs.push({ {nX,nY}, nWallCnt, false });
                }
                

            }



        }

    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int y = 0; y < N; ++y)
    {
        string sS; cin >> sS;
        for (int x = 0; x < M; ++x)
        {
            Matrix[y][x] = sS[x] - '0';
        }
    }

    Reset();

    cout << BFS();


    return 0;
}
