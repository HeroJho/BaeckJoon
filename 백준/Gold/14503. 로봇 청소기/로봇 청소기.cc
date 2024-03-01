#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct RobotInfo
{
    pair<int, int> Pos;
    int Dir;
};

int N, M;
int Matrix[51][51] = { 0 };
//            북  동 남  서
int DirX[] = { 0, 1, 0, -1};
int DirY[] = { -1, 0, 1, 0};

RobotInfo Robot;


bool IsIn(int X, int Y)
{
    return X >= 0 && X < M&& Y >= 0 && Y < N;
}

bool CheckGar()
{
    bool bB = false;

    for (int i = 0; i < 4; ++i)
    {
        int nX = Robot.Pos.first + DirX[i];
        int nY = Robot.Pos.second + DirY[i];
        
        if (!IsIn(nX, nY))
            continue;

        if (Matrix[nY][nX] == 0)
        {
            bB = true;
            break;
        }

    }

    return bB;
}


int DoSimul()
{
    int Count = 0;

    while (true)
    {
        // 현재 칸 확인 - 청소
        if (Matrix[Robot.Pos.second][Robot.Pos.first] == 0)
        {
            ++Count;
            Matrix[Robot.Pos.second][Robot.Pos.first] = 9;
        }
            
        // 주변 확인
        if (CheckGar())
        { // 있다면
            // 반 시계 회전
            int nDir = Robot.Dir - 1;
            if (nDir < 0)
                nDir = 3;
            Robot.Dir = nDir;

            // 바라보는 방향 쓰래기라면 이동
            int nX = Robot.Pos.first + DirX[Robot.Dir];
            int nY = Robot.Pos.second + DirY[Robot.Dir];
            
            if (!IsIn(nX, nY))
                continue;
            if (Matrix[nY][nX] == 0)
            {
                Robot.Pos.first = nX;
                Robot.Pos.second = nY;
            }


        }
        else // 없다면
        {
            // 방향의 반대로 이동, 방향 유지
            int nDir = (Robot.Dir + 2) % 4;
            int nX = Robot.Pos.first + DirX[nDir];
            int nY = Robot.Pos.second + DirY[nDir];

            // ***범위 벗어나는 것도 벽?
            if (!IsIn(nX, nY))
                break;
            // 벽이라면 종료
            if (Matrix[nY][nX] == 1)
                break;
            
            // 이동
            Robot.Pos.first = nX;
            Robot.Pos.second = nY;

        }

    }

    return Count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> Robot.Pos.second >> Robot.Pos.first;
    cin >> Robot.Dir;
    for(int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            cin >> Matrix[y][x];
        }
    }


    cout << DoSimul();

    return 0;
}
