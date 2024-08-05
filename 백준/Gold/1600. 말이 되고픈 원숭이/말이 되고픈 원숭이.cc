#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int K;
int X, Y;
int Matrix[201][201] = { 0 };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };
int nDirX[] = { -2, -1, 1, 2,       -2, -1, 1, 2 };
int nDirY[] = { 1, 2, 2, 1,         -1, -2, -2, -1 };

bool DP[31][201][201] = { 0 };


void Reset()
{
    for (int i = 0; i < 31; ++i)
    {
        for (int y = 0; y < 201; ++y)
        {
            for (int x = 0; x < 201; ++x)
            {
                DP[i][y][x] = INT_MAX;
            }
        }
    }
}

bool IsIn(int InX, int InY)
{
    return InX >= 0 && InX < X && InY >= 0 && InY < Y;
}

void BFS()
{
    queue<pair<pair<int ,int>, pair<int, int>>> Qs;
    Qs.push({ {0, K}, {0, 0} });
    DP[K][0][0] = true;


    while (!Qs.empty())
    {

        pair<pair<int, int>, pair<int, int>> Cur = Qs.front();
        Qs.pop();

        pair<int, int> Pos = Cur.second;
        int Cnt = Cur.first.first;
        int InK = Cur.first.second;


        if (Pos.first == X - 1 && Pos.second == Y - 1)
        {
            cout << Cnt;
            return;
        }

        if (InK > 0)
        {
            for (int i = 0; i < 8; ++i)
            {
                int nX = nDirX[i] + Pos.first;
                int nY = nDirY[i] + Pos.second;

                if (!IsIn(nX, nY))
                    continue;

                if (Matrix[nY][nX] == 1)
                    continue;

                if (DP[InK - 1][nY][nX])
                    continue;
                DP[InK - 1][nY][nX] = true;
                    
                Qs.push({ {Cnt + 1,InK - 1},{nX,nY} });
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int nX = DirX[i] + Pos.first;
            int nY = DirY[i] + Pos.second;

            if (!IsIn(nX, nY))
                continue;

            if (Matrix[nY][nX] == 1)
                continue;

            if (DP[InK][nY][nX])
                continue;
            DP[InK][nY][nX] = true;

            Qs.push({ {Cnt + 1,InK},{nX,nY} });
        }

    }

    cout << -1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> K;
    cin >> X >> Y;
    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            cin >> Matrix[y][x];
        }
    }

     
    BFS();

    return 0;
}