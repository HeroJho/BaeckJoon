#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int N;
int Matrix[11][11] = { 0 };
bool Check[11][11] = { false };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { 1, -1, 0, 0 };

int Ans = INT_MAX;

bool IsIn(int X, int Y)
{
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

void DFS(int Depth, int Score)
{
    if (Depth == 3)
    {
        if (Ans > Score)
            Ans = Score;

        return;
    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            bool bCan = true;
            pair<int, int> PosTemp[4];
            for (int z = 0; z < 4; ++z)
            {
                int nX = DirX[z] + j;
                int nY = DirY[z] + i;

                if (!IsIn(nX, nY) || Check[nY][nX] == true)
                {
                    bCan = false;
                    break;
                }

                PosTemp[z] = { nX,nY };
            }

            if (!bCan)
                continue;

            int Sum = 0;

            for (int z = 0; z < 4; ++z)
            {
                Sum += Matrix[PosTemp[z].second][PosTemp[z].first];
                Check[PosTemp[z].second][PosTemp[z].first] = true;
            }
            Sum += Matrix[i][j];
            Check[i][j] = true;

            DFS(Depth + 1, Score + Sum);

            for (int z = 0; z < 4; ++z)
            {
                Check[PosTemp[z].second][PosTemp[z].first] = false;
            }
            Check[i][j] = false;

        }
    }


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Matrix[i][j];
        }
    }

    DFS(0, 0);

    cout << Ans;


    return 0;
}