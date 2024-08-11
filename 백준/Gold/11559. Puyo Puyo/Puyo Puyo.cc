#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;


char Matrix[12][6];
bool Visited[12][6] = { false };
bool BombVisited[12][6] = { false };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

void Debug()
{
    cout << endl;

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cout << Matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
}

void ResetVisited()
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            Visited[i][j] = false;
        }
    }
}

void BombResetVisited()
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            BombVisited[i][j] = false;
        }
    }
}

bool IsIn(int X, int Y)
{
    return X >= 0 && X < 6 && Y >= 0 && Y < 12;
}

bool CheckBFS(pair<int ,int> StartPos)
{
    if (Matrix[StartPos.second][StartPos.first] == '.')
        return false;

    int Cnt = 1;

    char Mark = Matrix[StartPos.second][StartPos.first];

    queue<pair<int, int>> Qs;
    Qs.push(StartPos);
    Visited[StartPos.second][StartPos.first] = true;


    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.front();
        Qs.pop();


        for (int i = 0; i < 4; ++i) 
        {
            int nX = DirX[i] + Cur.first;
            int nY = DirY[i] + Cur.second;

            if (!IsIn(nX, nY))
                continue;

            if (Matrix[nY][nX] != Mark)
                continue;

            if (Visited[nY][nX])
                continue;
            Visited[nY][nX] = true;
            ++Cnt;

            Qs.push({nX, nY});

        }

    }

    if (Cnt >= 4)
        return true;
    else
        return false;
}



void DrawBFS(pair<int, int> StartPos)
{
    char Mark = Matrix[StartPos.second][StartPos.first];

    queue<pair<int, int>> Qs;
    Qs.push(StartPos);
    BombVisited[StartPos.second][StartPos.first] = true;
    Matrix[StartPos.second][StartPos.first] = '.';

    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.front();
        Qs.pop();


        for (int i = 0; i < 4; ++i)
        {
            int nX = DirX[i] + Cur.first;
            int nY = DirY[i] + Cur.second;

            if (!IsIn(nX, nY))
                continue;

            if (Matrix[nY][nX] != Mark)
                continue;

            if (BombVisited[nY][nX])
                continue;
            BombVisited[nY][nX] = true;

            Matrix[nY][nX] = '.';

            Qs.push({ nX, nY });

        }

    }

}




void Down()
{

    for (int x = 0; x < 6; ++x)
    {
        for (int y = 0; y < 12; ++y)
        {
            if (Matrix[y][x] != '.')
            {
                while (true)
                {
                    bool bGo = false;
                    bool bT = false;
                    for (int z = 11; z >= 0; --z)
                    {
                        if (Matrix[z][x] == '.')
                            bT = true;
                        else if (Matrix[z][x] != '.' && bT)
                        {
                            bGo = true;
                            break;
                        }

                    }

                    if (!bGo)
                        break;

                    for (int z = 11; z >= 1; --z)
                    {
                        if (Matrix[z][x] == '.')
                        {
                            Matrix[z][x] = Matrix[z - 1][x];
                            Matrix[z - 1][x] = '.';
                        }

                    }

                    Matrix[0][x] = '.';
                }
            }


        }
    }

  
}

bool Bomb()
{
    ResetVisited();

    bool Can = false;
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (Visited[i][j])
                continue;

            if (CheckBFS({ j, i }))
            {
                BombResetVisited();
                DrawBFS({ j, i });
                Can = true;
            }

        }
    }
    
    return Can;
}

void Go()
{

    int Ans = 0;
    while(Bomb())
    {
        // Debug();

        ++Ans;
        Down();

        // Debug();
    }

    cout << Ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> Matrix[i][j];
        }
    }


    Go();



    return 0;
}