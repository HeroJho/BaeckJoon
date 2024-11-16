#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;

int Y, X, R;
int Matrix[301][301] = { 0 };

//           위  오  밑  왼
int DirX[] = { 1, 0, -1, 0 };
int DirY[] = { 0, 1, 0, -1 };


void Rotate(int Depth)
{
    int CurX = Depth;
    int CurY = Depth;

    // 시작 빼고
    int StartVal = Matrix[CurY][CurX];

    // 돌리기
    for (int dir = 0; dir < 4; ++dir)
    {
        int nX = CurX;
        int nY = CurY;

        while (true)
        {
            nX = CurX + DirX[dir];
            nY = CurY + DirY[dir];

            if (nX == Depth && nY == Depth)
            {
                // 시작 넣어주기
                Matrix[CurY][CurX] = StartVal;
                return;
            }

            if (!(nX >= Depth && nX < X - Depth
                && nY >= Depth && nY < Y - Depth))
                break;

            Matrix[CurY][CurX] = Matrix[nY][nX];
            CurX = nX;
            CurY = nY;

        }

    }

}

void Go()
{
    int Depth = min(X, Y) / 2;
    for (int i = 0; i < Depth; ++i)
    {
        Rotate(i);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> Y >> X >> R;
    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            cin >> Matrix[y][x];
        }
    }

    for (int i = 0; i < R; ++i)
    {
        Go();
    }

    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            cout << Matrix[y][x] << ' ';
        }
        cout << '\n';
    }

    return 0;
}