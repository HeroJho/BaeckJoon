#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Pos
{
    int X, Y, Z;
    Pos() {};
    Pos(int x, int y, int z) : X(x), Y(y), Z(z) {};

};

// 층    행    열
int g_L, g_R, g_C;
int g_Matrix[30][30][30] = {0};
bool g_Visited[30][30][30] = { false };
Pos g_Start;
Pos g_End;

//           좌 우 앞 뒤 위 아래
int g_DirX[] = {-1, 1, 0, 0, 0, 0};
int g_DirY[] = {0, 0, -1, 1, 0, 0};
int g_DirZ[] = {0, 0, 0, 0, -1, 1};

int g_Count = 0;

void Reset()
{
    for (int l = 0; l < 30; ++l)
    {
        for (int r = 0; r < 30; ++r)
        {
            for (int c = 0; c < 30; ++c)
            {
                g_Matrix[l][r][c] = 0;
                g_Visited[l][r][c] = false;
            }
        }
    }
}

bool IsIn(int X, int Y, int Z)
{
    return X >= 0 && X < g_C && Y >= 0 && Y < g_R && Z >= 0 && Z < g_L;
}


bool BFS()
{
    queue<Pos> Qs;
    Qs.push(g_Start);
    g_Visited[g_Start.Z][g_Start.Y][g_Start.X] = true;

    while (!Qs.empty())
    {
        int Size = Qs.size();
        ++g_Count;

        for (int t = 0; t < Size; ++t)
        {
            Pos Cur = Qs.front();
            Qs.pop();

            for (int i = 0; i < 6; ++i)
            {
                int nX = g_DirX[i] + Cur.X;
                int nY = g_DirY[i] + Cur.Y;
                int nZ = g_DirZ[i] + Cur.Z;

                if (!IsIn(nX, nY, nZ))
                    continue;

                if (g_Matrix[nZ][nY][nX] == 1)
                    continue;

                if (g_Visited[nZ][nY][nX])
                    continue;
                g_Visited[nZ][nY][nX] = true;

                if (nX == g_End.X && nY == g_End.Y && nZ == g_End.Z)
                {
                    return true;
                }

                Qs.push({ nX, nY, nZ });

            }
        }

        

    }

    return false;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    while (true)
    {
        cin >> g_L >> g_R >> g_C;
        if (g_L == 0 && g_R == 0 && g_C == 0)
        {
            break;
        }

        Reset();
        g_Count = 0;

        for (int l = 0; l < g_L; ++l)
        {

            for (int r = 0; r < g_R; ++r)
            {
                string sS;
                cin >> sS;
                if (sS == "")
                    break;

                for (int c = 0; c < g_C; ++c)
                {
                    if (sS[c] == 'S')
                    {
                        g_Start.X = c;
                        g_Start.Y = r;
                        g_Start.Z = l;
                        g_Matrix[l][r][c] = 0;
                    }
                    else if (sS[c] == 'E')
                    {
                        g_End.X = c;
                        g_End.Y = r;
                        g_End.Z = l;
                        g_Matrix[l][r][c] = 0;
                    }
                    else if (sS[c] == '.')
                    {
                        g_Matrix[l][r][c] = 0;
                    }
                    else if (sS[c] == '#')
                    {
                        g_Matrix[l][r][c] = 1;
                    }

                }


            }

        }

        bool bCan = BFS();

        if (bCan)
        {
            cout << "Escaped in " << g_Count << " minute(s)." << endl;
        }
        else
        {
            cout << "Trapped!" << endl;
        }

    }




    return 0;
}
